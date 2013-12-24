#include <stdlib.h>
#include <stdio.h>



//Struct with linked list structure
typedef struct Element{
  struct Element *next;
  void *data;
}Element;


Element * findItem(void *data);
int insert(void *data);
int deleteItem(void *data);
void printItems();


//head and tail globals

Element *head;
Element *tail;

//main to test linked list

int main(){

  int *data = malloc(sizeof(int));
  *data = 10;
  insert(data);   
  int *data2 = malloc(sizeof(int));
  *data2 = 99;
  insert(data2);
  printItems();
  deleteItem(data);
  //printItems();

  Element *foundItem = findItem(data);

  if(foundItem){
    printf("Found item\n");
  }else{
    printf("Item not found\n");
  }



  return 1;
}


//find item
Element * findItem(void *data){

  if(!data) return NULL;

  Element *currElement = head;

  while(currElement !=NULL){

    if(currElement->data == data) return currElement;
    currElement = currElement->next;
  }

  return NULL;

}


//insert item
int insert(void *data){

  if(!data) return 0;

  //Create element
  Element *newElement = malloc(sizeof(Element));
  if(!newElement) return 0; //error

  newElement->data = data; //newElement points to address of data

  if(head){
    newElement->next = head;
  } 

  head = newElement; //head will now reference newElement memory location

  return 1;
  
}


//delete item
int deleteItem(void *data){

  if(!data) return 0; //error

  Element *currElement = head;

  //special case for head

  if(head && head->data==data){
    free(head);
    head = NULL;
    return 1;
  }

  while(currElement->next != NULL){

    if(currElement->next->data == data){
      //found item as next element

      Element *deleteElement = currElement->next;

      if(deleteElement == tail){ 
        tail =  currElement;  //special case -- deleting tail 
        currElement->next = NULL;
      }else{
        currElement->next = deleteElement->next; // update next reference for item before delete element
      }

      free(deleteElement); //remove the element
      return 1;
    }

  }

  return 0;

}


//print items
void printItems(){
  Element *currentElement = head;
  while(currentElement) {
    printf("\nPrinting Element with value %u\n", *(int *)(currentElement->data) ); 
    currentElement = currentElement->next;
  }
}
