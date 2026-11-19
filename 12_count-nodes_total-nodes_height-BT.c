Algorithm:
COUNT_NODES(node):
1. If node = NULL, return 0
2. Return 1 + COUNT_NODES(node->left) + COUNT_NODES(node->right)
COUNT_LEAF(node):
1. If node = NULL, return 0
2. If node->left = NULL and node->right = NULL, return 1
3. Return COUNT_LEAF(node->left) + COUNT_LEAF(node->right)
HEIGHT(node):
1. If node = NULL, return -1 (or 0, depending on convention)
2. Return 1 + max(HEIGHT(node->left), HEIGHT(node->right))
Program:
/* Practical 12: Count total nodes, leaf nodes and height of Binary Tree (CO2) */
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
 
/* Function to Create Binary Tree (-1 = NULL) */
struct Node *createTree()
{
    int value;
    struct Node *newNode;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &value);
 
    if (value == -1)
        return NULL;
    newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
 
    printf("Enter left child of %d\n", value);
    newNode->left = createTree();
 
    printf("Enter right child of %d\n", value);
    newNode->right = createTree();
 
    return newNode;
}
 
/* Function to Count Total Nodes */
int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
 
/* Function to Count Leaf Nodes */
int countLeaf(struct Node *root)
{
    if (root == NULL)
        return 0;
 
    if (root->left == NULL && root->right == NULL)
        return 1;
 
    return countLeaf(root->left) + countLeaf(root->right);
}
 
/* Function to Find Height */
int height(struct Node *root)
{
    int leftHeight, rightHeight;
 
    if (root == NULL)
        return 0;
 
    leftHeight = height(root->left);
    rightHeight = height(root->right);
 
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}
 
int main()
{
    struct Node *root = NULL;
 
    printf("Create Binary Tree\n");
    root = createTree();
 
    printf("\nTotal Nodes = %d", countNodes(root));
    printf("\nLeaf Nodes = %d", countLeaf(root));
    printf("\nHeight of Tree = %d\n", height(root));
 
    return 0;
}
