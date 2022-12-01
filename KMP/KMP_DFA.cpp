#include <iostream>
#define MAX_SIZE 1001

using namespace std;

int num1, num2;
int DFA[301][MAX_SIZE];
char pattern[MAX_SIZE], text[MAX_SIZE];

int constructDFA();
int KMP(int length);
int getLength(char *str);

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> pattern >> text;;
        num1 = constructDFA();
        num2 = KMP(getLength(pattern));
        cout << num1 << " " << num2 << '\n';
    }
}
int constructDFA()
{
    int X, j, num=0;
    int length = getLength(pattern);
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<=length; j++)
        {
            DFA[i][j] = 0;
        }
    }
    DFA[pattern[0]-65][0] = 1;
    for (X=0, j=1; j<length; j++)
    {
        for (int k=0; k<3; k++)
            DFA[k][j] = DFA[k][X];

        DFA[pattern[j]-65][j] = j + 1;
        X = DFA[pattern[j]-65][X];
    }
    for (int k=0; k<3; k++)
        DFA[k][j] = DFA[k][X];

    for (int i=0; i<3; i++)
    {
        for (int j=0; j<=length; j++)
        {
            if (DFA[i][j] != 0)
                num++;
        }
    }
    return num;
}
int KMP(int length)
{
    int i, j, textLength, num2=0;
    textLength = getLength(text);
    for (i=0, j=0; i<textLength; i++)
    {
        j = DFA[text[i]-65][j];
        if (j == length)
        {
            num2++;
        }
    }
    return num2;
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
