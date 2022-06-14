#ifndef _AIMA_H
#define _AIMA_H

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <ctype.h>

#define STR_SZ (2048)

void grab_input(char * input, size_t size);
void loop(void);
const char * ans2str(int ans);
uint32_t hash(char * key);

#endif /* _AIMA_H */
