#include <string.h>
#include <stdio.h> //for printf
#include <stdlib.h> //for malloc



typedef struct Element{
 struct Element *next;
 void *data;
} Element;

Element *head;
Element *tail;

int insertInFront(Element **head, int *data);
int insertAfter( Element *elem, void * data );
void printList(Element *head);

int main(){

  head = malloc(sizeof(Element));
  memset(head, 0, sizeof(void*));
  int y = 5;
  int *x = malloc(sizeof(int));
  *x = 5;
  head->data = x;
//  head->next = NULL;

  int w = 6;
  int *z = malloc(sizeof(int));
  *z = w;

  insertInFront(&head, z);

  printList(head);

  return 0;
}

/*
  insertInFront

  params: 
    Element **head: The list to add to
    int *data: The data to add to new element 
  performance
   O(1)
*/
int insertInFront(Element **head, int *data){

  Element *newElem = malloc( sizeof(Element));
  if(!newElem) return 0;

  newElem->data = data;
  newElem->next = *head;
  *head = newElem;
  return 1;
}

int insertAfter( Element *elem, void * data ){
  Element *newElem, *curPos = head;

  newElem = malloc( sizeof(Element) );
  if( !newElem )
    return 0;
  newElem->data = data;

  /* Null elem parameter passed, insert at beginning of list */
  if( ! elem ){
    newElem->next = head;
    head = newElem; 

    /* Special case for empty list */
    if( !tail )
      tail = newElem;
    return 1;
  }

  while( curPos ){
    if( curPos == elem){
      newElem->next = curPos->next;
      curPos->next= newElem;

      /*Special case for inserting at end of list */
      if( !(newElem->next) )
        tail = newElem;
      return 1;
    }
    curPos = curPos->next;
  }
  
  /* Insert position not found; free element and return failure */
  free( newElem );
  return 0;
}

void printList(Element *head){
  Element *currNode = head;
  int count = 0;
  while(currNode){
    printf("Node = %u = %u\n", count, *(int*)(currNode->data));
    currNode = currNode->next;
    count++;
  }
}
