#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << "enter number of items:" << endl;
    int n;
    cin >> n;
    cout << "enter max capacity: " << endl;
    int c;
    cin >> c;

    cout << "enter profits of all items:" << endl;
    int p[n + 1], wt[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        cin >> p[i];
    }
    p[0] = 0;
    wt[0] = 0;
    cout << "enter weights of all items" << endl;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> wt[i];
    }

    int k[n + 1][c + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= c; w++)
        {
            if (i == 0 || w == 0)
            {
                k[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                k[i][w] = max(p[i] + k[i - 1][w - wt[i]], k[i - 1][w]);
            }
            else
            {
                k[i][w] = k[w][i];
            }
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            cout << k[i][j] << " ";
        }
        cout << endl;
    }

    cout << "max profit: " << k[n + 1][c + 1] << endl;

    return 0;
}