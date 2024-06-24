#include <stdio.h>
#include <string.h>

char *s21_strrchr(const char *str, int c){
    size_t i = strlen(str);
    while(i > 0) {
        if(*(str + --i) == c) break;
    }
    return (char*)(*(str + i) == c ? str + i : NULL);
}
