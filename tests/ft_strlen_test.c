#include <stdio.h>
#include <string.h>
#include <stddef.h>

size_t  ft_strlen(const char *str);


int main(void) {
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
        printf("Test %d: \"%s\"\n", i, tests[i]);
        printf("  ft_strlen = %zu\n", mine);
        printf("  strlen    = %zu\n", real);
        printf("  -> %s\n\n", (mine == real ? "OK" : "FAIL"));
    }

    return 0;
}
