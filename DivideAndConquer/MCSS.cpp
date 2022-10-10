#include <stdio.h>
#define MAX_SIZE 100
int max(int a, int b) { return (a > b) ? a : b; }
int max(int a, int b, int c) { return max(max(a, b), c); }

int maxCombine(int arr[], int left, int mid, int right)
{
    int sum = 0;
    int leftSum = 0;
    int rightSum = 0;

    for (int i = mid; i >= left; i--)
    {
        sum = sum + arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }

    sum = 0;
    for (int i = mid; i <= right; i++)
    {
        sum = sum + arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }
    if (leftSum == 0 and rightSum == 0)
        return 0;
    return max(leftSum + rightSum - arr[mid], leftSum, rightSum);
}

int maxSubArray(int arr[], int left, int right)
{
    if (left > right)
        return 0;

    if (left == right)
        return arr[left];

    int mid = (left + right) / 2;

    return max(maxSubArray(arr, left, mid-1),
               maxSubArray(arr, mid+1, right),
               maxCombine(arr, left, mid, right));
}

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
        printf("%d\n", maxSubArray(arr, 0, n-1));
    }
}
