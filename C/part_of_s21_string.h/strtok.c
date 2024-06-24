#include <stdio.h>
#include "strchr.h"

char *s21_strtok(char *str, const char *delim) {
    static char new_str[10000];
    static char part[10000];
    s21_memmove(part, part + s21_strlen(part), s21_strlen(new_str));
    if(str != S21_NULL) {
        s21_strcpy(new_str, s21_strstr(str, delim) + s21_strlen(delim));
        s21_memmove(strstr(str, delim), str + s21_strlen(str), strlen(str));
        strcpy(part, str);
    }
    else if (str == S21_NULL && strstr(new_str, delim) != S21_NULL) {
            s21_strncpy(part, new_str, s21_strstr(new_str, delim) - new_str);
            s21_memmove(new_str, s21_strstr(new_str, delim) + s21_strlen(delim), s21_strlen(new_str));
        }
    else {
        s21_strcpy(part, new_str);
        s21_memmove(new_str, new_str + s21_strlen(new_str), s21_strlen(new_str));
    }
    return s21_strchr(new_str, '\0') == new_str ? S21_NULL : part;
}
