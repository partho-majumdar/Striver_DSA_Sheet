#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int visit[], vector<int> &dfs_ans)
{
    visit[node] = 1;
    dfs_ans.push_back(node);

    for (auto it : adj[node])
    {
        if (!visit[it])
        {
            dfs(it, adj, visit, dfs_ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    int visit[V + 1] = {0};
    int start = 1;
    vector<int> dfs_ans;
    dfs(start, adj, visit, dfs_ans);
    return dfs_ans;
}

void graph_using_list(vector<int> adj[], int V, int E)
{
    cout << "Enter the edges (a b):\n";
    for (int i = 0; i < E; i++)
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

    cout << "DFS Traversal of the graph:\n";
    vector<int> dfsResult = dfsOfGraph(V, adj);

    for (int node : dfsResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}