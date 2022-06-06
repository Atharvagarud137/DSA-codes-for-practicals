#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
	float x[20], tp = 0;
	int i, j, u;
	u = capacity;
	for (i = 0; i < n; i++)
	{
		x[i] = 0.0;
	}
	for (i = 0; i < n; i++)
	{
		if (weight[i] > u)
			break;
		else
		{
			x[i] = 1.0;
			tp = tp + profit[i];
			u = u - weight[i];
		}
	}

	if (i < n)
		x[i] = u / weight[i];

	tp = tp + (x[i] * profit[i]);

	for (i = 0; i < n; i++)
		printf("%f\t", x[i]);

	printf("\nMaximum profit is:- %f \n", tp);
}

void knapsack_p(int n, float w[], float p[], float capacity)
{
	int i, j;
	float u, x[20], temp = 0, tp = 0;
	for (i = 0; i < n; i++)
		x[i] = 0;
	u = capacity;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (p[i] < p[j])
			{
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
				temp = w[j];
				w[j] = w[i];
				w[i] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (w[i] > u)
			break;

		x[i] = 1;
		tp += p[i];
		u = u - w[i];
	}

	if (i < n)
	{
		x[i] = u / w[i];
		tp = tp + p[i] * x[i];
	}
	printf("Profit based on profit is: %f\n", tp);
}

void knapsack_w(int n, float w[], float p[], float capacity)
{
	int i, j;
	float u, x[20], temp = 0, tp = 0;
	for (i = 0; i < n; i++)
		x[i] = 0;
	u = capacity;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (w[i] > w[j])
			{
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
				temp = w[j];
				w[j] = w[i];
				w[i] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (w[i] > u)
			break;

		x[i] = 1;
		tp += p[i];
		u = u - w[i];
	}

	if (i < n)
	{
		x[i] = u / w[i];
		p[i] = p[i] * x[i];
		tp = tp + p[i];
	}
	printf("Profit based on weight is: %f\n", tp);
}

int main()
{
	float weight[20], profit[20], capacity;
	int num, i, j;
	float ratio[20], temp;

	printf("\nEnter the no. of objects:- ");
	scanf("%d", &num);

	printf("\nEnter the wts and profits of each object:- ");
	for (i = 0; i < num; i++)
	{
		scanf("%f %f", &weight[i], &profit[i]);
	}

	printf("\nEnter the capacity of knapsack:- ");
	scanf("%f", &capacity);

	for (i = 0; i < num; i++)
	{
		ratio[i] = profit[i] / weight[i];
	}

	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (ratio[i] < ratio[j])
			{
				temp = ratio[j];
				ratio[j] = ratio[i];
				ratio[i] = temp;

				temp = weight[j];
				weight[j] = weight[i];
				weight[i] = temp;

				temp = profit[j];
				profit[j] = profit[i];
				profit[i] = temp;
			}
		}
	}

	knapsack(num, weight, profit, capacity);
	knapsack_p(num, weight, profit, capacity);
	knapsack_w(num, weight, profit, capacity);
	return (0);
}
