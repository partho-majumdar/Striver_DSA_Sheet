#include <bits/stdc++.h>
using namespace std;

void dfs(int st_node, vector<int> adj[], int visit[], vector<int> &ans)
{
    visit[st_node] = 1;
    ans.push_back(st_node);

    for (auto i : adj[st_node])
    {
        if (!visit[i])
        {
            dfs(i, adj, visit, ans);
        }
    }
}

vector<int> make_dfs_graph(vector<int> adj[], int V)
{
    int visit[V + 1] = {0};
    int start = 1;
    vector<int> ans;
    dfs(start, adj, visit, ans);
    return ans;
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
    vector<int> dfsResult = make_dfs_graph(adj, V);

    for (int node : dfsResult)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}