#include<stdio.h>
#define MIN(a, b) ((a) < (b) ? (a):(b))

int MatrixChain(int p[], int i, int j);

int mem[101][101];
int INF = 1000000007;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int n;
        scanf("%d", &n);
        int arr[101];
        for (int j=0; j<=n; j++)
        {
            scanf("%d", &arr[j]);
        }
        for(int k=0; k<=n; k++)
        {
            for(int w=0; w<=n; w++)
            {
                mem[k][w] = -1;
            }
        }
        // arr : 0, 1, ..., n
        printf("%d\n", MatrixChain(arr, 1, n));
    }
}

int MatrixChain(int p[], int i, int j)
{
    if (i == j)
        return 0;
    if (mem[i][j] != -1)
        return mem[i][j];
    mem[i][j] = INF;
    for (int k = i; k < j; k++)
    {
        mem[i][j] = MIN(mem[i][j], MatrixChain(p, i, k) + MatrixChain(p, k+1, j) + p[i-1] * p[k] * p[j]);
    }
    return mem[i][j];
}