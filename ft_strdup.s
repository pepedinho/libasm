bits 64
global ft_strdup

extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

section .text
  ft_strdup:
    test    rdi, rdi
    jz      .null

    push    rdi               ; on garde s et on aligne la stack 
    call    ft_strlen
    inc     rax               ; +1 pour \0
    mov     rdi, rax          ; on deplace la taille de s dans rdi pour malloc
    call    malloc wrt ..plt
    test    rax, rax          ; check si on recois NULL
    jz      .fail

    pop     rsi               ; restaurer s
    mov     rdi, rax          ; dest
    call    ft_strcpy
    ret

  .fail:
      add     rsp, 8            ; on simule un pop (realignement de la stack)
  .null:
      xor     rax, rax
      ret

