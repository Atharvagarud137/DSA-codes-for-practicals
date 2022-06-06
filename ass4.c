#include <stdio.h>
void prims(int, int[10][10]);
int main()
{
    int n, cost[10][10];
    printf("Enter number of vertices:\n");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    prims(n, cost);
    return 0;
}
void prims(int n, int cost[10][10])
{
    int min_cost = 0, min, e = 1, u = 1, v = 1, visited[10];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    visited[1] = 1;
    while (e < n)
    {
        for (int i = 0; i < n; i++)
        {
            min = 999;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (cost[i][j] < min)
                    {
                        if (visited[i] == 0)
                            continue;
                        else
                        {
                            min = cost[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
                if (visited[u] == 0 || visited[v] == 0)
                {
                    min_cost = min_cost + min;
                    printf("\n%d edge (%d, %d) and cost = %d\n", ++e, u, v, min);
                    visited[v] = 1;
                    printf("\n");
                }
                cost[u][v] = cost[v][u] = 999;
            }
        }
    }
    printf("\nCost of the MST = %d\n", min_cost);
}
