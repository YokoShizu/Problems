#include <regex.h>
#include <stdio.h>
#include <string.h>

int compareRegex_grep(const char *string, const char *templ, int ignor_reg) {
  regex_t reg_ex;
  int cflags = 0;
  if (ignor_reg) cflags |= REG_ICASE;
  if (regcomp(&reg_ex, templ, cflags) != 0) {
    return 1;
  }
  int r = regexec(&reg_ex, string, 0, NULL, 0);
  regfree(&reg_ex);
  return r;
}
