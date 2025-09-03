# libasm

This project aims to reimplement certain standard C library functions in **x86_64 assembly (NASM)**.  
It helps to get familiar with assembly language, register management, Linux system calls (`syscall`), and basic assembly debugging.

---

## Implemented Functions

Currently, the following functions are available:

- **ft_strlen.s**: returns the length of a string (equivalent to `strlen`).
- **ft_strcpy.s**: copies a string into another (equivalent to `strcpy`).
- **ft_strcmp.s**: compares two strings (equivalent to `strcmp`).
- **ft_write.s**: writes data to a file descriptor (equivalent to `write`).

---

## Useful Resources

Here are some useful resources to improve your understanding:

- [Registers (x86_64 register explanations)](https://math.hws.edu/eck/cs220/f22/registers.html)
- [Linux System Call Table (x86_64)](https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/)
- [GDB Guide for Debugging](https://web.cecs.pdx.edu/~apt/cs510comp/gdb.pdf)
- [x86 Instruction Documentation](https://www.felixcloutier.com/x86/)

---

## Notes

- The project follows the **System V AMD64 ABI** convention (standard calling convention on Linux).
- Each function must respect register usage conventions.
- Always preserve non-volatile registers (`rbx`, `rbp`, `r12–r15`).

---
