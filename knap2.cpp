#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int maxProfit = 0;

int knap(int n, int c, int p[], int wt[])
{
    int dp[n + 1][c + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= c; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] < w)
            {
                dp[i][w] = max(p[i] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][c];
}
int main()
{
    int n, c;
    cout << "number of items and capacity: " << endl;
    cin >> n >> c;
    int p[n], wt[n];
    cout << "profit and weight of each item:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        cin >> wt[i];
    }
    cout << "maximum profit " << knap(n, c, p, wt) << endl;
}