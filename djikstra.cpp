#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int findMinVertex(int distance[], bool visited[], int v)
{
    int minVertex = -1;
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void dick(int adj[][100], int v, int source)
{
    int distance[v];
    bool visited[v];

    for (int i = 1; i <= v; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[source] = 0;

    for (int i = 1; i <= v; i++)
    {
        int minVertex = findMinVertex(distance, visited, v);
        visited[minVertex] = true;
        for (int j = 1; j <= v; j++)
        {
            if (adj[minVertex][j] != 0 && !visited[j])
            {
                int dist = distance[minVertex] + adj[minVertex][j];
                if (dist < distance[j])
                {
                    distance[j] = dist;
                }
            }
        }
    }
    for (int i = 1; i <= v; i++)
    {
        cout << i << " " << distance[i] << endl;
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
        for (int j = 1; j <= m; j++)
        {
            adj[i][j] = 0;
        }
    }
    int p, q, d;
    cout << "enter source,destination and distance" << endl;
    do
    {
        cin >> p;
        cin >> q;
        cin >> d;
        adj[p][q] = d;
    } while (p != -1 && q != -1 && d != -1);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;

    cout << "enter source vertex: " << endl;
    int source;
    cin >> source;
    dick(adj, m, source);

    return 0;
}
