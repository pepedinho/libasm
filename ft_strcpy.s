bits 64
global ft_strcpy


section .text
  ft_strcpy:
    xor rbx, rbx; rbx = 0
    ;rdi = dest, rsi = src
 
  .loop:
    cmp byte [rsi + rbx], 0 ; je check si je suis sur un \0
    je .done ; si je suis dessus je passe a l'etape suivante
    mov al, [rsi + rbx] ; je stock le caracter actuel de src(rsi) dans al
    mov [rdi + rbx], al ; je move dans dest la valeur stocker dans al
    inc rbx ; incremente rbx (index)
    jmp .loop ; je refais un tour

  .done: 
    mov byte [rdi + rbx], 0
    mov rax, rdi
    ret
