bits 64
global ft_strcpy


section .text
  ft_strcpy:
    xor rbx, rbx; rbx = 0
  
  .loop:
    cmp byte [rsi + rbx], 0; je check si je suis sur un \0
    je .done; si je suis dessus je passe a l'etape suivante
    ; ajoute une variable pour stocker [rsi + rbx]
    mov [rdi + rbx], [rsi + rbx] 
    inc rbx
    jmp .loop

  .done: 
    mov rax, rdi
