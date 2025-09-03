#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

size_t  ft_strlen(const char *str);
char    *ft_strcpy(char *dest, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);

#define ASSERT(a) { \
  if (a) { printf("ok\n"); } else { printf("failed\n");} \
}

int assert_int(int a, int b) {
  return a == b;
}

int assert_str(const char *a, const char *b) {
  return strcmp(a, b) == 0;
}

int assert_cmp(int a, int b) {
  return a == 0 && b == 0;
}


void strlen_tests() {

  printf("--------[STRLEN_TESTS]--------\n");
  const char *tests[] = {
        "",
        "a",
        "hello",
        "oui je test",
        "longue chaine avec beaucoup de caracteres...",
        NULL
    };

    for (int i = 0; tests[i] != NULL; i++) {
        size_t mine = ft_strlen(tests[i]);
        size_t real = strlen(tests[i]);
        printf("%s: ", tests[i]);
        ASSERT(assert_int(real, mine));
    }
    printf("\n");
}

void strcpy_tests() {
  printf("--------[STRCPY_TESTS]--------\n");
  const char *tests[] = {
        "",
        "a",
        "hello",
        "oui je test",
        "longue chaine avec beaucoup de caracteres...",
        NULL
    };
    for (int i = 0; tests[i] != NULL; i++) {
        char *dest = malloc(sizeof(char) * strlen(tests[i]));
        ft_strcpy(dest, tests[i]);
        printf("%s: ", tests[i]);
        ASSERT(assert_str(dest, tests[i]));
        free(dest);
    }
    printf("\n");
}

void strcmp_tests() {
  printf("--------[STRCMP_TESTS]--------\n");
  const char *tests[] = {
        "",
        "a",
        "hello",
        "oui je test",
        "longue chaine avec beaucoup de caracteres...",
        NULL
    };

    const char *tests2[] = {
        "",
        "a",
        "heilo",
        "oui je test",
        "longue/chaine avec beaucoup de caracteres...",
        NULL
    };
    for (int i = 0; tests[i] != NULL; i++) {
        int mine = ft_strcmp(tests[i], tests2[i]);
        int real = strcmp(tests[i], tests2[i]);
        printf("%s: ", tests[i]);
        ASSERT(assert_int(mine, real));
    }
    printf("\n");
}

#include <fcntl.h>

void test_write() {
  int fd = open("/dev/null", O_WRONLY);
  printf("--------[WRITE_TESTS]--------\n");
  const char *tests[] = {
        "",
        "a",
        "hello",
        "oui je test",
        "longue chaine avec beaucoup de caracteres...",
        NULL
    };
    for (int i = 0; tests[i] != NULL; i++) {
        int mine = ft_write(fd, tests[i], ft_strlen(tests[i]));
        int real= write(fd, tests[i], ft_strlen(tests[i]));
        printf("%s: ", tests[i]);
        ASSERT(assert_int(mine, real));
    }
    close(fd);
    fd = open("/dev/null", O_RDONLY);
    int mine = ft_write(fd, "ca dois pas marcher", 19);
    perror("mine errno");
    int real = write(fd, "ca dois pas marcher", 19);
    perror("real errno");
    printf("write_in_rdonly_file: ");
    ASSERT(assert_int(mine, real));
    close(fd);
    printf("\n");
}


int main(void) {
    strlen_tests();
    strcpy_tests();
    strcmp_tests();
    test_write();
    return 0;
}
