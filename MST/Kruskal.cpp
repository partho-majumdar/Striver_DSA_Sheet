#include <bits/stdc++.h>
using namespace std;

// Disjoint Set (Union-Find) Class
class DisjointSet
{
    vector<int> parent, size;

public:
    // Constructor to initialize parent and size arrays
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i; // Initially, each node is its own parent
    }

    // Find function with path compression
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    // Union by size to connect two components
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        // Union by size
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// Solution class containing the function to find the sum of weights of edges in the MST
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree (MST)
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;

        // Collect all edges from the adjacency list
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0]; // Neighbor node
                int wt = it[1];      // Weight of the edge
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }

        // Sort the edges by their weight
        sort(edges.begin(), edges.end());

        DisjointSet ds(V); // Create a DisjointSet for union-find operations
        int mstWt = 0;

        // Process all edges, and use union-find to avoid cycles
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            // If the nodes u and v are in different components, include this edge in MST
            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mstWt += wt;          // Add edge weight to the MST sum
                ds.unionBySize(u, v); // Union the two components
            }
        }

        return mstWt; // Return the total weight of the MST
    }
};

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Number of vertices in the graph
    int V = 5;
    // Adjacency list for the graph, initialized for each vertex
    vector<vector<int>> adjacencyList[V];

    // List of edges represented as {from, to, weight}
    vector<vector<int>> edgeList = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 2, 1},
        {2, 3, 2},
        {3, 4, 1},
        {4, 2, 2}};

    // Building the adjacency list from the edge list
    for (const auto &edge : edgeList)
    {
        int u = edge[0];      // Source node
        int v = edge[1];      // Destination node
        int weight = edge[2]; // Weight of the edge

        adjacencyList[u].push_back({v, weight}); // Add edge from u to v
        adjacencyList[v].push_back({u, weight}); // Add edge from v to u (since undirected)
    }

    // Create an instance of the Solution class
    Solution solution;

    // Calculate the sum of weights of the MST
    int totalWeightMST = solution.spanningTree(V, adjacencyList);

    // Output the result
    cout << "The sum of all the edge weights in the Minimum Spanning Tree (MST): " << totalWeightMST << endl;

    return 0;
}
