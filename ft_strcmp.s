bits 64
global ft_strcmp


section .text
  ft_strcmp:
    ;rdi = dest, rsi = src
 
  .loop:
    movzx eax, byte [rdi]       ; s1[i]
    movzx edx, byte [rsi]       ; s2[i]
    cmp eax, edx                ; check si s1[i] == s2[i]
    jne .err                    ; si je suis dessus je passe a l'etape suivante
    test eax, eax               ; check si s1[i] == 0
    je .done                    ; si != je renvoie err
    inc rdi                     ; s1++
    inc rsi                     ; s2++
    jmp .loop                   ; je refais un tour

  .done: 
    xor rax, rax                ; return 0
    ret

  .err:
    sub eax, edx                ; dest = dest - src
    ret
