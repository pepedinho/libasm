bits 64
global ft_atoi_base

extern ft_strlen

section .text:
  ft_atoi_base:
    push  rbx
    xor   rbx, rbx
    mov   cl, 0    ; neg = 0

    test  rdi, rdi ; check str == NULL
    jz    .error
    test  rsi, rsi ; check base == NULL
    jz    .error
    
  .loop_on_sign:
    mov   al, [rdi] ; charger le caractere dans al
    test  al, al    ; *str == \0 ?
    jz    .end      ;  si oui, fin

    cmp   al, '-'
    jne   .check_plus ; on verifie si on est sur un '+'
    mov   cl, 1       ; si == '-' neg = 1
    inc   rdi
    jmp   .loop_on_sign ; if != '+' '-' on sort de la boucle


  .check_plus:
    cmp   al, '+'
    jne   .loop   ; si != '+' break
    inc   rdi
    jmp   .loop_on_sign


  .loop:
    mov   al, [rdi]
    test  al, al
    jz    .end
  
    push  rdi       ; on stock rdi dans la stack
    
    mov   rdi, rsi  ; on stock rsi (base) dans rdi pour le passer a ft_strlen
    call  ft_strlen ; rax = strlen(base)
    
    pop   rdi       ; on restore rdi
    imul  ebx, eax  ; res *= ft_strlen(base)
    
    cmp   al, '0'
    jl    .error    ; si < 0 il ne peux appartenir a aucune autre base donc error (jl == jump if less than 0)
    cmp   al, '9'
    jg    .alpha    ; si > 0 il peux appartenir a alpha ou caps_alpha donc on check (jg = jump if greater than 0)
    jmp   .num      ; si dans la range alor on traite en tant que num

  .num:
    movzx edx, al
    sub   edx, '0'  ; str[i] - '0'
    add   ebx, edx  ; res += res[i] - '0'

    jmp   .next
  
  .alpha:
    cmp   al, 'a'
    jl    .error    ; si < 0 il ne peux appartenir a aucune autre base donc error (jl == jump if less than 0)
    cmp   al, 'z'
    jg    .caps_alpha    ; si > 0 il peux appartenir a caps_alpha donc on check (jg = jump if greater than 0)
    
    movzx edx, al
    sub   edx, 'a'  ; str[i] - 'a'
    add   edx, 10 
    add   ebx, edx  ; res += res[i] - 'a' + 10

    jmp   .next

  .caps_alpha:
    cmp   al, 'A'
    jl    .error    ; si < 0 il ne peux appartenir a aucune autre base donc error (jl == jump if less than 0)
    cmp   al, 'Z'
    jg    .error    ; si > 0 il ne peux appartenir a aucune autre base donc error (jg = jump if greater than 0)

    movzx edx, al
    sub   edx, 'A'  ; str[i] - 'A'
    add   edx, 10
    add   ebx, edx  ; res += res[i] - 'a' + 10

    jmp   .next

  .next: 
    inc   rdi
    jmp   .loop

  .end:
    test  cl, cl  ; check si neg == 0
    jz    .no_neg
    neg   rbx     ; res = -res
  .no_neg:
    mov   rax, rbx
    pop   rbx
    ret

  .error:
    mov rax, 0 ; return 0 
    pop rbx
    ret
