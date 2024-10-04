#include <stdio.h>

void squeezeStrings_cat(int *num_pairs, char previous, int current) {
  if (previous == '\n' && current == '\n')
    (*num_pairs)++;
  else
    *num_pairs = 0;
}
