#include <regex.h>
#include <stdio.h>
#include <string.h>

#include "compareRegex_grep.h"
#include "notRepeated_grep.h"

void searchTemplate_grep(char *pars_res, char *string, char *templ, FILE *f,
                         int argc, char **argv, int i, int j, int string_num,
                         int trulse, int ignor_reg, int flag_no_name, int l,
                         int min) {
  int no_repeat = 1;
  if ((compareRegex_grep(string, templ, ignor_reg) == 0) == trulse) {
    if (strstr(pars_res, "f") != NULL)
      no_repeat = 1;
    else
      no_repeat = notRepeated_grep(pars_res, string, argv, j, l);
    if (strstr(pars_res, "c") == NULL && strstr(pars_res, "l") == NULL &&
        (no_repeat == 1)) {
      if (strstr(pars_res, "n") != NULL && strstr(pars_res, "o") == NULL) {
        if ((argc - min == 1) || flag_no_name == 1)
          printf("%d:%s", string_num, string);
        else
          printf("%s:%d:%s", argv[i], string_num, string);
        if (((feof(f) != 0) || (i == argc - 1)) &&
            (strstr(string, "\n") == NULL))
          printf("\n");
      } else if (strstr(pars_res, "o") == NULL &&
                 strstr(pars_res, "n") == NULL) {
        if ((argc - min > 1) && flag_no_name == 0)
          printf("%s:", argv[i]);
        printf("%s", string);
        if (((feof(f) != 0) || (i == argc - 1)) &&
            (strstr(string, "\n") == NULL))
          printf("\n");
      }
    }
  }
}
