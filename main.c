#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void str2hex(char *str, uint8_t *dest, int n) {
    int i;
    uint8_t h1, h2, s1, s2;
    for (i = 0; i < n; i++) {
        h1 = str[2 * i];
        h2 = str[2 * i + 1];

        s1 = toupper(h1) - 0x30;
        if (s1 > 9)
            s1 -= 7;

        s2 = toupper(h2) - 0x30;
        if (s2 > 9)
            s2 -= 7;

        dest[i] = s1 * 16 + s2;
    }
}

char xor_loop(uint8_t *hexes, int n) {
    int i;
    uint8_t r = hexes[0];
    for (i = 1; i < n; ++i) {
        r ^= hexes[i];
    }
    return r;
}

int main(int argc, char **argv)
{
    char *s = argv[1];
    int n = strlen(s) / 2; // 获取十六进制数字个数
    uint8_t *hexes = (uint8_t*)malloc(n);

    str2hex(s, hexes, n);  // 字符串转十六进制数字 "ba" -> 0xba
    uint8_t r = xor_loop(hexes, n);  // 逐位异或
    free(hexes);
    printf("%x\n", r);

    return 0;
}