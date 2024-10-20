#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int c[26] = { 0 }, max = 0, i;
    char ch;
    while ((ch = getchar()) != '\n') {
        c[ch - 'a']++;
    }
    for (i = 1; i < 26; i++) {
        if (c[i] > c[max]) {
            max = i;
        }
    }
    printf("%c\n%d", max + 'a', c[max]);
}