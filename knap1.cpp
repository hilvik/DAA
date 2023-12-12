#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int weight;
    int profit;
};

bool comp(Item a, Item b)
{
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return (r1 > r2);
}

int knap(int n, int c, Item a[])
{
    sort(a, a + n, comp);
    double cp = 0.0;
    int cw = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].weight + cw <= c)
        {
            cw += a[i].weight;
            cp += a[i].profit;
        }
        else
        {
            int remain = c - cw;
            cp = cp + ((double)remain / a[i].weight) * a[i].profit;
        }
    }
    return cp;
}

int main()
{
    int n, c;
    cout << "enter number of items and max capacity of knapsack:" << endl;
    cin >> n;
    cin >> c;
    Item a[n];
    cout << "enter profit and weight of each item:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].profit;
        cin >> a[i].weight;
    }
    cout << "max profit : " << knap(n, c, a);
}