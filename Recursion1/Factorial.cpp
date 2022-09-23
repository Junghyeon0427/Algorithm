#include <stdio.h>
int factorial(int n);
int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        scanf("%d", &num);
        printf("%d", factorial(num));
        printf("\n");
    }
    return 0;
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    else
    {
        int tmp = n * factorial(n-1);
        while (tmp % 10 == 0)
        {
            tmp = tmp / 10;
        }

        return tmp % 1000;
    }
}
