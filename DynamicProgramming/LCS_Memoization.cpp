#include<stdio.h>
#include<iostream>

using namespace std;

#define MAX(a, b) ((a) > (b) ? (a):(b))

int getLength(char *str);
int LCS(char s[], char t[], int m, int n, int** mem);

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++)
    {
        char s[101];
        char t[101];
        scanf("%s %s", s, t);
        int m = getLength(s);
        int n = getLength(t);
        int** mem = new int*[m];
        for (int j=0; j<m; j++)
        {
            mem[j] = new int[n];
        }
        for(int i = 0; i<getLength(s) ;i++)
        {
            for(int j = 0; j<getLength(t) ;j++)
            {
                mem[i][j] = -1;
            }
        }
        printf("%d", LCS(s, t, m, n, mem));
        printf("\n");
        for(int j=0; j<m; j++)
            delete[] mem[j];
        delete[] mem;
    }
}

int getLength(char *str)
{
    int length = 0;
    while (*(str+length) != '\0')
    {
        length++;
    }
    return length;
}

int LCS(char s[], char t[], int m, int n, int** mem)
{
    if (m == 0 | n == 0)
        return 0;
    if  (mem[m-1][n-1] != -1)
    {
        return mem[m-1][n-1];
    }

    else if (s[m-1] == t[n-1])
    {
        mem[m-1][n-1] = 1 + LCS(s, t, m-1, n-1, mem);
        return mem[m-1][n-1];
    }
    else
    {
        int a = LCS(s, t, m-1, n, mem);
        int b = LCS(s, t, m, n-1, mem);
        mem[m-1][n-1] = MAX(a, b);
        return mem[m-1][n-1];
    }
}
