// Checking if a binary tree is a perfect binary tree in C

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

// Creating a new node
struct node *newnode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

// Calculate the depth
int depth(struct node *node) {
  int d = 0;
  while (node != NULL) {
    d++;
    node = node->left;
  }
  return d;
}

// Count the number of nodes
int countNumNodes(struct node *root) {
  if (root == NULL)
    return (0);
  return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

// Check if the tree is perfect
bool is_perfect(struct node *root, int d, int level) {
    // Check if the tree is empty
  if (root == NULL)
    return true;

  // Check the presence of children
  if (root->left == NULL && root->right == NULL)
    return (d == level + 1);

  if (root->left == NULL || root->right == NULL)
    return false;

  return is_perfect(root->left, d, level + 1) &&
       is_perfect(root->right, d, level + 1);
}
// Check for height balance
bool checkHeightBalance(struct node *root, int *height) {
  // Check for emptiness
  int leftHeight = 0, rightHeight = 0;
  int l = 0, r = 0;

  if (root == NULL) {
    *height = 0;
    return 1;
  }

  l = checkHeightBalance(root->left, &leftHeight);
  r = checkHeightBalance(root->right, &rightHeight);

  *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

  if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2))
    return 0;

  else
    return l && r;
}
// Check for Full balance
bool isFullBinaryTree(struct node *root) {
  // Checking tree emptiness
  if (root == NULL)
    return true;

  // Checking the presence of children
  if (root->left == NULL && root->right == NULL)
    return true;

  if ((root->left) && (root->right))
    return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

  return false;
}

// Check if the tree is a complete binary tree
bool checkComplete(struct node *root, int index, int numberNodes) {
  // Check if the tree is complete
  if (root == NULL)
    return true;

  if (index >= numberNodes)
    return false;

  return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
}

// Wrapper function
bool is_Perfect(struct node *root) {
  int d = depth(root);
  return is_perfect(root, d, 0);
}

void displayPerfect(struct node *root) {
  if (is_Perfect(root))
    printf("The tree is a perfect binary tree\n");
  else
    printf("The tree is not a perfect binary tree\n");
}

void displayBalanced(struct node *root){
	int height = 0;

	
	if (checkHeightBalance(root, &height))
	   printf("The tree is balanced");
	else
	   printf("The tree is not balanced");
}

void displayFull(struct node *root){
  	if (isFullBinaryTree(root))
    	printf("The tree is a full binary tree\n");
  	else
    	printf("The tree is not a full binary tree\n");
}

void displayComplate(struct node *root){
	int node_count = countNumNodes(root);
  	int index = 0;
  	if (checkComplete(root, index, node_count))
    	printf("The tree is a complete binary tree\n");
  	else
    	printf("The tree is not a complete binary tree\n");
}


int main() {
	struct node *root = NULL;
  	root = newnode(1);
  	root->left = newnode(2);
  	root->right = newnode(3);

  	root->left->left = newnode(4);
  	root->left->right = newnode(5);
  	root->left->right->left = newnode(6);
  	root->left->right->right = newnode(7);
  	
	printf("=========Perfect Binary Tree ===========\n");
  	displayPerfect(root);
	
	printf("\n=========Perfect Balanced Tree ===========\n");
	displayBalanced(root);
	
	printf("\n\n=========Perfect Full Tree ===========\n");
	displayFull(root);
	
	printf("\n\n=========Complete Tree ===========\n");
	displayComplate(root);
}


