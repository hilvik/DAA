// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;
// int maxprofit = 0;

// int knapback(int n, int c, int p[], int wt[], int i, int cw, int cp)
// {
//     if (i == n || cw == c)
//     {
//         if (cw > maxprofit)
//         {
//             maxprofit = cp;
//         }
//         return maxprofit;
//     }

//     if (cw + wt[i] <= c)
//     {
//         maxprofit = max(maxprofit, knapback(n, c, p, wt, i + 1, cw + wt[i], cp + p[i]));
//     }
//     else
//     {
//         maxprofit = max(maxprofit, knapback(n, c, p, wt, i + 1, cw, cp));
//     }

//     return maxprofit;
// }

// int main()
// {
//     int n, c;
//     cout << "enter number of items and max capacity of knapsack" << endl;
//     cin >> n;
//     cin >> c;
//     int p[n], wt[n];
//     cout << "enter profit and weight of item : " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> p[i];
//         cin >> wt[i];
//     }

//     int maxproft = knapback(n, c, p, wt, 0, 0, 0);

//     cout << "max profit : " << maxproft;

//     return 0;
// }
#include <iostream>

using namespace std;

int knapback(int n, int c, int p[], int wt[], int i, int cw, int cp)
{
    if (i == n || cw == c)
    {
        return cp;
    }

    int maxprofit = cp;

    if (cw + wt[i] <= c)
    {
        maxprofit = max(maxprofit, knapback(n, c, p, wt, i + 1, cw + wt[i], cp + p[i]));
    }

    maxprofit = max(maxprofit, knapback(n, c, p, wt, i + 1, cw, cp));

    return maxprofit;
}

int main()
{
    int n, c;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> c;

    int p[n], wt[n];
    cout << "Enter the profit and weight of each item: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i] >> wt[i];
    }

    int maxProfit = knapback(n, c, p, wt, 0, 0, 0);

    cout << "Max profit: " << maxProfit << endl;

    return 0;
}
