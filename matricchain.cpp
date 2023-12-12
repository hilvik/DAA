#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int matrix(int p[], int i, int j)
{
    int k, count;
    int mini = INT_MAX;
    for (k = i; k < j; k++)
    {
        count = matrix(p, i, k) + matrix(p, k + 1, j) + (p[i - 1] * p[k] * p[j]);
        mini = min(count, mini);
    }
    return mini;
}

int main()
{
    cout < "enter number of matrices:" << endl;
    int n;
    cin >> n;
}
