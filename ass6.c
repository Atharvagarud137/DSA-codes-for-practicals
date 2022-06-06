#include <stdio.h>
int size = 0;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(int a[], int i, int size)
{
    int largest;
    largest = i;
    int left, right;
    left = 2*i + 1;
    right = 2*i + 2;
    if(left < size && a[left] > a[largest])
    {
        largest = left;
    }
    if(right < size && a[right] > a[largest])
    {
        largest = right;
    }
    if(i != largest)
    {
        swap(&a[i], &a[largest]);
        for(int i=size/2 - 1; i>=0; i--)
        {
            heapify(a, i, size);
        }
    }
}
void insert(int a[], int num)
{
    if(size == 0)
    {
        a[size] = num;
        size++;
    }
    else
    {
        a[size] = num;
        size++;
        for(int i=size/2 - 1; i >= 0; i--)
        {
            heapify(a, i, size);
        }
    }
}
void delete(int a[])
{
    int i=0;
    swap(&a[i], &a[size-1]);
    size=size-1;
    for(int i=size/2 - 1; i >= 0; i--)
    {
        heapify(a, i, size);
    }
}
void display(int a[])
{
    for(int i=0; i<size; i++)
    {
        printf("%d ",a[i]); 
    }
    printf("\n");
}

int main()
{
    int a[10];
    insert(a, 5);
    insert(a, 3);
    insert(a, 2);
    insert(a, 10);
    insert(a, 8);
    printf("\n");
    printf("Max heaap of the array is:\n");
    display(a);
    printf("\n");
    delete(a);
    printf("Max heap after deleting is:\n");
    display(a);
    printf("\n");
    delete(a);
    printf("Max heap after deleting is:\n");
    display(a);
    printf("\n");
    delete(a);
    printf("Max heap after deleting is:\n");
    display(a);
    printf("\n");
    return 0;
}