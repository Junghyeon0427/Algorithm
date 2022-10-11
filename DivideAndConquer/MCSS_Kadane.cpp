#include <stdio.h>
#define MAX_SIZE 100

void Kadane(int arr[], int length);

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
        Kadane(arr, n);
    }
}

void Kadane(int arr[], int length)
{
    int maxNum = -1000;
    int maxNumStart = 0;
    int maxNumEnd = 0;
    int maxNumIdxLength = length;
    int numIdx[length][2];
    int maxNumIdx[2];

    // 0번째 인덱스에서 가질 수 있는 최댓값의 시작과 끝 [0, 0]
    numIdx[0][0] = 0;
    numIdx[0][1] = 0;

    // 해당 인덱스에서 가질 수 있는 최댓값과 그 때의 인덱스의 시작과 끝을 기록
    for (int i=1; i<length; i++)
    {
        if(arr[i] < arr[i]+arr[i-1])
            arr[i] = arr[i]+arr[i-1];
        else
            maxNumStart = i;
        maxNumEnd = i;
        numIdx[i][0] = maxNumStart;
        numIdx[i][1] = maxNumEnd;
    }

    for (int i=0; i<length; i++)
    {
        if (arr[i] > maxNum)
        {
            maxNum = arr[i];
        }
    }

    if (maxNum <= 0)
        printf("%d %d %d", 0, -1 ,-1);

    else
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == maxNum)
            {
                maxNumIdx[0] = numIdx[i][0];
                maxNumIdx[1] = numIdx[i][1];
                break;
            }
        }

        printf("%d %d %d", maxNum, maxNumIdx[0], maxNumIdx[1]);
    }
    printf("\n");
}
