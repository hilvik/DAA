// #include <bits/stdc++.h>

// using namespace std;

// int knap(int c, int n, int wt[], int p[])
// {
//     int k[n + 1][c + 1];
//     int i, w;
//     for (i = 0; i <= n; i++)
//     {
//         for (w = 0; w <= c; w++)
//         {
//             if (i == 0 || w == 0)
//             {
//                 k[i][w] = 0;
//             }
//             else if (wt[i - 1] < w)
//             {
//                 k[i][w] = max(p[i - 1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]);
//             }
//             else
//             {
//                 k[i][w] = k[i - 1][w];
//             }
//         }
//     }
//     return k[n][c];
// }

// int main()
// {
//     cout << "Enter number of items: " << endl;
//     int n;
//     cin >> n;
//     int c;
//     cout << "enter max capacity of knapsack: " << endl;
//     cin >> c;
//     int p[n], wt[n];
//     cout << "enter profit and weight: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> p[i];
//         cin >> wt[i];
//     }
//     cout << "max capacity: " << knap(c, n, wt, p);
//     return 0;
// }
#include <iostream>
using namespace std;
int max(int x, int y)
{
    return (x > y) ? x : y;
}
int knapSack(int W, int w[], int v[], int n)
{
    int i, wt;
    int K[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (wt = 0; wt <= W; wt++)
        {
            if (i == 0 || wt == 0)
                K[i][wt] = 0;
            else if (w[i - 1] <= wt)
                K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
            else
                K[i][wt] = K[i - 1][wt];
        }
    }
    return K[n][W];
}
int main()
{
    cout << "Enter the number of items in a Knapsack:";
    int n, W;
    cin >> n;
    int v[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value and weight for item " << i << ":";
        cin >> v[i];
        cin >> w[i];
    }
    cout << "Enter the capacity of knapsack";
    cin >> W;
    cout << knapSack(W, w, v, n);
    return 0;
}