#include <stdio.h>
#include <stdlib.h>

void nonPrint_cat(int *current) {
  if ((*current >= 11 && *current <= 31) || (*current >= 0 && *current < 9)) {
    printf("^");
    *current += 64;
  } else if (*current == 127) {
    printf("^");
    *current -= 64;
  } else if (*current >= 128 && *current < 160) {
    printf("M-^");
    *current -= 64;
  } else if (*current >= 160 && *current < 255) {
    *current -= 128;
    printf("M-");
    *current = '\0';
  } else if (*current == 255) {
    printf("M-^?");
    *current = '\0';
  }
}
