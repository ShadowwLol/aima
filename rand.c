#include "rand.h"

static unsigned int seed = 1;

void randomize(int newseed){
  seed = (unsigned)newseed & 0x7fffffffU;
}

int lcg_rand(void){
  seed = (seed * 1103515245U + 12345U) & 0x7fffffffU;
  return (int)seed;
}

int lcg_range(int min, int max){
  return ((lcg_rand() % max) + min);
}
