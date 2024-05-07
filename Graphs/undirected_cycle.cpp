#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], int vis[])
{
    vis[src] = 1;
    // store <source node, parent node>
    queue<pair<int, int>> q;
    q.push({src, -1});
    // traverse until queue is not empty
    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // go to all adjacent nodes
        for (auto adjacentNode : adj[node])
        {
            // if adjacent node is unvisited
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            // if adjacent node is visited and is not it's own parent node
            else if (parent != adjacentNode)
            {
                // yes it is a cycle
                return true;
            }
        }
    }
    // there's no cycle
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    // initialise them as unvisited
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (detect(i, adj, vis))
                return true;
        }
    }
    return false;
}

int main()
{

    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};

    bool ans = isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
