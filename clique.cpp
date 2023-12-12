#include <bits/stdc++.h>
#define MAX 100

int graph[MAX][MAX];
int maxClique[MAX];
int maxCliquesize;

using namespace std;

bool isSafe(int v, int clique[], int pos)
{
    for (int i = 0; i < pos; i++)
    {
        if (graph[v][clique[i]] == 0)
            return false;
    }
    return true;
}

void findmaxclique(int clique[], int pos, int n, int size)
{
    if (pos >= n)
    {
        if (size > maxCliquesize)
        {
            maxCliquesize = size;
            for (int i = 0; i < pos; i++)
            {
                maxClique[i] = clique[i];
            }
            return;
        }
        for (int v = 0; v < n; v++)
        {
            if (isSafe(v, clique, pos))
            {
                clique[pos] = v;
                findmaxclique(clique, , pos + 1, n, size + 1);
            }
        }
    }
}

int main()
{
    int n;
    cout << "enter number of vertices: " << endl;
    cin >> n;
    cout << "Enter the adjacency matrix of the graph: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
}