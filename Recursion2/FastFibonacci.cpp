#include <stdio.h>

void matMul(int fib[2][2], int matrix[2][2]);
void power(int fib[2][2], int n);
int fibMat(int n);

int main()
{
    int numTestCase;
    scanf("%d", &numTestCase);
    for (int i = 0; i < numTestCase; i++)
    {
        int n;
        scanf("%d", &n);
        printf("%d", fibMat(n));
        printf("\n");
    }
}

void matMul(int fib[2][2], int matrix[2][2])
{
    int x = fib[0][0] * matrix[0][0] + fib[0][1] * matrix[1][0];
    int y = fib[0][0] * matrix[0][1] + fib[0][1] * matrix[1][1];
    int z = fib[1][0] * matrix[0][0] + fib[1][1] * matrix[1][0];
    int w = fib[1][0] * matrix[0][1] + fib[1][1] * matrix[1][1];

    fib[0][0] = x % 1000;
    fib[0][1] = y % 1000;
    fib[1][0] = z % 1000;
    fib[1][1] = w % 1000;
}

void power(int fib[2][2], int n)
{
    if (n == 0 or n == 1)
    {
        return;
    }
    int matrix[2][2] = {{1, 1}, {1, 0}};
    power(fib, n/2);
    matMul(fib, fib);
    if (n % 2 == 1)
    {
        matMul(fib, matrix);
    }
}

int fibMat(int n)
{
    int fib[2][2] = {{1, 1}, {1, 0}};
    if (n == 0)
    {
        return 0;
    }
    power(fib, n-1);

    return fib[0][0];
}
