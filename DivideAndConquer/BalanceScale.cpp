#include <stdio.h>
#include <stdlib.h>

void getWeight(int arr[], int n);

int main() {
    int testCase;
    scanf("%d", &testCase);
    for (int i = 0; i < testCase; i++)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }
        getWeight(arr, n);
        printf("\n");
    }
    return 0;
}

void getWeight(int arr[], int n)
{
    int cnt = 0;
    int leftSum = 0;
    int rightSum = 0;

    int choo[7] = {100, 50, 20, 10, 5, 2, 1};

    leftSum += arr[0];
    rightSum += arr[1];
    for (int i=2; i<n; i++)
    {
        if (leftSum == rightSum)
        {
            leftSum += arr[i];
        }
        else if (leftSum > rightSum)
        {
            rightSum += arr[i];
        }
        else
        {
            leftSum += arr[i];
        }
    }
    int diff = abs(leftSum - rightSum);

    for (int i=0; i<7; i++)
    {
        if (choo[i] > diff)
            continue;

        while (diff >= choo[i])
        {
            diff -= choo[i];
            cnt++;
        }
    }
    if (diff == 0)
        printf("%d", cnt);
    else
        printf(0);
}
