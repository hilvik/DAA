#include <iostream>

#define inf 9999
using namespace std;
int floydm(int g[][10], int v)
{
    int d[10][10];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            d[i][j] = g[i][j];
        }
    }
    for (int k = 0; k < v; ++k)
    {
        for (int i = 0; i < v; ++i)
        {
            for (int j = 0; j < v; ++j)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << "dist between " << i << " and " << j << " is " << d[i][j] << endl;
        }
    }
    return 0;
}

int main()
{
    int v;
    cout << "enter number of vertices:" << endl;
    cin >> v;
    int g[10][10];

    cout << "enter adj matrix of the graph:" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> g[i][j];
        }
    }

    floydm(g, v);
}