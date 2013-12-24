#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void printBinary(char*floatString);

int main(){

  char *floatNumber = "11.75757575757575";  //binary = 10110110
  printf("********\n");
  printf("  %s \n", floatNumber);
  printf("********\n");
  printBinary(floatNumber);

  return 0;
}


void printBinary(char* floatString){

  int length = strlen(floatString);

  //Calculate whole number binary before '.'
  int wholeNumber = floor( atof(floatString));
  int wholeBinaryLength = floor( log2( wholeNumber )) + 1;   //.floor( log2(11))+1     3+1 = 4.
  char wholeArray[wholeBinaryLength];
  int i = 0;
  while( i < wholeBinaryLength ) wholeArray[i++] = '0';

  int temp = wholeNumber;
  while(wholeNumber > 0 ){
    int exponent = floor( log2( wholeNumber ));
    wholeArray[ wholeBinaryLength - exponent -1] = '1'; // 4 - 3 - 1 = 0 index... 2 index, 3 index
    wholeNumber = wholeNumber - pow(2.0, (float)exponent);
  }

  //print whole number
  printf("Whole Number: ");
  for(int i = 0; i < wholeBinaryLength; i++) fputc(wholeArray[i], stdout); 
  printf("\n");

  //Calculate decimal portion

  char decimalArray[4];

  float multiplier =  atof(floatString) - floor( atof(floatString)); // 11.08 -> 11.08 - 11 = .08

  for(int i = 0; i < 4; i++){

    multiplier = (multiplier - floor(multiplier)) * 2;  //  .08 * 2  = .16
    if (multiplier >= 1){
      decimalArray[i] = '1';
    }else{
      decimalArray[i] = '0';
    }
  }

  //print the number
  for(int i = 0; i < 4; i++) fputc(decimalArray[i], stdout);

}
