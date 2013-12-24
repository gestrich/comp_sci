#include <stdio.h> //for printf

#include "BinarySearchTree.h"

struct TreeNode
{
  ElementType data;
  SearchTree Left;
  SearchTree Right;
}

SearchTree MakeEmpty(SearchTree T)
{
  if(T!=NULL)
  {
    MakeEmpty(T->Left);
    MakeEmpty(T->Right);
    free(T);
  }
  return NULL;
}

Position Find(ElementType X, SearchTree T)
{
  if(T==NULL)
    return NULL;
    else if(X<T->data)
      return Find(X,T->Left);
    else if(X>T->data)
      return Find(X,T->Right);
    else
      return T;
  }

int main(){


  return 0;
}
