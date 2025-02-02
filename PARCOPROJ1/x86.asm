section .text
global x86

x86:
    push rbx                
    push rsi
    push rdi
    
    xor rax, rax            
    mov rsi, rdx            
    mov rdi, r8            
    mov rcx, rcx            

loop1:
    test rcx, rcx           
    jz done

    mov ebx, [rsi]          
    imul ebx, [rdi]       
    add rax, rbx         

    add rsi, 4             
    add rdi, 4            

    dec rcx                
    jmp loop1              

done:
    mov [r9], eax          
    
    pop rdi
    pop rsi
    pop rbx
    ret
