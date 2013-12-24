#include <pthread.h>
#include <stdio.h>

void *testFunction( void *something);

int main(){

  puts("test");
 
 pthread_t myThread;

 char *testString = "Thread string";
 
 if ( pthread_create( &myThread, NULL, testFunction, testString   ) == 0){
   puts("In loop");
 }
  
  pthread_join(myThread, NULL);
  puts("Exiting");
  return 0;
}


void *testFunction( void * something ){

  printf("\ntestFunction param: %s\n", (char*)something);
  return NULL;
}
