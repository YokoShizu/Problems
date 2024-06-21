#include <stdio.h>
#include <string.h>

#include "nonPrint_cat.h"

void printTabs_cat(char *pars_res, int *current) {
  if (*current == '\t') {
    printf("^");
    *current = 'I';
  }
  if (strstr(pars_res, "t") != NULL) {
    nonPrint_cat(current);
  }
}
