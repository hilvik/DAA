#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void find_MST(int adj[][100], int m)
{
    int parent[m], cost[m];
    bool visited[m];
    for (int i = 1; i <= m; i++)
    {
        cost[i] = 999;
        visited[i] = false;
        parent[i] = -1;
    }
    cost[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < m; i++)
    {
        int u = min_cost(adj, visited);
        visited[u] = true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (adj[u][m] != 0 && visited[m] == false && adj[u][m] < cost[m])
        {
            parent[m] = u;
            cost[m] = adj[u][m];
        }
    }
}

int main()
{
    int m;
    cout << "enter number of vertices:" << endl;
    cin >> m;
    int adj[100][100];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            adj[i][j] = 0;
        }
    }
    cout << "enter source destination and cost:" << endl;
    int p, q, c;
    do
    {
        cin >> p >> q >> c;
        adj[p][q] = c;
    } while (p != -1 && q != -1 && c != -1);
}