#include <stdio.h>
int binarySearch(int a[], int left, int right, int value);

int main()
{
    int testCase;
    scanf("%d", &testCase);
    for (int i=0; i<testCase; i++)
    {
        int n, K;
        scanf("%d %d", &n, &K);
        int arr[n];
        for (int j=0; j<n; j++)
        {
            scanf("%d", &arr[j]);
        }
        printf("%d\n", binarySearch(arr, 0, n, K));
    }
}

int binarySearch(int a[], int left, int right, int value)
{
    int mid;

    if (left > right)
        return -1;
    else
    {
        mid = (left+right)/2;

        if (a[mid] == value)
            return mid;
        else if (a[mid] > value)
            return binarySearch(a, left, mid-1, value);
        else
            return binarySearch(a, mid+1, right, value);
    }
}
