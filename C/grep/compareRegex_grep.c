#include <regex.h>
#include <stdio.h>
#include <string.h>
int compareRegex_grep(char *string, char *templ, int ignor_reg) {
  int flag;
  regex_t reg_ex;
  if (ignor_reg == 1) {
    regcomp(&reg_ex, templ, REG_ICASE);
    if (!((strcmp(string, "\n") == 0) && (strcmp(templ, ".") == 0)))
      flag = regexec(&reg_ex, string, 0, NULL, 0);
  } else {
    regcomp(&reg_ex, templ, 0);
    if (!((strcmp(string, "\n") == 0) && (strcmp(templ, ".") == 0)))
      flag = regexec(&reg_ex, string, 0, NULL, 0);
  }
  regfree(&reg_ex);
  return flag;
}
