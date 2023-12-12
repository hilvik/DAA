#include <iostream>
#include <bits/stdc.++h>

using namespace std;

class Task
{
public:
    int start;
    int finish;
};

bool comp(Task a, Task b)
{
    return (a.start < b.start);
}

void assign(Task ar[], int n)
{
    sort(ar, ar + n, comp);
    bool selected[n];
    for (int i = 0; i < n; i++)
    {
        selected[i] = false;
    }
}
