#include <iostream>

using namespace std;

void dfs(int v, int adj[][10], int source)
{
    int visited[v] = {0};
    int s[20], top = -1;
    s[++top] = source;
    visited[source] = 1;
    while (top >= 0)
    {
        int u = s[top--];
        for (int i = 0; i < v; i++)
        {
            if (adj[u][i] == 1 && visited[i] == 0)
            {
                s[++top] = i;
                visited[i] = 1;
            }
        }
        cout << u << " ";
    }
}

int main()
{
    int v, e;
    cout << "vertices and edges: " << endl;
    cin >> v >> e;
    int adj[10][10];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            adj[i][j] = 0;
        }
    }
    cout << "enter source and destination of edge:" << endl;
    int p, q;
    for (int i = 0; i < e; i++)
    {
        cin >> p;
        cin >> q;
        adj[p][q] = 1;
    }
    cout << "enter source:" << endl;
    int source;
    cin >> source;

    dfs(v, adj, source);
}