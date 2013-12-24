#import <stdio.h>
#import <string.h>
#import <stdlib.h>

typedef struct DynamicArray{
  char * array; 
  int size;    
  int capacity;    
} DynamicArray;

char * resizeArray( DynamicArray * array);
void addElement( DynamicArray * array, char element );

int main(){

  FILE *fp1 = fopen("file1.txt", "r"); //1452
  FILE *fp2 = fopen("file2.txt", "r"); //501

  if(!fp1){
    printf("File 1 could not be read\n");
    return 0;
  }

  if(!fp2){
    printf("File 2 could not be read\n");
    return 0;
  }

  DynamicArray array1;
  array1.size = 0;
  array1.array = NULL;
  array1.capacity = 0;

  DynamicArray array2;
  array2.size = 0;
  array2.array = NULL;
  array2.capacity = 0;

  DynamicArray resArray;
  resArray.size = 0;
  resArray.array = NULL;
  resArray.capacity = 0;

  char character;

  //Copy file 1 to dynamic array 
  int file1Size = 0;
  while( fread(&character, 1, 1, fp1) != 0){
    if(character >= '0' && character <= '9' ){
      addElement( &array1, character);
      file1Size++;
    }
  }

  //Copy file 2 to dynamic array 
  int file2Size = 0;
  while( fread(&character, 1, 1, fp2) != 0){
    if(character >= '0' && character <= '9' ){
      addElement( &array2, character);
      file2Size++;
    }
  }


  addElement(  &array1, '\0' );
  addElement(  &array2, '\0' );
  printf("array1.array = %s\n", array1.array);
  printf("array2.array = %s\n", array2.array);

  int carry = 0;
  int file1Index = file1Size;
  int file2Index = file2Size;
  while( file2Index >0 || file1Index >0){
    file1Index--; 
    file2Index--; 
    int value1 = 0;  
    int value2 = 0;  

    if(file1Index >=0){
      value1 = array1.array[file1Index] - '0' ; 
    }

    if(file2Index >=0){
      value2 =  array2.array[file2Index] - '0'; 
    }


    int result = value1 + value2 + carry;

    if(result >= 10){
      carry = 1;
    }else{
      carry = 0;
    }

    //write to file
    printf("result: %u\n", result % 10);
    addElement(  &resArray, result%10 + '0'  );

  }

  //Bring out final carry
  if(carry){
    addElement(  &resArray, carry + '0'  );
  }


  addElement(  &resArray, '\0' );
  FILE *resFile = fopen("file3.txt", "w+");
  if( !resFile ) return 0; 
    printf("capacity = %u\n", resArray.capacity);
  for(int i = resArray.capacity - 2 ; i >= 0; i--){
    printf("i = %u\n", i);
    int size = fwrite(&resArray.array[i], 1, 1, resFile);
    putc(resArray.array[i], stdout);
  }
  putc('\n', stdout);

  fclose(resFile);


  return 0;

}


char * resizeArray( DynamicArray * array){
  char * res;
  int newSize;
  if(array->size == 0){
    // uninitialized array
    newSize = 1;
    res = (char*)malloc(newSize); 
  }else{
    // must copy array
    newSize = array->size * 2;
    res = (char*)malloc( newSize );
    char *tempRes = res;
    for(int i = 0; i < array -> size; i++){
      tempRes = (char *)( res + i );
      *tempRes = (char)*(array->array + i );
    }
    free(array->array); // free old memory
  }

  array->array = res;
  array->size = newSize;

  return res;
}

void addElement( DynamicArray * array, char element ){
  if( array->size == array->capacity ) resizeArray(array);

  char * tempRef = (char*)(array->array + array->capacity);
  *tempRef = element;
  array->capacity++;
}
