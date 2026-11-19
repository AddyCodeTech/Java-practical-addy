Algorithm:
SEARCH(node, value):
1. Start
2. If node = NULL, return "Not Found"
3. If value = node->data, return "Found"
4. If value < node->data, return SEARCH(node->left, value)
5. Else, return SEARCH(node->right, value)
6. Stop
Program:
/* Practical 14: Searching in Binary Search Tree (CO2) */
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
 
/* Create New Node */
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
 
/* Insert into BST */
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);
 
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
 
    return root;
}
 
/* Search in BST */
struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
 
    if (key < root->data)
        return search(root->left, key);
 
    return search(root->right, key);
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
    struct Node *result;
    int n, i, value, key;
 
    printf("Enter number of nodes: ");
    scanf("%d", &n);
 
    printf("Enter BST elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }
 
    printf("\nBST (Inorder Traversal): ");
    inorder(root);
 
    printf("\n\nEnter element to search: ");
    scanf("%d", &key);
 
    result = search(root, key);
 
    if (result != NULL)
        printf("%d found in the Binary Search Tree.\n", key);
    else
        printf("%d not found in the Binary Search Tree.\n", key);
 
    return 0;
}
