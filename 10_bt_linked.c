Algorithm:
INSERT(VALUE) — Level-order:
1. Start
2. Create a new node storing VALUE
3. If root is NULL, set root = new node and stop
4. Else, enqueue root into an auxiliary queue
5. While queue is not empty: dequeue a node; if its left child is NULL, attach the new node there and stop; else enqueue the left child; if its right child is NULL, attach the new node there and stop; else enqueue the right child
6. Stop
Program:
/* Practical 10: Binary Tree using Linked List (CO2) */
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
 
/* Function to create Binary Tree recursively (-1 = NULL) */
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
 
    printf("Create Binary Tree\n");
    root = createTree();
 
    printf("\nInorder Traversal : ");
    inorder(root);
    printf("\n");
 
    return 0;
}
