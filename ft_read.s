bits 64
global ft_read

extern __errno_location

section .text
  ft_read:
    mov rax, 0
    syscall
    cmp rax, 0
    jge .done ; >=
  
  .err:
    mov rdi, rax ; on stock la valeur de rax dans rdi
    neg rdi  ; rdi = -rax
    call __errno_location wrt ..plt; __errno_location renvoie l'adrress de errno dans rax
    mov dword [rax], edi ; on assigne la -valeur retourner par sys_write a errno
    mov rax, -1
  
  .done:
    ret
