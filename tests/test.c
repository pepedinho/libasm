#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

size_t ft_strlen(const char *str);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);

#define ASSERT(a)                                                              \
  {                                                                            \
    if (a) {                                                                   \
      printf(GREEN "✔ ok" RESET "\n");                                         \
    } else {                                                                   \
      printf(RED "✘ failed" RESET "\n");                                       \
    }                                                                          \
  }

int assert_int(int a, int b) { return a == b; }
int assert_str(const char *a, const char *b) { return strcmp(a, b) == 0; }
int assert_cmp(int a, int b) { return a == 0 && b == 0; }

void strlen_tests() {

  printf("--------[STRLEN_TESTS]--------\n");
  const char *tests[] = {"",
                         "a",
                         "hello",
                         "oui je test",
                         "longue chaine avec beaucoup de caracteres...",
                         NULL};

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
  const char *tests[] = {"",
                         "a",
                         "hello",
                         "oui je test",
                         "longue chaine avec beaucoup de caracteres...",
                         NULL};
  for (int i = 0; tests[i] != NULL; i++) {
    char *dest = malloc(sizeof(char) * strlen(tests[i]) + 1);
    ft_strcpy(dest, tests[i]);
    printf("%s: ", tests[i]);
    ASSERT(assert_str(dest, tests[i]));
    free(dest);
  }

  printf("too_big_malloc: ");
  char *dest = malloc(sizeof(char) * strlen(tests[4]) + 10);
  ft_strcpy(dest, tests[4]);
  ASSERT(assert_str(dest, tests[4]));
  free(dest);
  printf("\n");
}

void strcmp_tests() {
  printf("--------[STRCMP_TESTS]--------\n");
  const char *tests[] = {
      "",      "a",           "hello",
      "jello", "oui je test", "longue chaine avec beaucoup de caracteres...",
      NULL};

  const char *tests2[] = {
      "",      "a",           "heilo",
      "hello", "oui je tesx", "longue/chaine avec beaucoup de caracteres...",
      NULL};
  for (int i = 0; tests[i] != NULL; i++) {
    int mine = ft_strcmp(tests[i], tests2[i]);
    int real = strcmp(tests[i], tests2[i]);
    printf("%s: m %d | r %d", tests[i], mine, real);
    ASSERT(assert_int(mine, real));
  }
  printf("\n");
}

#include <fcntl.h>

void test_write() {
  int fd = open("/dev/null", O_WRONLY);
  printf("--------[WRITE_TESTS]--------\n");
  const char *tests[] = {"",
                         "a",
                         "hello",
                         "oui je test",
                         "longue chaine avec beaucoup de caracteres...",
                         NULL};
  for (int i = 0; tests[i] != NULL; i++) {
    int mine = ft_write(fd, tests[i], ft_strlen(tests[i]));
    int real = write(fd, tests[i], ft_strlen(tests[i]));
    printf("%s: ", tests[i]);
    ASSERT(assert_int(mine, real));
  }
  close(fd);
  fd = open("/dev/null", O_RDONLY);
  printf("write_in_rdonly_file: ");
  int mine = ft_write(fd, "ca dois pas marcher", 19);
  perror("  |__mine errno");
  int real = write(fd, "ca dois pas marcher", 19);
  perror("  |__real errno");
  ASSERT(assert_int(mine, real));
  close(fd);
  printf("\n");
}

void test_read() {
  printf("--------[READ_TESTS]--------\n");

  int mine_fd = open("./tests/read_test_mine.txt", O_RDONLY);
  int real_fd = open("./tests/read_test_real.txt", O_RDONLY);
  char mine_buf[20] = {0};
  char real_buf[20] = {0};

  int mine = ft_read(mine_fd, mine_buf, 15);
  int real = ft_read(real_fd, real_buf, 15);

  printf("read_buf_result: ");
  ASSERT(assert_str(mine_buf, real_buf));

  printf("read_return_value: ");
  ASSERT(assert_int(mine, real));

  (close(mine_fd), close(real_fd));
  mine_fd = open("./tests/read_test_mine.txt", O_WRONLY);
  real_fd = open("./tests/read_test_real.txt", O_WRONLY);
  printf("read_in_wronly_file: ");
  mine = ft_read(mine_fd, mine_buf, 15);
  perror("\tmine errno");
  real = ft_read(real_fd, real_buf, 15);
  perror("\treal errno");
  ASSERT(assert_int(mine, real));
  (close(mine_fd), close(real_fd));

  printf("read_in_invalid fd: ");
  mine = ft_read(mine_fd, mine_buf, 15);
  perror("  |__mine errno");
  real = ft_read(real_fd, real_buf, 15);
  perror("  |__real errno");
  ASSERT(assert_int(mine, real));
  (close(mine_fd), close(real_fd));
  printf("\n");
}

void strdup_tests() {
  printf("--------[STRDUP_TESTS]--------\n");
  const char *tests[] = {"oui",
                         "a",
                         "hello",
                         "oui je test",
                         "longue chaine avec beaucoup de caracteres...",
                         NULL};

  for (int i = 0; tests[i] != NULL; i++) {
    char *mine = ft_strdup(tests[i]);
    char *real = strdup(tests[i]);
    printf("%s: ", tests[i]);
    ASSERT(assert_str(mine, real));
    (free(real), free(mine));
  }
  printf("\n");
}

int main(void) {
  strlen_tests();
  strcpy_tests();
  strcmp_tests();
  test_write();
  test_read();
  strdup_tests();
  return 0;
}
