#include <iostream>
#include <dlfcn.h>
#include <stdio.h>

using namespace std;

extern "C" int get_count(void);
extern "C" void increment_count(void);

int main(void){

   void *handle;
   void (*IncCount)(void);
   void (*GetCount)(void);
   char *error;

   handle = dlopen("libmylib.so", RTLD_LAZY);
   
   if (!handle) {
      fprintf(stderr, "%s\n", dlerror());
      exit(EXIT_FAILURE);
   }
                 
   dlerror();    /* Clear any existing error */
   
   *(void **) (&IncCount) = dlsym(handle, "increment_count");
   *(void **) (&GetCount) = dlsym(handle, "get_count");
   
   IncCount();
   
   error = dlerror();
   if (error != NULL) {
      fprintf(stderr, "%s\n", error);
      exit(EXIT_FAILURE);
   }       
                          
   cout<< "I'm in main" <<endl;
   increment_count();
   cout<< get_count() <<endl;
      
   return 0;
}
