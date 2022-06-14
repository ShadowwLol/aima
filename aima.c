#include "aima.h"
#include "rand.h"

typedef enum{
  ANSWER_BEGIN,

  ANSWER_UNSURE,
  ANSWER_YES,
  ANSWER_NO,

  ANSWER_END,
} answer;

int main(void){
  while (1){
    loop();
  }
  return 0;
}

void loop(void){
  printf("> ");

  char input[STR_SZ] = "\0";
  grab_input(input, STR_SZ);

  int seed = hash(input);
  randomize(seed);

  int num = lcg_range(ANSWER_BEGIN + 1, ANSWER_END - 1);
  printf("[#]: %s\n", ans2str(num));
}

void grab_input(char * input, size_t size){
  char tmp[size];
  fgets(tmp, size, stdin);
  tmp[strlen(tmp) - 1] = '\0';

  size_t j = 0;
  for (size_t i = 0; tmp[i] != '\0'; ++i){
    if (isalnum(tmp[i])){
      input[j] = tolower(tmp[i]);
      ++j;
    }
  }
  input[j] = '\0';
}

const char * ans2str(int ans){
  switch(ans){
    default:
      return "I'm sorry, I didn't understand.";
    case ANSWER_UNSURE:
      return "I'm not sure.";
    case ANSWER_YES:
      return "Yes.";
    case ANSWER_NO:
      return "No.";
  }
}

uint32_t hash(char * key){
  uint32_t hash = 2166136261u;
  for (uint64_t i = 0; key[i] != '\0'; ++i) {
    hash ^= (uint8_t)key[i];
    hash *= 16777619;
  }
  return hash;
}
