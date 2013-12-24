#include <time.h>
#include <stdio.h>
#include <stdlib.h>


/*
* Should line near 108 be  <= ??? tried and got seg fault

example of fail:
QuickSelect called with size = 3 k = 2
37 39 21 
Pivot index = 1, Pivot value = 39
Swapping value 39 for value 21
i = 0
i = 1
i = 2
Last left index = 1
Quick select result = 21
5 5 3 8 14 37 21 39 41 45 
Sorted 7th = 37
FAIL

*/


int quickSelect(int *list, int k, int size);
void printArray(int *arrayToPrint, int size);
void swap(int *list, int index1, int index2);
int * copyArray(int *list, int size);
int *sort(int *list, int size);

int main(int argc, char *argv[] ){

  /*printf("argc = %d\n", argc);
  int argNum = 1;
  printf("argv[%u] = %s\n", argNum, argv[argNum]);
  */

  int size = 10;
  for(int i = 1; i < size; i++){
    int k = i;

    printf("*********************************\n");
    printf("BEGIN\n");
    printf("*********************************\n");
    //Create array of numbers
    int numbers[size];

    time_t t;

    int i, n;
    n = 5;
    /* Intializes random number generator */
    srand((unsigned) time(&t));

    /* Print 5 random numbers from 0 to 50 */
    for( int j = 0 ; j < size ; j++ ) {
      numbers[j] = rand() % 50;
    }
    printArray(numbers, size);

  int *sortedArray = sort(numbers, size);
  printf("Sorted version *****\n");
  printArray(sortedArray, size);
  printf("End Sorted version *****\n");

    int quickSelectRet = quickSelect( numbers, k, size );
    printf("Quick select result = %d\n", quickSelectRet ); 

    printArray(numbers, size);
    printf("Sorted %uth = %u\n", k, sortedArray[k-1]);
    if(sortedArray[k-1] != quickSelectRet){
      printf("FAIL\n");
      return 1;
    }else{
      printf("PASS\n");
    }
  }
  return 0;

}


int quickSelect(int *list, int k, int size){
printf("QuickSelect called with size = %d k = %d\n", size, k); 
printArray(list, size);
 if(!list){
    //error
    printf("No list provided\n");
    return -1 ; 
  }  
  
  if(size <= 0){
    //error 
     printf("Invalid list size\n");
     return -1;   
  }else if(size == 1){
     printf("Base case\n");
     return list[0];   
  }

  //Choose some random pivot point
  //Pivot will end up on the left side of array
  int pivotIndex = (size / 2) - 1;  //Truncated size 1: 0, size 2: 1, size 3: 1, size 4: 2
  int pivotValue = list[pivotIndex ]; 
printf("Pivot index = %d, Pivot value = %d\n", pivotIndex, pivotValue);
  //Move the pivot to the end of array so that it will be the last left index
  swap(list, pivotIndex, size-1);  

  int lastLeftIndex = 0;
  int i = 0;
  int j = i; //next item to swap to left partition (smaller than pivot)
  for(; i < size; i++){
    printf("list[%u]=%d\n", i, list[i]);
    if(j<=i) j++;
    while(  (j < size-1)  &&  (list[j] > pivotValue)  ) j++; // skip until you get a value <= pivot 
       //The while loop stops when runs off array or finds value less or equal to pivot

    //partition array 
    if( list[i] > pivotValue && j < size  ){
      //You want the pivotValue included as your last left index
      //That way you can terminate the algorithm early -- when the number of left items is equal to k
      lastLeftIndex = i;
      //swap
      swap(list, i, j );
    }

    if( list[i] <= pivotValue ) lastLeftIndex = i;
        
  } // end loop for i
printf("Last left index = %d\n", lastLeftIndex);
  //Recursive call with array from 0 to last index of left side
  if(lastLeftIndex+1 == k){
    //Found kth index, done
    return list[lastLeftIndex];
  }else if(lastLeftIndex+1>k){
    // kth smallest item must be on the left still
    return quickSelect(list, k, lastLeftIndex+1);
  }else{
    // kth smallest item must be on the right 
    int *rightList = (int*)( list + ((lastLeftIndex+1)) );
printf("original address = %p\n", &list);
printf("new address = %p\n", rightList);
printf(" ((lastLeftIndex+1)*sizeof(int))= %lu\n",((lastLeftIndex+1)*sizeof(int)));
    printf("sizeofint = %lu\n", sizeof(int));
    return quickSelect(rightList, k - (lastLeftIndex+1), size-(lastLeftIndex+1));
  }

} 

void swap(int *list, int index1, int index2){
  printf("Swapping value %d for value %d\n", list[index1], list[index2] );
  int temp = list[index1];
  list[index1] = list[index2];
  list[index2] = temp;
}
void printArray(int *arrayToPrint, int size){
  if(!arrayToPrint){
    printf("Invalid arrayToPrint\n");
  }
  for(int x=0; x<size; x++){
    printf("%d ", arrayToPrint[x] );
  }
  printf("\n");
}

int * copyArray(int *list, int size){
  if(!list){
    printf("No array passed to copyArray\n");
    return 0;
  } 

  int *toRet = malloc( sizeof(int)*size);
  if(!toRet){
    printf("Could not allocate space\n");
    return 0;
  }
  for(int i = 0; i<size; i++){
    toRet[i] = list[i];
  }  
  return toRet;
}


int *sort(int *list, int size){

  int *listCopy = copyArray(list, size);
  if(!listCopy) return 0;

  int smallestIndexSoFar = -1;
  for(int i = 0; i < (size-1); i++){
    smallestIndexSoFar = i;
    for(int j = i+1; j < size; j++){
      if(listCopy[j]<=listCopy[smallestIndexSoFar]){
        smallestIndexSoFar = j;
      }
    }
    swap(listCopy, i, smallestIndexSoFar);  
  }

  return listCopy;
}
