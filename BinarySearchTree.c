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

void inOrderTraversal(struct node* root ) {
  if (root != NULL) {
    inOrderTraversal(root->left); // Recursively visiting the left subtree
    printf("%d ", root->data); // Visiting the parent node
    inOrderTraversal(root->right); // Recursively visiting the right subtree
  }
}

/**
 * @brief Function to check if a given binary tree is a Binary Search Tree (BST).
 *
 * This function uses a recursive approach to check if a binary tree is a BST.
 * It compares the data of each node with its left and right children to ensure
 * that the tree follows the BST property.
 *
 * @param root A pointer to the root node of the binary tree.
 * @return 1 if the binary tree is a BST, 0 otherwise.
 *
 * @note This function assumes that the binary tree is a valid binary tree,
 * i.e., it does not contain duplicate values and the left child of a node is
 * always less than or equal to the parent node, and the right child is always
 * greater than the parent node.
 */
int isBST(struct node* root) {
  static struct node* prev;
  if (root != NULL) {
    if (!isBST(root->left)) {
      return 0;
    }
    if (prev != NULL && root->data <= prev->data) {
      return 0;
    }
    prev = root;
    return isBST(root->right);
  } else {
      return 1;
  }
}

// Binary search recursively
struct node* binarySearch(struct node* root, int n) {
  if (root == NULL) {
    return NULL;
  }
  if (root->data == n) {
    return root;
  } else if (root->data > n) {
    return binarySearch(root->left, n);
  } else {
    return binarySearch(root->right, n);
  }
}

//Binary search iteratively
struct node *binarySearchIter(struct node *root, int n) {
  while (root != NULL) {
    if (root->data == n) {
      return root; // Found
    } else if (root->data > n){
      root = root->left;
    } else {
      root = root->right;
    }
  }
  return NULL; // Element not found
}


int main()
{

  //Constructing the parent node
  struct node* p = createNode(4);

  //Constructing the children node
  struct node* p1 = createNode(2);
  struct node* p2 = createNode(6);
  struct node* p3 = createNode(3);
  struct node* p4 = createNode(3);
  struct node* p5 = createNode(7);
  
    //       4
    //     /  \
    //    2   6
    //   / \    \
    //  1   3    7

  //Linking the chidren to the parent node
  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;
  p2->right = p5;

  // preOrderTraversal(p);
  // printf("\n");
  // postOrderTraversal(p);
  // inOrderTraversal(p);
  // printf("\n");
  // printf("Is BST? %d\n", isBST(p));
  int n = 3;
  struct node* searched = binarySearch(p, n);
  if (searched != NULL) {
    printf("Found: %d\n", searched->data);
  } else {
    printf("Not found\n");
  }

  return 0;
}