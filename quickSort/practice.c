#include <stdlib.h>
#include <stdio.h>


void quickSort(int data[], int left, int right);


int main(){

  int data[5];
  data[0] = 0;
  data[1] =  1;
  data[2] = 2; 
  data[3] = 3; 
  data[4] = 4; 
  quickSort(data, 0, 3);
  printf("\n%u\n", data[0]);
  printf("\n%u\n", data[1]);
  printf("\n%u\n", data[2]);
  printf("\n%u\n", data[3]);
  printf("\n%u\n", data[4]);
  return 1;
}


void quickSort(int data[], int left, int right){

 printf("\nquicksort called for left = %u\n", left); 
 printf("\nquicksort called for right = %u\n", right); 

  int pivotValue = data[(right + left )/2];  //take average index (middle)

 printf("\nPivot index = %u\n", data[right+left]/2); 
  int i = left;
  int j = right;

  while( i <= j){
    //loop until i and j cross

    // Find leftmost value less than the pivot 
    // If you can't find one, you will stop on the pivot
    // This stops on the index to move
    while(data[i] < pivotValue ) i++;

    // Find rightmost value less than or equal to pivot
    while(data[j] > pivotValue ) j--;

    //do the swap if the two values are in wrong order
    if(i<=j){
      int tempLeft = data[i];
      data[i] = data[j];
      data[j] = tempLeft;
      //Move past the sorted items
      i++;
      j--;
    }

  }//swapping complete

  //recursive call

  if( left < j ){
    quickSort(data, left, j);
  }
  if( i < right ) { 
    quickSort(data, i, right);
  }

}
