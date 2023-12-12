#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int knap(int n, int c, int p[], int wt[], int i, int cp, int cw)
{
    if (i == n || cw == c)
    {
        return cp;
    }
    int mp = cp;
    if (cw + wt[i] <= c)
    {
        mp = max(mp, knap(n, c, p, wt, i + 1, cp + p[i], cw + wt[i]));
    }

    mp = max(mp, knap(n, c, p, wt, i + 1, cp, cw));

    return mp;
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

    cout << "max profit : " << knap(n, c, p, wt, 0, 0, 0);
}