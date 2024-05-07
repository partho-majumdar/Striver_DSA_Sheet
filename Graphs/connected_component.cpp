#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int visit[], vector<int> &store_ans, int start)
{
    visit[start] = 1;
    store_ans.push_back(start);
    int cnt = 0;

    for (auto it : adj[start])
    {
        if (!visit[it])
        {
            cnt++;
            dfs(adj, visit, store_ans, it);
        }
    }
    cout << cnt;
}

vector<int> make_dfs(vector<int> adj[], int v)
{
    int visit[v + 1] = {0};
    vector<int> store_ans;
    int start = 1;
    dfs(adj, visit, store_ans, start);
    return store_ans;
}

void graph_list(vector<int> adj[], int v, int e)
{
    int a, b;
    for (int i = 1; i <= e; i++)
    {
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

    cout << "Connected components:" << endl;
    vector<int> result = make_dfs(adj, v);

    // for (auto i : result)
    // {
    //     cout << i << " ";
    // }
}