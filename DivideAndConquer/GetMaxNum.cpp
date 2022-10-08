#include <stdio.h>
#define MAX_SIZE 100
#define MAX(a,b) ((a)>(b)?(a):(b))

int recurMax(int a[], int left, int right);

int main()
{
    int testCase;
    scanf("%d", &testCase);
    for (int i=0; i<testCase; i++)
    {
        int n;
        scanf("%d", &n);
        int arr[MAX_SIZE];
        for (int j=0; j<n; j++)
        {
            scanf("%d", &arr[j]);
        }
        printf("%d", recurMax(arr, 0, n-1));
        printf("\n");
    }
}

int recurMax(int a[], int left, int right)
{
    int half;

    if (left == right)
    {
        return a[left];
    }
    else
    {
        half = (left+right) / 2;
        return MAX(recurMax(a, left, half), recurMax(a, half+1, right));
    }
}
