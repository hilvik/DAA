// takes a directed graph and returns an array of the nodes where each node appears before all the nodes it points to.
#include <iostream>
using namespace std;

int main()
{
    int p, q;
    cout << "enter number of vertices: " << endl;
    cin >> p;
    cout << "enter number of edges: " << endl;
    cin >> q;
    int adj[p][q];
    int indeg[100] = {0};
    cout << "enter the source and destination of edges: " << endl;
    int m, n;
    for (int i = 0; i < q; i++)
    {
        cin >> m;
        cin >> n;
        adj[m][n] = 1;
    }
}
