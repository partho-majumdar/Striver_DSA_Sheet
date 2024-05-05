#include <bits/stdc++.h>
using namespace std;

const int min_value = INT_MIN;

void dfs(int node, vector<int> &visit, stack<int> &st, vector<pair<int, int>> adj[])
{
    visit[node] = 1;
    for (auto &edge : adj[node])
    {
        int v = edge.first;
        if (!visit[v])
        {
            dfs(v, visit, st, adj);
        }
    }
    st.push(node);
}

vector<int> longestPath(int src, int V, vector<pair<int, int>> adj[])
{
    vector<int> visit(V, 0);
    stack<int> st;
    for (int i = 0; i < V; ++i)
    {
        if (!visit[i])
        {
            dfs(i, visit, st, adj);
        }
    }

    vector<int> dist(V, min_value);
    dist[src] = 0;

    while (!st.empty())
    {
        int u = st.top();
        st.pop();

        if (dist[u] != min_value)
        {
            for (auto &edge : adj[u])
            {
                int v = edge.first;
                int weight = edge.second;
                if (dist[v] < dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }
    return dist;
}

int main()
{
    int V, E;
    cout << "Enter Vertices (V) and edges (E): ";
    cin >> V >> E;

    vector<pair<int, int>> adj[V];

    cout << "Enter the edges (a b weight):\n";
    for (int i = 1; i <= E; ++i)
    {
        int a, b, weight;
        cin >> a >> b >> weight;
        adj[a].emplace_back(b, weight);
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    vector<int> dist = longestPath(src, V, adj);

    cout << "Longest distance: \n";
    for (int i = 0; i < V; ++i)
    {
        if (dist[i] == min_value)
        {
            cout << "dist(" << src << ", " << i << ") = infinity\n";
        }
        else
        {
            cout << "dist(" << src << ", " << i << ") = " << dist[i] << "\n";
        }
    }
    return 0;
}