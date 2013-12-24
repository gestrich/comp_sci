#import <stdio.h>
#import <stdlib.h>

int reverseWords(char words[], int length);

int main(){

  char name[] = "Bill Gestrich";

  int success = reverseWords(name, 13);

  if(!success){ 
    puts("error occurred");
  }else{
    printf("Reversed words: %s\n", name);
  }
  return 1;
}


int reverseWords(char words[], int length){

   //somehow check if aarray valid?

  // check valid length
  if(length < 0) return 0;

  int *copyWords = malloc(length);
  if(!copyWords) return 0; //malloc failed
 
  int wordsIndex = length-1; //backwards loop var
  int wordEndIndex = length-1; // end of current word index
  int copyIndex = 0;      //index in copy buffer 
  int loopIndex;

  //Loop from end of buffer until index < 0
  while(wordsIndex >=0){
    if(words[wordsIndex] == ' ' || wordsIndex == 0){
      //if character is space, copy the word to buffer
      //copy from char after space to end of word
      if(wordsIndex !=0){
        loopIndex = wordsIndex+1; 
      }else{
        loopIndex = wordsIndex; 
      }
      while( loopIndex <= wordEndIndex){
        copyWords[copyIndex++] = words[loopIndex];
        loopIndex++;
      }

      if(wordsIndex>0){
        //add a space at end if not on first index of array (last word)
       copyWords[copyIndex++] = ' '; 
      }

      wordEndIndex = wordsIndex-1;

    }


    //decrement index
    wordsIndex--;
  }

  //Copy buffer to original array

  for(int i = 0; i<length; i++){
    words[i] = copyWords[i];
  }

  //success 
  return 1;
}
