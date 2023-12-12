//
#include <iostream>
using namespace std;

const int INF = 1e9;

void tsp(int n, int graph[][10], bool visited[], int currPos, int count, int cost, int &minCost)
{
    if (count == n)
    {
        if (graph[currPos][0] != 0 && cost + graph[currPos][0] < minCost)
        {
            minCost = cost + graph[currPos][0];
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && graph[currPos][i] != 0)
        {
            visited[i] = true;
            tsp(n, graph, visited, i, count + 1, cost + graph[currPos][i], minCost);
            visited[i] = false;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    int graph[10][10];
    cout << "Enter the adjacency matrix representing the distances between cities:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    bool visited[10] = {false};
    visited[0] = true;

    int minCost = INF;
    tsp(n, graph, visited, 0, 1, 0, minCost);

    cout << "Minimum cost: " << minCost << endl;

    return 0;
}
