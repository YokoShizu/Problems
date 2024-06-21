#include <regex.h>
#include <stdio.h>
#include <string.h>

#include "onlyTheSameParts_grep.h"
#include "presenceStringNumber_grep.h"
#include "searchTemplate_grep.h"

void core_grep(char *pars_res, char *string, char *templ, int argc, char **argv,
               FILE *f, int i, int j, int string_num, int *trulse,
               int *quantity, int *ignor_reg, int *flag_no_name, int l,
               int min) {
  if (strstr(pars_res, "v") != NULL) {
    (*trulse) = 0;
  }
  if (strstr(pars_res, "i") != NULL)
    *ignor_reg = 1;
  if (strstr(pars_res, "h") != NULL)
    *flag_no_name = 1;
  if (strstr(pars_res, "o") != NULL)
    onlyTheSameParts_grep(pars_res, string, templ, argc, argv, *ignor_reg, i, j,
                          string_num, *trulse, *flag_no_name, min, l);
  else if (strstr(pars_res, "c") != NULL || strstr(pars_res, "l") != NULL)
    presenceStringNumber_grep(templ, string, quantity, *trulse, *ignor_reg);
  if (strstr(pars_res, "e") != NULL &&
      !(strstr(pars_res, "f") != NULL && *trulse == 0)) // +
    searchTemplate_grep(pars_res, string, templ, f, argc, argv, i, j,
                        string_num, *trulse, *ignor_reg, *flag_no_name, l, min);
}
