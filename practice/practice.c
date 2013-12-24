#include <string.h>
#include <stdio.h>
#include <stdlib.h>


char * removeDuplicates(char * string);


int main(){
  
 
  char *testString = "Bill Gestrich"; //Bil Gestrch
  char * result = removeDuplicates(testString); 
  printf("Result = %s\n", result);

  return 0;

}

char * removeDuplicates(char * string){
  if(string == NULL){
    printf("No string argument\n");
    return NULL;
  }

  //variable to hold next position in string to copy to

  //variable to hold position in string being analyzed 
  //Build array for each character

  //malloc 128 size
  char *characterArray = malloc( sizeof(char)*('a'-'Z'+1) ); 
  if(!characterArray){
    //error
    printf("Error allocating space\n");
    return NULL;
  }
  int length = strlen(string);
  char *newString = malloc(sizeof(char)*length);
  if(!newString){
    //error
    printf("Error allocating space\n");
    return NULL;
  }

  for(int i = 0; i<length; i++){
printf("i = %u\n", i);
  }

//for each letter in string
  //check if exists in array
  //if yes, delete
    //Delete by not copying to next available spot in string
  //if no, add to array
    //move to next available spot in array

    //Add NULL byte at end
if(characterArray){
  free(characterArray);
}

return NULL;

}
