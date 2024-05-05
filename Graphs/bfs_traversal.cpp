#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[], int sn)
{
    int visit[V + 1] = {0};
    queue<int> q;
    vector<int> bfs_ans;

    q.push(sn);
    visit[sn] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs_ans.push_back(node);

        for (auto neighbor : adj[node])
        {
            if (!visit[neighbor])
            {
                q.push(neighbor);
                visit[neighbor] = 1;
            }
        }
    }
    return bfs_ans;
}

void graph_using_list(vector<int> adj[], int V, int E)
{
    cout << "Enter the edges (a b):\n";
    for (int i = 1; i <= E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<int> adj[V + 1];
    graph_using_list(adj, V, E);

    cout << "Adjacency List representation of the graph:\n";
    for (int i = 1; i <= V; i++)
    {
        cout << "Vertex " << i << " : ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    int sn;
    cout << "which is gonna be your starting node: ";
    cin >> sn;

    vector<int> bfsResult = bfsOfGraph(V, adj, sn);
    cout << "BFS Traversal of the graph:\n";

    for (auto node : bfsResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
