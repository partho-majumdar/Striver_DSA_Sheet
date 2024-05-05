#include <bits/stdc++.h>
using namespace std;

void weighted_graph()
{
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<pair<int, int>> adj[V + 1];

    cout << "Enter the edges (a b weight):\n";
    for (int i = 1; i <= E; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    cout << "Adjacency List representation of the weighted graph:\n";
    for (int i = 1; i <= V; i++)
    {
        cout << "Vertex " << i << " : ";
        for (auto j : adj[i])
        {
            cout << "(" << j.first << ", " << j.second << ") ";
        }
        cout << endl;
    }
}

int main()
{
    weighted_graph();
    return 0;
}
