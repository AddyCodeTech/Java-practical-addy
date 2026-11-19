Algorithm:
PREORDER(node):
1. If node = NULL, return
2. Visit/print node->data
3. PREORDER(node->left)
4. PREORDER(node->right)
INORDER(node):
1. If node = NULL, return
2. INORDER(node->left)
3. Visit/print node->data
4. INORDER(node->right)
POSTORDER(node):
1. If node = NULL, return
2. POSTORDER(node->left)
3. POSTORDER(node->right)
4. Visit/print node->data
Program:
/* Practical 11: Preorder, Inorder and Postorder Traversal of Binary Tree (CO2) */
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
 
/* Preorder Traversal */
void preorder(struct Node *root)
{
    if (root == NULL)
        return;
 
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
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
 
/* Postorder Traversal */
void postorder(struct Node *root)
{
    if (root == NULL)
        return;
 
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
 
int main()
{
    struct Node *root = NULL;
 
    printf("Create Binary Tree\n");
    root = createTree();
 
    printf("\nPreorder Traversal : ");
    preorder(root);
 
    printf("\nInorder Traversal : ");
    inorder(root);
 
    printf("\nPostorder Traversal : ");
    postorder(root);
    printf("\n");
 
    return 0;
}
