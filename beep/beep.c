//code from: https://github.com/zserge/beep/blob/master/beep.h
#include "Beep.h"

#include <stdlib.h>

int main(int argc, char *argv[]) {
  for (int i = 0; i < (argc - 1) / 2; i++) {
    Beep(atoi(argv[i * 2 + 1]), atoi(argv[i * 2 + 2]));
  }
  return 0;
}
