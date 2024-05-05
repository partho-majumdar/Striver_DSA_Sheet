#include <bits/stdc++.h>
using namespace std;

void make_list(int V, int E)
{
    vector<int> adj_list[V + 1];

    int a, b;
    for (int i = 1; i <= E; i++)
    {
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    cout << "Adjacency list output: " << endl;
    for (int i = 0; i <= V - 1; i++)
    {
        cout << i << ": ";
        for (auto j : adj_list[i])
        {
            cout << j << ", ";
        }
        cout << endl;
    }

    int cnt = 0;
    int vertex;
    for (int i = 0; i <= V - 1; i++)
    {

        if (cnt <= adj_list[i].size())
        {
            vertex = i;
            cnt = adj_list[i].size();
        }
    }
    cout << vertex << " vertex has the highest number of adjacency nodes that is: " << cnt;
}

int main()
{
    int V, E;
    cout << "Enter vertex(V) and edge(E): ";
    cin >> V >> E;
    make_list(V, E);
}