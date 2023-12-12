#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int knapback(int c, int n, int p[], int wt[], int i, int cw, int cp)
{
    if (i == n || cw == c)
    {
        return cp;
    }

    int maxprofit = cp;

    if (cw + wt[i] <= c)
    {
        maxprofit = max(maxprofit, knapback(c, n, p, wt, i + 1, cw + wt[i], cp + p[i]));
    }
    else
    {
        maxprofit = max(maxprofit, knapback(c, n, p, wt, i + 1, cw, cp));
    }
    return maxprofit;
}

int main()
{
    int n, c;
    cout << "Enter number of items: " << endl;
    cin >> n;
    cout << "Enter capacity of knapsack: " << endl;
    cin >> c;
    int p[n], wt[n];
    cout << "enter profit and weight of items: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        cin >> wt[i];
    }

    cout << "Max profit: " << knapback(c, n, p, wt, 0, 0, 0);

    return 0;
}