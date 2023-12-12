#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Item
{
public:
    int profit;
    int weight;
};

bool compare(Item a, Item b)
{
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return (r1 > r2);
}

int knap(Item A[], int cap, int n)
{
    sort(A, A + n, compare);
    int cur_weight = 0;
    double final_profit = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (cur_weight + A[i].weight <= cap)
        {
            cur_weight += A[i].weight;
            final_profit += A[i].profit;
        }
        else
        {
            int remain = cap - cur_weight;
            final_profit = final_profit + ((double)remain / A[i].weight) * A[i].profit;
        }
    }
    return final_profit;
}

int main()
{
    int n, cap;
    cout << "Enter number of items:" << endl;
    cin >> n;
    cout << "Enter total capacity of knapsack:" << endl;
    cin >> cap;
    Item A[n];
    cout << "Enter profit and weight of each item:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].profit;
        cin >> A[i].weight;
    }
    cout << "Maxiumum Profit: " << knap(A, cap, n) << endl;

    return 0;
}
