#include <stdio.h>
#include <stdlib.h>

void PrintNumber(int startIndex, char *string, int length);


int main(){
  PrintNumber(0, "1?00?101", 8);
  return 0;

} 


void PrintNumber(int startIndex, char *string, int length){

  //get next digit >= index with ?
  int foundIndex = -1;
  for(int i = startIndex; i < length; i++){
    if( *(string + sizeof(char)*i ) == '?'){
      //? found
      foundIndex = i;
      break;
    }
  }
  printf("foundIndex = %d\n", foundIndex);
  if(foundIndex == -1){
    //Base case -- no characters left with '?'
    //print string
    printf("String: %s\n", string);
    return;
  }
  
  if(startIndex >= length) return; // string consumed

  //found another '?'


  //Create copy with '0'  
  char *copy1 = malloc( sizeof(char)*length + 1);
  if(!copy1) return;  //error
  for(int i = 0; i < length; i++){
    *(copy1 + sizeof(char)*i) = *(string + sizeof(char)*i);  
  }
  *(copy1 + sizeof(char)*length) = '\0'; //null term
  *(copy1 + sizeof(char)*foundIndex) = '0';

  //Create copy with '1'  
  char *copy2 = malloc( sizeof(char)*length + 1);
  if(!copy2) return;  //error
  for(int i = 0; i < length; i++){
    *(copy2 + sizeof(char)*i) = *(string + sizeof(char)*i);  
  }
  *(copy2 + sizeof(char)*length) = '\0'; //null term
  *(copy2 + sizeof(char)*foundIndex) = '1';
  PrintNumber(  foundIndex + 1, copy1, length );
  PrintNumber(  foundIndex + 1, copy2, length );

}


