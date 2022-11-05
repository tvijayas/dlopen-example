#include <iostream>
#include <dlfcn.h>
#include <stdio.h>

using namespace std;

extern "C" int get_count(void);
extern "C" void increment_count(void);

int main(void){

   void *handle1,*handle2;
   void (*IncCount)(void);
   void (*GetCount)(void);
   char *error;

   /*lib reference count=1*/
   handle1 = dlopen("libmylib.so", RTLD_LAZY);
   
   if (!handle1) {
      fprintf(stderr, "%s\n", dlerror());
      exit(EXIT_FAILURE);
   }
                 
   dlerror();/* Clear any existing error */
   
   *(void **) (&IncCount) = dlsym(handle1, "increment_count");
   *(void **) (&GetCount) = dlsym(handle1, "get_count");
   
   IncCount();
   
   error = dlerror();
   if (error != NULL) {
      fprintf(stderr, "%s\n", error);
      exit(EXIT_FAILURE);
   }       
                          
   cout<< "I'm in main" <<endl;
   increment_count();
   cout<< get_count() <<endl;
   
   /*lib reference count=2*/
   handle2 = dlopen("libmylib.so", RTLD_LAZY);
   
   if (!handle2) {
      fprintf(stderr, "%s\n", dlerror());
      exit(EXIT_FAILURE);
   }
   
   cout<< "handle1 = " <<(unsigned int)handle1 <<endl;
   cout<< "handle2 = " <<(unsigned int)handle2 <<endl;
   
   /*lib reference count reduced from 2 to 1*/
   dlclose(handle1);
   
   /*handle1 still works as the reference to the library not 0*/
   *(void **) (&IncCount) = dlsym(handle1, "increment_count");
   increment_count();
   cout<< get_count() <<endl;
   
   /*handle2 also works*/
   *(void **) (&IncCount) = dlsym(handle2, "increment_count");
   increment_count();
   cout<< get_count() <<endl;
   
   /*lib reference count reduced from 1 to 0*/
   dlclose(handle1);
      
   return 0;
}
