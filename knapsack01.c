#include <stdio.h>


int max(int a, int b)
{
    return (a > b) ? a : b;
}


void printknapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	int K[n + 1][W + 1];
	
	for (i = 0; i <= n; i++)
	{
		for (w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
					K[i - 1][w - wt[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	
	int res = K[n][W];
	printf("MAX value obtained = %d\n", res);
	
	w = W;
	for (i = n; i > 0 && res > 0; i--)
	{
		if (res == K[i - 1][w])
			continue;	
		else
		{
		    printf("Item %d: Weight = %d , Value = %d\n", i,wt[i - 1],val[i - 1]);
			res = res - val[i - 1];
			w = w - wt[i - 1];
		}
	}
}


int main()
{
	int i,n;
	printf("Enter no. of items: ");
	scanf("%d",&n);
	int val[n],wt[n],W;
	
	printf("\nEnter weight and value of each item.\n");
	
	for(i=0;i<n;i++)
	{
	    printf("\nWeight & vlaue of item %d: ", i+1);
	    scanf("%d", &wt[i]);
	    scanf("%d", &val[i]);
	}
	printf("\nEnter MAX weight of Knapsack: ");
	scanf("%d",&W);
	
	printknapSack(W, wt, val, n);
	
	return 0;
}
