section .text
bits 64
default rel

global SIMDX

SIMDX:
    push rbp            ; saves the base pointer
    mov rbp, rsp
    
    sub rsp, 32		    ; allocates for the shadow space

    push rbx            ; just these non volatile registers
    push rsi
    push rdi
    
    xorps xmm0, xmm0    ; this basically acts as the accumulator for the dot product value, and it just resets itself everytime it is ran.
    
    mov r10d, ecx        ; loads the size of the array into r10d

    mov ebx, r10d       ; just saves the value of n into ebx
    shr r10d, 2          ; this just divides it by 4 because of how SIMD works with 128 bits, where it needs to process 4 elements at a time.
    
    test r10d, r10d      ; this just checks if atleast 4 elements are present
    jz odd

sum:
    movdqu xmm1, [rdx]    ; rdx is the second argument in the function definition, where it loads v1 into xmm1
    movdqu xmm2, [r8]    ; r8 is the third argument in the function definition, where it loads v2 into xmm2
    
    pmulld xmm1, xmm2   ; just multipliess the corresponding elements
    paddd xmm0, xmm1    ; addition to the accumulator
    
    add rdx, 16          ; moves the v1 rdx pointer to the next set of elements
    add r8, 16           ; advances the same just with v2
    
    dec r10d             ; decrements the loop counter
    jnz sum              ; jumps to sum if the loop counter is not zero

odd:
    test ebx, 3           ; will just check if there anymore elements left in the array
    jz exit

remainder:
    test ebx, 2		      ; checks if there are more than 2 elements left
    jz check

    movq xmm1, [rdx]      ; loads 2 elements of v1 into eax
    movq xmm2, [r8]       ; loads 2 elements of v2 into ebx
    pmulld xmm1, xmm2
    paddd xmm0, xmm1

    add rdx, 8            ; moves the v1 rdx pointer to the next set of elements
    add r8, 8             ; same as above just with v2

check:
    test ebx, 1           ; checks if a single element is left in the array
    jz exit

    mov r10d, [rdx]      ; loads the value of v1 into eax
    imul r10d, [r8]      ; multiplies it with elements from v2
    movd xmm1, r10d
    paddd xmm0, xmm1

exit:
    phaddd xmm0, xmm0   ; horizontal addition of xmm0
    phaddd xmm0, xmm0
    movd r10d, xmm0     ; moves the value of the dot product into r10d
    mov [r9], r10d       ; stores the value of the dot product into the address pointed by r9

    pop rdi             ; restores the pushed registers
    pop rsi
    pop rbx

    add rsp, 32         ; restores the shadow space
    mov rsp, rbp        ; restores the stack pointer
    pop rbp             ; restores the base pointer
    ret