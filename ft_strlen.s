bits 64
global ft_strlen

section .text
  ft_strlen:
    push rbx
    xor rbx, rbx
   
  len_loop:
    mov al, byte [rdi + rbx]
    cmp al, 0
    je len_done
    inc rbx
    jmp len_loop


  len_done:
    mov rax, rbx
    pop rbx
    ret
