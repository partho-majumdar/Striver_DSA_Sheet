#include <bits/stdc++.h>
using namespace std;

void graph_using_list()
{
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<int> adj[V + 1];

    cout << "Enter the edges (a b):\n";
    for (int i = 1; i <= E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "Adjacency List representation of the directed graph:\n";
    for (int i = 1; i <= V; i++)
    {
        cout << "Vertex " << i << " : ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    graph_using_list();
    return 0;
}
