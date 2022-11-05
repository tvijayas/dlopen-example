#include "stdio.h"


static int count = 0;
int get_count(void){
  return count;
}

void increment_count(void){
  count++;
}

__attribute__((constructor)) void lib_init(void){
  fprintf(stderr,"%s \n","mylib loaded");   
}

__attribute__((destructor)) void lib_exit(void){
  fprintf(stderr,"%s \n","mylib unload");
}
