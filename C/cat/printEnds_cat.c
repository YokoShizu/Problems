#include <stdio.h>
#include <string.h>

#include "nonPrint_cat.h"

void printEnds_cat(char *pars_res, int *current, char previous) {
  if (*current == '\n' && strstr(pars_res, "b") == NULL)
    printf("$");
  else if (strstr(pars_res, "b") != NULL) {
    if (*current == '\n' && (previous == '\n' || previous == '\0'))
      printf("%6s\t%s", "\0", "$");
    else if (*current == '\n' && previous != '\n')
      printf("$");
  }
  if (strstr(pars_res, "e") != NULL) {
    nonPrint_cat(current);
  }
}
