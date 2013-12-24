#include <stdio.h>
#include <stdlib.h>


int calculate( char *calculation, int length, int *error);


int main(){


  char *calculation = "1+5+2*6*3+3*2"; // 48
  int length = 13;

  int error = 0;
  int result =  calculate(calculation, length,  &error);

  if(error){
    puts("Error has occurred");

  }else{
    printf("\nResult = %u\n", result);
  }

  return 0;
}


int calculate( char *calculation, int length, int *error){

  if(!calculation || length < 1 ){
    //invalid input
     *error = 1;
     return 0;
  }

  int completedValue = 0; //completed calcuations up to now
  int temp = 0;
  char lastOp;

  for(int i = 0; i < length; i++){

    //check for invalid characters
    if( !( calculation[i] == '*' || calculation[i] == '+' || (calculation[i] >= '0' && calculation[i] <= '9')   )){
     *error = 1;
     return 0;
    }

    //skip over * & + in loop
    if( calculation[i] == '*' || calculation[i] == '+'){
      lastOp = calculation[i];
       continue;
    }

    if(i==0){
      //first index, special case
      temp = (calculation[i] - '0');
      continue;
    }

    //if last op is a +,
    if(lastOp == '+'){
     completedValue += temp ;
     temp = (calculation[i] - '0');
    }

    //if last op is a *
    if(lastOp == '*'){
      temp *= (calculation[i] - '0');  
    }
  }

  //clear temp

  completedValue += temp;

  return completedValue;

}




