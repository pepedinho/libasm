int ft_atoi(char *str) {
    int res = 0, i = 0, neg = 0;

    if (!str)
        return 0;
    if (str[0] == '-') {
        neg = 1;
        i++;
    }
    while (str[i]) {
        res *= 10;
        res += str[i++] - '0';
    }
    return neg ? -res : res;
}

#include <stdio.h>
#include <string.h>
int ft_atoi_base(char *str, char *base) {
    int res = 0, i = 0, neg = 0;

    if (!str)
        return 0;
    if (str[0] == '-') {
        neg = 1;
        i++;
    }
    while (str[i]) {
        res *= (int)strlen(base);
        // res += base[(str[i++] - strlen(base)) % strlen(base)];
        if (str[i] >= '0' && str[i] <= '9')
            res += str[i] - '0';
        else if (str[i] >= 'a' && str[i] <= 'f')
            res += str[i] - 'a' + 10;
        else if (str[i] >= 'A' && str[i] <= 'F')
            res += str[i] - 'A' + 10;
        i++;
    }
    return neg ? -res : res;
}

int main() {
    printf("atoi for 42: %d\n", ft_atoi("42"));
    printf("atoi for 0: %d\n", ft_atoi("0"));
    printf("atoi for -42: %d\n", ft_atoi("-42"));
    printf("atoi_base for 2A: %d\n", ft_atoi_base("2A", "0123456789ABCDEF"));
    return 1;
}