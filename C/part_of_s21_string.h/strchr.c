#include <stdio.h>

char *s21_strchr(const char *str, int c){
    while(*str && *str != c) ++str;
    return (char*)(*str == c ? str : NULL);
}
