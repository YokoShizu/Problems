#include <regex.h>
#include <stdio.h>
#include <string.h>

#include "compareRegex_grep.h"

void presenceStringNumber_grep(char *templ, char *string, int *quan, int trulse,
                               int ignor_reg) {
  if ((compareRegex_grep(string, templ, ignor_reg) == 0) == trulse)
    (*quan)++;
}
