#include <stdio.h>
#include <string.h>

#include "quantity.h"

int strlensum(int argc, char **argv) {
  size_t sum = 0;
  int flags = flags_quantity(argc, argv);
  for (int i = 1; i < flags + templs_quantity(argc, argv, flags) + 1; i++) {
    if (argv[i][0] == '-') {
      sum += strlen(argv[i]) - 1;
    }
  }
  return sum;
}
