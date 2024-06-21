#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "searchOptions.h"
#include "searchRepeats.h"
#include "strlensum.h"

int parser(int flags_q, int *fflag, int templs_q, char *pars_res, int argc,
           char **argv) {
  int flag = 0;
  if (strstr(argv[0], "s21_cat") != NULL && argc > 1 && flags_q > 0) {
    flag = searchOptions(flags_q, fflag, templs_q, pars_res, argv);
    if (strlen(pars_res) > 0) {
      searchRepeats(pars_res, argv);
      searchBN(pars_res);
      searchEV(pars_res);
      searchTV(pars_res);
    }
  } else if ((strstr(argv[0], "s21_grep") != NULL) && (argc > 2)) {
    flag = searchOptions(flags_q, fflag, templs_q, pars_res, argv);
    if (strlen(pars_res) > 0)
      searchRepeats(pars_res, argv);
  }
  return flag;
}
