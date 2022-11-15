#include <iostream>
#define MAX_LENGTH 110
#define MIN(a, b) ((a) < (b) ? (a):(b))

using namespace std;

int MatrixChain(int arr[], int num);
void order(int i, int j);
int INF = 1000000007;

int P[MAX_LENGTH][MAX_LENGTH];

int main()
{
    int t;
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int num, n;
        cin >> num;
        int arr[num+1];
        for (int j=0; j<=num; j++)
        {
            cin >> n;
            arr[j] = n;
        }
        int answer = MatrixChain(arr, num);
        order(1, num);
        cout << '\n';
        cout << answer << '\n';
    }
}

int MatrixChain(int arr[], int num)
{
    int M[MAX_LENGTH][MAX_LENGTH];

    for (int diag=0; diag<num; diag++)
    {
        for (int i=1; i<=num-diag; i++)
        {
            int j = i + diag;
            if (j == i)
            {
                M[i][j] = 0;
                continue;
            }
            M[i][j] = INF;
            for (int k=i; k<=j-1; k++)
            {
                if(M[i][j] > M[i][k] + M[k+1][j] + arr[i-1] * arr[k] * arr[j])
                {
                    M[i][j] = M[i][k] + M[k+1][j] + arr[i-1] * arr[k] * arr[j];
                    P[i][j] = k;
                }
            }
        }
    }
    return M[1][num];
}

void order(int i, int j)
{
    if (i == j)
        cout << "M" << i;
    else
    {
        int k = P[i][j];
        cout << "(";
        order(i, k);
        order(k+1, j);
        cout << ")";
    }
}