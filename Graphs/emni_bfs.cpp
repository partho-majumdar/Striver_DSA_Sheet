#include <bits/stdc++.h>
using namespace std;

vector<int> bfs_traversal(vector<int> adj[], int v, int sn)
{
    int visit[v + 1] = {0};
    queue<int> q;
    vector<int> ans;

    q.push(sn);
    visit[sn] = 1;

    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        ans.push_back(val);

        for (auto neighbour : adj[val])
        {
            if (!visit[neighbour])
            {
                q.push(neighbour);
                visit[neighbour] = 1;
            }
        }
    }
    return ans;
}

void graph_list(vector<int> adj[], int v, int e)
{
    for (int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<int> adj[v + 1];
    graph_list(adj, v, e);

    for (int i = 1; i <= v; i++)
    {
        cout << "Vertex " << i << ": ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    int sn;
    cout << "which is gonna be your starting node: ";
    cin >> sn;
    cout << "After bfs traversal: ";

    vector<int> result = bfs_traversal(adj, v, sn);
    for (auto i : result)
    {
        cout << i << " ";
    }
}