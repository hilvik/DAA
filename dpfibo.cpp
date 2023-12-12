#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void fibo(int n)
{
    int fib[n + 2];
    fib[0] = 0;
    fib[1] = 1;

    cout << "fibonachi series for " << n << " :- " << endl;

    cout << fib[0] << " " << fib[1] << " ";

    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        cout << fib[i] << " ";
    }
}

int main()
{
    int n;
    cout << "enter n: " << endl;
    cin >> n;
    fibo(n);
    return 0;
}