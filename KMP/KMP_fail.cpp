#include <iostream>
#define MAX_SIZE 1001

using namespace std;

int* f;
int result;

int kmp(char *text, char *pattern);
int getFail(char *pattern, int length);
int getLength(char *str);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char pattern[MAX_SIZE];
        char text[MAX_SIZE];
        cin >> pattern >> text;

        int pattern_length = 0;
        pattern_length = getLength(pattern);

        f = new int[pattern_length]();

        result = 0;

        getFail(pattern, pattern_length);
        kmp(text, pattern);

        for(int i=0; i<pattern_length; i++)
        {
            cout << f[i] << " ";
        }
        cout << '\n';

        cout << result << '\n';
    }
}

int getFail(char *pattern, int pattern_length)
{
    int j = 0;

    for(int i=1; i<pattern_length; i++)
    {
        while(j>0 && pattern[i] != pattern[j])
        {
            j = f[j-1];
        }
        if (pattern[i] == pattern[j])
        {
            f[i] = ++j;
        }
    }
    return 0;
}

int kmp(char *text, char *pattern)
{
    int n = getLength(text);
    int m = getLength(pattern);
    int j = 0;

    for (int i=0; i<n; i++)
    {
        while(j>0 && text[i] != pattern[j])
        {
            j = f[j-1];
        }
        if (text[i] == pattern[j])
        {
            if (j == m-1)
            {
                result++;
                j = f[j];
            }
            else
                j++;
        }
    }
    return 0;
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
