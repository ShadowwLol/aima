#ifndef _RAND_H
#define _RAND_H

/* LCG IMPLEMENTATION */
void randomize(int newseed);
int lcg_rand(void);
int lcg_range(int min, int max);

#endif /* _RAND_H */
