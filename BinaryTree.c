#include <stdio.h>
#include <malloc.h>

// Linked Representation

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* createNode(int data) {
  struct node *n; // Assigning a new node
  n = (struct node*) malloc(sizeof(struct node)); // Allocating memory for the new node
  n->data = data; // Setting the data
  n->left = NULL; // Setting the left node to NULL
  n->right = NULL; // Setting the right node to NULL
  return n; // Returning the node
}

void preOrderTraversal(struct node *root) {
  if (root != NULL) {
    printf("%d ", root->data); // Visiting the parent node
    preOrderTraversal(root->left); // Recursively visiting the left subtree
    preOrderTraversal(root->right); //Recursively visiting the right subtree
  }
}

void postOrderTraversal(struct node *root) {
  if (root != NULL) {
    postOrderTraversal(root->right); // Recursively visiting the right subtree
    postOrderTraversal(root->left); // Recursively visiting the left subtree
    printf("%d ", root->data); // Visiting the parent node
  }
}

void inOrderTraversal(struct node* root ) {
  if (root != NULL) {
    inOrderTraversal(root->left); // Recursively visiting the left subtree
    printf("%d ", root->data); // Visiting the parent node
    inOrderTraversal(root->right); // Recursively visiting the right subtree
  }
}

int main()
{

  //Constructing the parent node
  struct node* p = createNode(4);

  //Constructing the children node
  struct node* p1 = createNode(1);
  struct node* p2 = createNode(6);
  struct node* p3 = createNode(5);
  struct node* p4 = createNode(2);
  struct node* p5 = createNode(7);
  
  //Linking the chidren to the parent node
  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;
  p2->right = p5;

  preOrderTraversal(p);
  printf("\n");
  postOrderTraversal(p);
  printf("\n");
  inOrderTraversal(p);

  return 0;
}