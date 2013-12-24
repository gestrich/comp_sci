#import <stdlib.h>
#import <stdio.h>

typedef struct Tree{
  void *data;
  void *children; //pointer to array of children
  int numChildren; 
} Tree;

int depth(Tree *root, Tree *node);

int main(){

  Tree child1;
  child1.data = NULL;
  child1.numChildren = 0;
  child1.children = NULL;
  Tree *children[] = {&child1  };

  Tree myTree;
  myTree.children = children;
  myTree.data = NULL;
  myTree.numChildren = 1;

  printf("myTree depth = %d\n", depth(&myTree, &child1) ); // 
  
  return 0;
}


int depth(Tree *root, Tree *node){
  if (node == NULL) return -1; // leaf, node not in this tree
  if (root == node) return 0; //found node, depth 0 in this tree
  if(root->numChildren == 0) return -1;

  int nodeDepth = -1;
  for (void **i = root->children; i < (void**)(root->children + root->numChildren * sizeof(void**) ); i += sizeof(void**)){
    void *child = (Tree*)*i;
    int tempDepth = depth( child, node ); //recursive call
    if (tempDepth > -1) nodeDepth = tempDepth + 1; // found node, set return value & add 1 for this level
  }
  return nodeDepth;
}
