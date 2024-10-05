/*
#include <bits/stdc++.h>
using namespace std;

// Solution class containing the function to find the sum of the weights of edges in the MST
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Min-heap (priority queue) to pick the smallest edge weight (Prim's Algorithm)
        // Stores pairs of {weight, node}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<pair<int, int>>>
            pq;

        // Visited array to mark nodes that are already included in the MST
        vector<int> vis(V, 0);

        // Initializing the priority queue with the starting node (node 0 with weight 0)
        // {weight, node} => {0, 0} means node 0 with a weight of 0.
        pq.push({0, 0});

        // Variable to store the sum of the weights of the edges included in the MST
        int sum = 0;

        // Loop until the priority queue is empty (which happens after covering all nodes)
        while (!pq.empty())
        {
            // Extract the top (smallest weight) element from the priority queue
            auto it = pq.top();
            pq.pop();

            // Extract the node and the weight of the current edge from the pair
            int node = it.second;
            int wt = it.first;

            // If the node is already visited, skip it (since it's already part of the MST)
            if (vis[node] == 1)
                continue;

            // Mark the node as visited (part of the MST now)
            vis[node] = 1;

            // Add the weight of the current edge to the MST sum
            sum += wt;

            // Traverse all the adjacent nodes (neighbors) of the current node
            for (auto it : adj[node])
            {
                int adjNode = it[0]; // Adjacent node (neighbor)
                int edW = it[1];     // Edge weight between current node and adjacent node

                // If the adjacent node is not visited, push it to the priority queue
                // with its corresponding edge weight
                if (!vis[adjNode])
                {
                    pq.push({edW, adjNode});
                }
            }
        }
        // Return the total sum of the edge weights of the Minimum Spanning Tree
        return sum;
    }
};

int main()
{

    // Number of vertices in the graph
    int V = 5;

    // List of edges where each edge is represented as {from, to, weight}
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

    // Adjacency list to represent the graph
    vector<vector<int>> adj[V];

    // Building the adjacency list from the edge list
    for (auto it : edges)
    {
        vector<int> tmp(2);
        tmp[0] = it[1];            // Neighbor node
        tmp[1] = it[2];            // Edge weight
        adj[it[0]].push_back(tmp); // Add {neighbor, weight} to the adjacency list of `from` node

        // Since the graph is undirected, we need to add the reverse edge as well
        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp); // Add {from, weight} to the adjacency list of `to` node
    }

    // Create an object of the Solution class
    Solution obj;

    // Call the spanningTree function to calculate the MST sum
    int sum = obj.spanningTree(V, adj);

    // Output the result
    cout << "The sum of all the edge weights: " << sum << endl;

    return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;

// Solution class containing the function to find the sum of the weights of edges in the MST and print paths
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree and print the MST paths.
    int spanningTree(int V, vector<pair<int, int>> adj[])
    {
        // Min-heap (priority queue) to pick the smallest edge weight (Prim's Algorithm)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Visited array to mark nodes that are already included in the MST
        vector<int> vis(V, 0);

        // Array to store the parent of each node (to reconstruct the MST path)
        vector<int> parent(V, -1);

        // Initializing the priority queue with the starting node (node 0 with weight 0)
        pq.push({0, 0});

        // Variable to store the sum of the weights of the edges included in the MST
        int sum = 0;

        // Loop until the priority queue is empty (which happens after covering all nodes)
        while (!pq.empty())
        {
            // Extract the top (smallest weight) element from the priority queue
            auto it = pq.top();
            pq.pop();

            // Extract the node and the weight of the current edge from the pair
            int node = it.second;
            int wt = it.first;

            // If the node is already visited, skip it (since it's already part of the MST)
            if (vis[node] == 1)
                continue;

            // Mark the node as visited (part of the MST now)
            vis[node] = 1;

            // Add the weight of the current edge to the MST sum
            sum += wt;

            // Traverse all the adjacent nodes (neighbors) of the current node
            for (auto it : adj[node])
            {
                int adjNode = it.first; // Adjacent node (neighbor)
                int edW = it.second;    // Edge weight between current node and adjacent node

                // If the adjacent node is not visited, push it to the priority queue
                if (!vis[adjNode])
                {
                    pq.push({edW, adjNode});
                    parent[adjNode] = node; // Store the parent of the adjacent node
                }
            }
        }

        // Print the edges of the MST
        cout << "Edges in the Minimum Spanning Tree:" << endl;
        for (int i = 1; i < V; i++)
        {
            cout << "Edge: " << parent[i] << " - " << i << endl;
        }

        // Return the total sum of the edge weights of the Minimum Spanning Tree
        return sum;
    }
};

int main()
{
    // Number of vertices in the graph
    int V = 5;

    // Create the adjacency list for an undirected graph
    vector<pair<int, int>> adj[V];

    // List of edges where each edge is represented as {from, to, weight}
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 2, 1},
        {2, 3, 2},
        {3, 4, 1},
        {4, 2, 2}};

    // Building the adjacency list from the edge list
    for (auto edge : edges)
    {
        int u = edge[0]; // from node
        int v = edge[1]; // to node
        int w = edge[2]; // weight of the edge

        // Since it's an undirected graph, we need to add the edge in both directions
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // Create an object of the Solution class
    Solution obj;

    // Call the spanningTree function to calculate the MST sum
    int sum = obj.spanningTree(V, adj);

    // Output the result
    cout << "The sum of all the edge weights: " << sum << endl;

    return 0;
}
