Algorithm:
INSERT(node, value):
1. If node = NULL, create a new node with value and return it
2. If value < node->data, node->left = INSERT(node->left, value)
3. Else, node->right = INSERT(node->right, value)
4. Return node
DELETE(node, value):
1. If node = NULL, return NULL
2. If value < node->data, recurse left; if value > node->data, recurse right
3. On match: if node is a leaf, delete it directly
4. If node has one child, replace node with that child
5. If node has two children, find the inorder successor (smallest value in right subtree), copy its value into node, then recursively delete the successor from the right subtree
6. Return node
Program:
/* Practical 13: Binary Search Tree - Insertion, Searching and Deletion (CO2) */
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
 
/* Insert Node */
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
 
/* Search Node */
struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
 
    if (key < root->data)
        return search(root->left, key);
 
    return search(root->right, key);
}
 
/* Find Minimum Node */
struct Node *findMin(struct Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}
 
/* Delete Node */
struct Node *deleteNode(struct Node *root, int key)
{
    struct Node *temp;
 
    if (root == NULL)
        return NULL;
 
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        /* Node with no child */
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        /* Node with one child */
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
 
        /* Node with two children */
        temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
 
    return root;
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
    int choice, value;
 
    do
    {
        printf("\n******** BINARY SEARCH TREE MENU ********");
        printf("\n1. Insert");
        printf("\n2. Search");
        printf("\n3. Delete");
        printf("\n4. Display (Inorder)");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
 
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value))
                printf("%d Found in BST.\n", value);
            else
                printf("%d Not Found.\n", value);
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Deletion completed.\n");
            break;
        case 4:
            printf("\nBST (Inorder Traversal): ");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Program Terminated.\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }
    } while (choice != 5);
 
    return 0;
}
