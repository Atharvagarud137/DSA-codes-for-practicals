#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node* left, *right;
};
struct node* newnode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
void preorder(struct node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}
struct node* insert(struct node* node, int key)
{
    if(node == NULL)
    {
        return newnode(key);
    }
    else if(key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else
    {
        node->right = insert(node->right, key);
    }
    return node;
}
struct node* minvalue(struct node* node)
{
    struct node* current = node;
    while(current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
struct node* delete(struct node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }
    else if(key < root->key)
    {
        root->left = delete(root->left, key);
    }
    else if(key > root->key)
    {
        root->right = delete(root->right, key);
    }
    else
    {
        if(root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minvalue(root->right);
        root->key = temp->key;
        root->right = delete(root->right, temp->key);
    }
    return root;
}
int main()
{
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 70);
    root = insert(root, 80);
    printf("\nInorder traversal of the given tree:\n");
    inorder(root);
    printf("\nPreorder traversal of the givern tree:\n");
    preorder(root);
    printf("\nPostorder traversal of the given tree:\n");
    postorder(root);
    printf("\nDelete 20\n");
    root = delete(root, 20);
    printf("\nInorder traversal of the modified tree:\n");
    inorder(root);
    printf("\nPreorder traversal of the modified tree:\n");
    preorder(root);
    printf("\nPostorder traversal of the modified tree:\n");
    postorder(root);
    printf("\nDelete 30\n");
    root = delete(root, 30);
    printf("\nInorder traversal of the modified tree:\n");
    inorder(root);
    printf("\nPreorder traversal of the modified tree:\n");
    preorder(root);
    printf("\nPostorder traversal of the modified tree:\n");
    postorder(root);
    printf("\nDelete 50\n");
    root = delete(root, 50);
    printf("\nInorder traversal of the modified tree:\n");
    inorder(root);
    printf("\nPreorder traversal of the modified tree:\n");
    preorder(root);
    printf("\nPostorder traversal of the modified tree:\n");
    postorder(root);
    return 0;
}