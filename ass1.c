#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

struct abc
{
    int data;
    struct abc* left;
    struct abc* right;
    struct abc* next; 
};
struct abc* top = NULL;

void push(struct abc* root)
{
    if(top == NULL)
    {
        top = root;
    }
    else
    {
        root->next = top;
        top = root;
    }
} 
struct abc* pop()
{
    struct abc* w;
    w = top;
    top = top->next;
    return w;
}
struct abc* create(char a)
{
    struct abc* temp = (struct abc*)malloc(sizeof(struct abc));
    temp->data = a;
    temp->left = temp->right = NULL;
    temp->next = NULL;
    return temp;
}
void inorder(struct abc* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}
void preorder(struct abc* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct abc* root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}
int main()
{
    struct abc* root, *p, *q;
    char a[50];
    int n;
    printf("Enter the number of characters in the expresstion:\n");
    scanf("%d", &n);
    printf("Enter the expression:\n");
    scanf("%s", a);
    for(int i=0; i<n; i++)
    {
        if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '^')
        {
            root = create(a[i]);
            p = pop();
            q = pop();
            root->right = p;
            root->left = q;
            push(root);
        }
        else
        {
            root = create(a[i]);
            push(root);
        }
    }
    printf("\nResult of inorder traversing:");
    inorder(root);
    printf("\nResult of preorder traversing:");
    preorder(root);
    printf("\nResult of postorder traversing:");
    postorder(root);
    printf("\n");
    return 0;
}