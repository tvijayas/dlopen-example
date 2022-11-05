#include "stdio.h"


static int count = 0;
int get_count(void){
  return count;
}

void increment_count(void){
  count++;
}
