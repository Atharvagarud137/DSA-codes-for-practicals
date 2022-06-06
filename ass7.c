#include <stdio.h>
int a[10], min, max;

void minmax(int i, int j)
{
    if(i==j)
    {
        min = max = a[i];
    }
    else if(i==j-1)
    {
        if(a[i] > a[j])
        {
            min = a[j];
            max = a[i];
        }
        else
        {
            min = a[i];
            max = a[j];
        }
    }
    else
    {
        int mid = (i+j)/2;
        minmax(i, mid);
        int min1 = min;
        int max1 = max;
        minmax(mid+1, j);
        if(max<max1)
        {
            max = max1; 
        }
        if(min>min1)
        {
            min = min1;
        }
    }
}

int main()
{
    int n;
    printf("Enter number of elements in array:\n");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    minmax(0,n-1);
    printf("\nMinimum element is: %d and Maximum element is: %d\n", min, max);
    return 0;
}