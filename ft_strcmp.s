bits 64
global ft_strcmp


section .text
  ft_strcmp:
    push rbx
    xor rbx, rbx; rbx = 0
    ;rdi = dest, rsi = src
 
  .loop:
    cmp byte [rsi + rbx], 0 ; je check si je suis sur un \0
    je .done ; si je suis dessus je passe a l'etape suivante
    mov al, [rsi + rbx] ; je stock le caracter actuel de src(rsi) dans al
    cmp [rdi + rbx], al ; je compare les deux caracters actuel
    jne .err ; si != je renvoie err
    inc rbx ; incremente rbx (index)
    jmp .loop ; je refais un tour

  .done: 
    pop rbx
    mov rax, 0
    ret

  .err:
    mov rax, [rdi + rbx]
    sub rax, [rsi + rbx] ; dest = dest - src
    pop rbx
    ret
