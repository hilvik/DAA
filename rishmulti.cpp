#include <iostream>
#include <climits>
#define max 1000
using namespace std;

string ans[max];
int gkay[max][max];

void update(int start, int end)
{
    if (end - start <= 1)
    {
        return;
    }
    int k = gkay[start][end];
    ans[start] = "(" + ans[start];
    ans[k] = ans[k] + ")";
    ans[k + 1] = "(" + ans[k + 1];
    ans[end] = ans[end] + ")";
    update(start, k);
    update(k + 1, end);
}

int main()
{
    cout << "Enter the number of matrices:";
    int n;
    cin >> n;
    cout << "Enter the order of matrices in sequence:";
    int r[n + 2];
    for (int i = 1; i <= n + 1; i++)
        cin >> r[i];
    int c[n + 1][n + 1];
    int kay[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = -1;
            kay[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        c[i][i] = 0;
        kay[i][i] = 0;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        c[i][i + 1] = r[i] * r[i + 1] * r[i + 2];
        kay[i][i + 1] = i;
    }
    int start = 1;
    int diff = 2;
    while (start + diff <= n)
    {
        for (int i = start; i + diff <= n; i++)
        {
            int j = i + diff;
            int min = INT_MAX;
            kay[i][j] = -1;
            for (int k = i; k < j; k++)
            {
                int cost = c[i][k] + c[k + 1][j] + r[i] * r[k + 1] * r[j + 1];
                if (cost < min)
                {
                    min = cost;
                    kay[i][j] = k;
                }
            }
            c[i][j] = min;
        }
        diff++;
    }
    cout << "minimum cost is:" << c[1][n] << endl;
    cout << "kay matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            gkay[i][j] = kay[i][j];
            cout << kay[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i] = "A";
        ans[i] += '0' + i;
    }
    update(1, n);
    cout << "Order of multiplication:";
    for (int i = 1; i < n; i++)
    {
        cout << ans[i] << "x";
    }
    cout << ans[n] << endl;
}

// 4
// 3 2 4 2 5