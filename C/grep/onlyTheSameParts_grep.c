#include <regex.h>
#include <stdio.h>
#include <string.h>

#include "compareRegex_grep.h"
#include "notRepeated_grep.h"

void onlyTheSameParts_grep(char *pars_res, char *string, char *templ, int argc,
                           char **argv, int ignor_reg, int i, int j,
                           int string_num, int trulse, int flag_no_name,
                           int min, int l) {
  int no_repeat = 1, indent = 0, flag;
  regmatch_t match;
  regex_t reg;
  if (strstr(pars_res, "f") != NULL)
    no_repeat = 1;
  else
    no_repeat = notRepeated_grep(pars_res, string, argv, j, l);
  if (ignor_reg == 1 &&
      !((strcmp(string, "\n") == 0) && (strcmp(templ, ".") == 0))) {
    regcomp(&reg, templ, REG_ICASE);
    while (((flag = regexec(&reg, string + indent, 1, &match, 0)) == 0) ==
           trulse) {
      if (strstr(pars_res, "n") != NULL && strstr(pars_res, "o") != NULL &&
          strstr(pars_res, "c") == NULL && strstr(pars_res, "l") == NULL &&
          strstr(pars_res, "f") == NULL && no_repeat == 1) {
        if ((argc - min - 2 == 1) || flag_no_name == 1)
          printf("%d:%.*s", string_num, (int)(match.rm_eo - match.rm_so),
                 string + indent + match.rm_so);
        else
          printf("%s:%d:%.*s\n", argv[i], string_num,
                 (int)(match.rm_eo - match.rm_so),
                 string + indent + match.rm_so);
      } else if (strstr(pars_res, "n") == NULL &&
                 strstr(pars_res, "o") != NULL &&
                 strstr(pars_res, "c") == NULL &&
                 strstr(pars_res, "l") == NULL &&
                 strstr(pars_res, "f") == NULL && no_repeat == 1) {
        if (argc - min > 1 && flag_no_name == 0)
          printf("%s:", argv[i]);
        printf("%.*s\n", (int)(match.rm_eo - match.rm_so),
               string + indent + match.rm_so);
      }
      indent += match.rm_eo;
    }
  } else if (ignor_reg == 0 &&
             !((strcmp(string, "\n") == 0) && (strcmp(templ, ".") == 0))) {
    regcomp(&reg, templ, 0);
    while (((flag = regexec(&reg, string + indent, 1, &match, 0)) == 0) ==
           trulse) {
      if (strstr(pars_res, "n") != NULL && strstr(pars_res, "o") != NULL &&
          strstr(pars_res, "c") == NULL && strstr(pars_res, "l") == NULL &&
          strstr(pars_res, "f") == NULL && no_repeat == 1) {
        if ((argc - min - 2 == 1) || flag_no_name == 1)
          printf("%d:%.*s", string_num, (int)(match.rm_eo - match.rm_so),
                 string + indent + match.rm_so);
        else
          printf("%s:%d:%.*s\n", argv[i], string_num,
                 (int)(match.rm_eo - match.rm_so),
                 string + indent + match.rm_so);
      } else if (strstr(pars_res, "n") == NULL &&
                 strstr(pars_res, "o") != NULL &&
                 strstr(pars_res, "c") == NULL &&
                 strstr(pars_res, "l") == NULL &&
                 strstr(pars_res, "f") == NULL && no_repeat == 1) {
        if (argc - min > 1 && flag_no_name == 0)
          printf("%s:", argv[i]);
        printf("%.*s\n", (int)(match.rm_eo - match.rm_so),
               string + indent + match.rm_so);
      }
      indent += match.rm_eo;
    }
  }
  regfree(&reg);
}
