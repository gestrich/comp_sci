//Height of arbitrary tree


#include "stdio.h"
#include "stdlib.h"
#include "math.h"



typedef struct Tree{
  struct Tree *left;
  struct Tree *right;
  int data;
}Tree;

int depth(Tree  *tree);
Tree *createTree();


int main(){

  Tree *root = createTree();
  root->data = 0;
  Tree *left = createTree();
  left->data = 1;
  Tree *right = createTree();
  right->data = 2;
  Tree *right3 = createTree();
  right3->data = 3;
  root->left =  left;
  root->right =  right;
  right->right = right3;
  right3->left = createTree();
  right3->left->right = createTree();

  int value = depth(root);
  printf("\nDepth of tree = %u\n", value);

  return 0;
}

int depth(Tree *tree){
  puts("In depth");
  if(tree==NULL) return 0;
  printf("Node= %u", tree->data);

  puts("about to return");
  return 1 + fmax( depth(tree->left), depth(tree->right)    );
}

Tree *createTree(){

  Tree *tree = malloc(sizeof(Tree));
  if(!tree) return NULL;
    tree->right = NULL;
    tree->left = NULL;
  return tree;
}

