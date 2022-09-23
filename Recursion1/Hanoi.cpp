#include <stdio.h>
void Hanoi(int n, int a, int b, int c);

int stack1[10];
int stack2[10];
int stack3[10];
int pointer1 = 0;
int pointer2 = 0;
int pointer3 = 0;

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int n;
        scanf("%d", &n);
        int tmp = n;
        pointer1 = n;
        for (int i = 0; i < n; i++)
        {
            stack1[i] = tmp;
            tmp--;
        }
        Hanoi(n, 1, 2, 3);
        printf("\n");
        pointer1 = 0;
        pointer2 = 0;
        pointer3 = 0;
    }
    return 0;
}

void Hanoi(int n, int a, int b, int c)
{
    if (n > 0)
    {
        Hanoi(n-1, a, c, b);
        if (a == 1)
        {
            if (c == 2)
            {
                pointer1--;
                stack2[pointer2] = stack1[pointer1];
                stack1[pointer1] = 0;
                pointer2++;
            }
            if (c == 3)
            {
                pointer1--;
                stack3[pointer3] = stack1[pointer1];
                stack1[pointer1] = 0;
                pointer3++;
            }
        }
        if (a == 2)
        {
            if (c == 1)
            {
                pointer2--;
                stack1[pointer1] = stack2[pointer2];
                stack2[pointer2] = 0;
                pointer1++;
            }
            if (c == 3)
            {
                pointer2--;
                stack3[pointer3] = stack2[pointer2];
                stack2[pointer2] = 0;
                pointer3++;
            }
        }
        if (a == 3)
        {
            if (c == 2)
            {
                pointer3--;
                stack2[pointer2] = stack3[pointer3];
                stack3[pointer3] = 0;
                pointer2++;
            }
            if (c == 1)
            {
                pointer3--;
                stack1[pointer1] = stack3[pointer3];
                stack3[pointer3] = 0;
                pointer1++;
            }
        }
        if (a == 3 or c == 3)
            printf("%d ", stack3[pointer3-1]);
        Hanoi(n-1, b, a, c);
    }
}