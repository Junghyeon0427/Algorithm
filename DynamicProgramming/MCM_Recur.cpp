#include<stdio.h>

#define MAX_LENGTH 11
#define MIN(a, b) ((a) < (b) ? (a):(b))

int MatrixChain(int p[], int i, int j);
int INF = 1000000007;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int n;
        scanf("%d", &n);
        int arr[MAX_LENGTH];
        for (int j=0; j<=n; j++)
        {
            scanf("%d", &arr[j]);
        }
        // arr : 0, 1, ..., n
        printf("%d\n", MatrixChain(arr, 1, n));
    }
}

int MatrixChain(int arr[], int i, int j)
{
    if (i == j)
        return 0;

    int k;
    int min = INF;
    int count;

    for (k = i; k < j; k++)
    {
        count = MatrixChain(arr, i, k) + MatrixChain(arr, k + 1, j) + arr[i-1] * arr[k] * arr[j];
        min = MIN(min, count);
    }

    return min;
}