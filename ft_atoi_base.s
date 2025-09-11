bits 64
global ft_atoi_base

extern ft_strlen

section .text:
  ft_atoi_base:
    push  rbx
    test  rdi, rdi ; check str == NULL
    jz    .error
    test  rsi, rsi ; check base == NULL
    jz    .error

    mov   bl, [rdi] ;lis le premier caractere
    
  .loop_on_sign:
    mov   al, [rdi] ; charger le caractere dans al
    cmp   al, '-'
    je    .next_char ; on passe au caractere suivant
    cmp   al, '+'
    jne    .loop ; is != '+' '-' on sort de la boucle

  .next_char:
    inc [rdi]
    jmp   .loop_on_sign

  .loop:
    test [rdi], [rdi]
    jz

  .error:
    mov rax, 0 ; return 0 
    ret
