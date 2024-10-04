#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/parser.h"
#include "../common/quantity.h"
#include "../common/searchRepeats.h"
#include "../common/strlensum.h"
#include "applyOptions_cat.h"

int main(int argc, char **argv) {
  int pars_flag = 0, fflag = 0;
  int flags_q = flags_quantity(argc, argv);
  char *pars_res = calloc(strlensum(argc, argv) + 1, sizeof(char));
  if (pars_res != NULL && argc > 0) {
    pars_flag = parser(flags_q, &fflag, 0, pars_res, argc, argv);
    pars_res[strlen(pars_res)] = '\0';
    for (int i = flags_q + 1; i < argc; i++) {
      if (pars_flag != -1) {
        FILE *f = fopen(argv[i], "r");
        if (f != NULL) {
          applyOptions_cat(pars_res, f);
        } else
          printf("cat: %s: no such file or directory.", argv[i]);
        fclose(f);
      } else {
        printf("cat: illegal option. Please, enter only approptiate flags: "
               "[-belnstuv].");
        break;
      }
    }
  } else
    printf("ERROR! Allocation memory for the flags sequence is failed.");
  free(pars_res);
  return 0;
}
