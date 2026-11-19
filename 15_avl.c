Algorithm:
INSERT(node, value):
1. Perform standard BST insertion of value
2. Update the height of node
3. Compute balance factor = height(node->left) - height(node->right)
4. If balance > 1 and value < node->left->data → perform Right Rotation (LL case)
5. If balance < -1 and value > node->right->data → perform Left Rotation (RR case)
6. If balance > 1 and value > node->left->data → Left-Rotate the left child, then Right-Rotate node (LR case)
7. If balance < -1 and value < node->right->data → Right-Rotate the right child, then Left-Rotate node (RL case)
8. Return the (possibly new) root of this subtree
Program:
/* Practical 15: AVL Tree (CO2) */
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};
 
/* Function to get height */
int getHeight(struct Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}
 
/* Maximum of two numbers */
int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
/* Create new node */
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
 
/* Right Rotation */
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
 
    return x;
}
 
/* Left Rotation */
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
 
    return y;
}
 
/* Balance Factor */
int getBalance(struct Node *node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}
 
/* Insert Node */
struct Node *insert(struct Node *node, int value)
{
    int balance;
 
    if (node == NULL)
        return createNode(value);
 
    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;
 
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
 
    balance = getBalance(node);
 
    /* LL Rotation */
    if (balance > 1 && value < node->left->data)
        return rightRotate(node);
 
    /* RR Rotation */
    if (balance < -1 && value > node->right->data)
        return leftRotate(node);
 
    /* LR Rotation */
    if (balance > 1 && value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    /* RL Rotation */
    if (balance < -1 && value < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}
 
/* Inorder Traversal */
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main()
{
    struct Node *root = NULL;
    int n, i, value;
 
    printf("Enter number of nodes: ");
    scanf("%d", &n);
 
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("\nInorder Traversal of AVL Tree:\n");
    inorder(root);
    printf("\n");
    return 0;
}
