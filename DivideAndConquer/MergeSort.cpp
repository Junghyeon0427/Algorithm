#include <stdio.h>
#define MAX_SIZE 100
void merge(int a[], int low, int mid, int high);
void mergeSort(int v[], int low, int high);

int count = 0;

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
        mergeSort(arr, 0, n-1);
        printf("%d\n", count);
        count = 0;
    }
}

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int tmp[MAX_SIZE];

    for (i=low; i<=high; i++)
        tmp[i] = a[i];

    i = k = low;
    j = mid+1;

    while (i<=mid && j<=high)
    {
        count++;
        if (tmp[i] <= tmp[j]) {
            a[k++] = tmp[i++];
        } else
            a[k++] = tmp[j++];
    }
    while (i<=mid)
        a[k++] = tmp[i++];
    while (j<=high)
        a[k++] = tmp[j++];
}

void mergeSort(int v[], int low, int high)
{
    int mid;

    if (low == high)
        return;
    mid = (low + high) / 2;

    mergeSort(v, low, mid);
    mergeSort(v, mid+1, high);
    merge(v, low, mid, high);
}
