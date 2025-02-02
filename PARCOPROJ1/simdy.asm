section .text
bits 64
default rel

global SIMDY

SIMDY:
    ; Stack setup
    push rbp            
    mov rbp, rsp
    
    sub rsp, 32		    ; Shadow space allocation

    push rbx            
    push rsi
    push rdi
    
    vxorps ymm0, ymm0, ymm0    ; Dot product accumulator 
    
    mov r10d, ecx        ; Load length of vectors

    mov ebx, r10d        ; For boundary handling if vector length is not multiple of 8
    shr r10d, 3          ; r10d / 8, to process 8 elements since 256/32 = 8
    
    test r10d, r10d
    jz odd

sum:
    vmovdqu ymm1, [rdx]  
    vmovdqu ymm2, [r8]     
    
    ; Dot product computation
    vpmulld ymm1, ymm1, ymm2   
    vpaddd ymm0, ymm0, ymm1    
    
    add rdx, 32          ; Proceed to next set of 8 elements, 4 bytes/element * 8 = 32
    add r8, 32           ; Proceed to next set of 8 elements, 4 bytes/element * 8 = 32
    
    dec r10d              ; Decrement loop counter
    jnz sum

odd:
    test ebx, 7          ; Compute n % 8 for boundary handling
    jz exit              ; If no remainder, finish program

remainder:
    test ebx, 4          ; Check if >= 4 elements
    jz check

    vmovdqu xmm1, [rdx]  
    vmovdqu xmm2, [r8]   
    vpmulld xmm1, xmm1, xmm2
    vpaddd ymm0, ymm0, ymm1

    add rdx, 16          ; Proceed to next set of 4 elements, 4 bytes/element * 4 = 16
    add r8, 16           ; Proceed to next set of 4 elements, 4 bytes/element * 4 = 16

check:
    test ebx, 3          ; Check if >= 2 elements
    jz single

    movq xmm1, [rdx]     
    movq xmm2, [r8]      
    vpmulld xmm1, xmm1, xmm2
    vpaddd ymm0, ymm0, ymm1

    add rdx, 8           ; Proceed to next set of 2 elements, 4 bytes/element * 2 = 8
    add r8, 8            ; Proceed to next set of 2 elements, 4 bytes/element * 2 = 8

single:
    test ebx, 1          ; Check if only 1 element left
    jz exit

    mov r10d, [rdx]       
    imul r10d, [r8]       
    vmovd xmm1, r10d
    vpaddd ymm0, ymm0, ymm1

exit:
    vextracti128 xmm1, ymm0, 1  
    vpaddd xmm0, xmm0, xmm1     
    vphaddd xmm0, xmm0, xmm0    
    vphaddd xmm0, xmm0, xmm0
    vmovd r10d, xmm0
    mov [r9], r10d               

    pop rdi
    pop rsi
    pop rbx

    add rsp, 32         ; Shadow space deallocation
    mov rsp, rbp
    pop rbp             

    ret