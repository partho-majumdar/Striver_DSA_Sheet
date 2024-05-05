#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        int v = it.first;
        if (!vis[v]) {
            topoSort(v, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    int vis[N] = {0};
    stack<int> st;
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            topoSort(i, adj, vis, st);
        }
    }

    vector<int> dist(N, 1e9);
    dist[0] = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        for (auto it : adj[node]) {
            int v = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[v]) {
                dist[v] = wt + dist[node];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
    }
    return dist;
}

int main() {
    int N, M;
    cout << "Enter the number of vertices (N) and edges (M): ";
    cin >> N >> M;

    vector<vector<int>> edges(M, vector<int>(3));
    cout << "Enter the edges (u v wt):\n";
    for (int i = 0; i < M; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<int> shortest_distances = shortestPath(N, M, edges);

    cout << "Shortest distances from source vertex 0:\n";
    for (int dist : shortest_distances) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}
