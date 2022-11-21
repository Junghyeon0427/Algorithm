#include <stdio.h>

void backtracking(int row, int n, int result[]);

bool flag = true;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        int n;
        scanf("%d", &n);
        int* result = new int[n];
        backtracking(0, n, result);
        flag = true;
        delete[] result;
    }
    return 0;
}

bool Check(int row, int col, int result[])
{
    for (int i=0; i<row; i++)
    {
        if(result[i] == col+1)
            return false;
        if(result[i]-i == col-row+1)
            return false;
        if(result[i]-col == row-i+1)
            return false;
    }
    return true;
}

void backtracking(int row, int n, int result[])
{
    if (row == n)
    {
        for(int i=0; i<n; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
        flag = false;

    }
    for(int i=0; i<n; i++)
    {
        /// 첫번째 경우만 출력하고 이후의 경우는 세지 않음
        if (flag == false)
            break;
        if(Check(row, i, result))
        {
            result[row] = i+1;
            backtracking(row+1, n, result);
        }

    }
    return;
}
