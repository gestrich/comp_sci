#import <stdlib.h>
#import <stdio.h>
#import <math.h>

typedef struct Tree{
  int value;
  struct Tree * leftChild;
  struct Tree * rightChild;
}Tree;

void binarySearch(Tree *tree, int target, int bestSoFar);



int main (){
  Tree myTree;
  Tree myTree2;
  Tree myTree3;
  myTree.value = 10;
  myTree2.value = 11;
  myTree3.value = 9;
  myTree.leftChild = &myTree3;
  myTree.rightChild = &myTree2;

  myTree2.leftChild = NULL;
  myTree2.rightChild = NULL;

  myTree3.leftChild = NULL;
  myTree3.rightChild = NULL;

  binarySearch(&myTree, 8, INFINITY); 
  return 0;

}


void binarySearch(Tree *tree, int target, int bestSoFar){
 if(tree == NULL){
   printf("Next highest = %d\n", bestSoFar);
    return; 
 }

 if(tree->value <= target){
  //nodeVal Can't be bestSoFar, go right
   binarySearch(tree->rightChild, target, bestSoFar);
  }else{
   //if nodeVal > target, go left  
  // if nodeVal < bestSoFar then bestSoFar = nodeVal
    if(tree->value < bestSoFar) bestSoFar = tree->value;
     binarySearch(tree->leftChild, target, bestSoFar);
    }
  return;  
}
