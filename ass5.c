#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10

struct abc
{
    char name[20];
    char ph[20];
    struct abc* next;
};

struct abc* head[size], *p;

int hashcode(char ph[])
{
    int l = strlen(ph);
    int n = atoi(ph+l-1);
    return n;
}
void insert(char name[], char ph[])
{
    struct abc* temp;
    temp = (struct abc*)malloc(sizeof(struct abc));
    strcpy(temp->name, name);
    strcpy(temp->ph, ph);
    temp->next = NULL;
    int a = hashcode(ph);
    printf("%d", a);
    if(head[a] == NULL)
    {
        head[a] = temp;
    }
    else
    {
        p = head[a];
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
void display()
{
    for(int i=0; i<size; i++)
    {
        p = head[i];
        while((p) != NULL)
        {
            printf("|%d", i);
            printf("Name: %s\nPhone number: %s\n\n", p->name, p->ph);
            p = p->next;
        }
    }
}

int main()
{
    char name[20], ph[20];
    int ch;
    do
    {
        printf("Enter name:\n");
        scanf("%s", name);
        printf("Enter phone number:\n");
        scanf("%s", ph);
        printf("Enter your choice:\n");
        scanf("%d", &ch);
    } while (ch==1);
    display();
    return 0;
    
}