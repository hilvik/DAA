#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Cont
{
public:
    int weight;
};

bool comp(Cont a, Cont b)
{
    return (a.weight < b.weight);
}

int loading(Cont a[], int cap, int n)
{
    sort(a, a + n, comp);
    int cur_weight = 0;
    for (int i = 0; i < n; i++)
    {
        if (cur_weight + a[i].weight < cap)
        {
            cur_weight += a[i].weight;
        }
    }
    return cur_weight;
}

int main()
{
    int n;
    cout << "enter the number of containers: " << endl;
    cin >> n;
    int cap;
    cout << "enter the total capacity" << endl;
    cin >> cap;
    Cont a[n];
    cout << "Enter the capacity of each container: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].weight;
    }
    cout << "total capacity occupied: " << loading(a, cap, n) << endl;
    return 0;
}
