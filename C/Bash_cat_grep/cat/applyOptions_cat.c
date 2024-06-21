#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nonPrint_cat.h"
#include "numberStrings_cat.h"
#include "printEnds_cat.h"
#include "printTabs_cat.h"
#include "squeezeStrings_cat.h"

void applyOptions_cat(char *pars_res, FILE *f) {
  char previous = '\n';
  int current = fgetc(f);
  int num_pairs = 0;
  int num_all = 1, num_non_empty = 1;
  while (current != EOF) {
    if (strstr(pars_res, "s") != NULL)
      squeezeStrings_cat(&num_pairs, previous, current);
    if (num_pairs <= 1) {
      if (strstr(pars_res, "b") != NULL || strstr(pars_res, "n") != NULL)
        numberStrings_cat(pars_res, &num_all, &num_non_empty, previous,
                          &current);
      if (strstr(pars_res, "t") != NULL || strstr(pars_res, "T") != NULL)
        printTabs_cat(pars_res, &current);
      if ((strstr(pars_res, "e") != NULL && strstr(pars_res, "T") == NULL) ||
          (strstr(pars_res, "E") != NULL && strstr(pars_res, "t") == NULL))
        printEnds_cat(pars_res, &current, previous);
      if (strstr(pars_res, "v") != NULL)
        nonPrint_cat(&current);
      printf("%c", current);
    }
    previous = current;
    current = fgetc(f);
  }
}
