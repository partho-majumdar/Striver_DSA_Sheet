#include <bits/stdc++.h>
using namespace std;

void adjacency_matrix()
{
    int N, E;
    cout << "Enter number of nodes: ";
    cin >> N;
    cout << "Enter number of edges: ";
    cin >> E;

    int graph[N][N] = {};

    cout << "Enter edges (node1 node2):" << endl;
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    cout << "---------Graph---------" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    adjacency_matrix();
    return 0;
}
