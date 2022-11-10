#include<stdio.h>
#define MAX_LENGTH 101
#define MAX(a, b) ((a) > (b) ? (a):(b))

int getLength(char *str);
int lengthLCS(char s[], char t[], int m, int n);
void printLCS(char s[], char t[], int m, int n);
int L[MAX_LENGTH][MAX_LENGTH], S[MAX_LENGTH][MAX_LENGTH];

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
        printf("%d ", lengthLCS(s, t, m, n));
        printLCS(s, t, m, n);
        printf("\n");
    }
}

int lengthLCS(char s[], char t[], int m, int n)
{
    int i, j;
    for(i = 0; i <= m; i++)
        L[i][0] = 0;
    for(i = 0; i <= n; i++)
        L[0][i] = 0;
    for(i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
                S[i][j] = 0;
            }
            else
            {
                L[i][j] = MAX(L[i][j - 1], L[i - 1][j]);
                if (L[i][j] == L[i][j - 1])
                    S[i][j] = 1;
                else
                    S[i][j] = 2;
            }
        }
    }
    return L[m][n];
}

void printLCS(char s[], char t[], int m, int n)
{
    if(m==0 || n==0)
        return;
    if(S[m][n] == 0)
    {
        printLCS(s, t, m-1, n-1);
        printf("%c", s[m-1]);
    }
    else if(S[m][n] == 1)
        printLCS(s, t, m, n-1);
    else if(S[m][n] == 2)
        printLCS(s, t, m-1, n);
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
