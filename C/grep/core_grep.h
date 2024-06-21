#ifndef CORE_GREP_H
#define CORE_GREP_H

void core_grep(char *pars_res, char *string, char *templ, int argc, char **argv,
               FILE *f, int i, int j, int string_num, int *trulse,
               int *quantity, int *ignor_reg, int *flag_no_name, int l,
               int min);

#endif
