#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int visit[], stack<int> &st, vector<int> adj[])
{
    visit[node] = 1;
    for (auto it : adj[node])
    {
        if (!visit[it])
        {
            dfs(it, visit, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    int visit[V] = {0};
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!visit[i])
        {
            dfs(i, visit, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

void graph_using_list(vector<int> adj[], int V, int E)
{
    cout << "Enter the edges (a b):\n";
    for (int i = 1; i <= E; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<int> adj[V];
    graph_using_list(adj, V, E);

    cout << "Adjacency List representation of the graph:\n";
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << " : ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    vector<int> topo_order = topoSort(V, adj);

    cout << "Topological Sort of the graph:\n";
    for (int node : topo_order)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
