#include <bits/stdc++.h>
using namespace std;

// Structure to represent a node in the graph
struct Node
{
    string name;
    int cost; // g(n) + h(n)

    Node(string n, int c) : name(n), cost(c) {}
};

// Comparator for priority queue
struct Compare
{
    bool operator()(const Node &a, const Node &b)
    {
        return a.cost > b.cost; // Min-heap
    }
};

class Graph
{
public:
    unordered_map<string, vector<pair<string, int>>> adj;

    void addEdge(const string &u, const string &v, int weight)
    {
        adj[u].emplace_back(v, weight);
    }

    vector<pair<string, int>> getNeighbors(const string &v)
    {
        return adj[v];
    }
};

// Heuristic distances (h(n))
unordered_map<string, int> h_dist = {
    {"s", 11.5}, {"A", 10.1}, {"B", 5.8}, {"C", 3.4}, {"D", 9.2}, {"E", 7.1}, {"F", 3.5}, {"G", 0}};

// A* algorithm function
vector<string> aStarAlgo(Graph &graph, const string &start_node, const string &stop_node)
{
    priority_queue<Node, vector<Node>, Compare> open_set;
    unordered_map<string, int> g;
    unordered_map<string, string> parents;

    open_set.emplace(start_node, 0);
    g[start_node] = 0;
    parents[start_node] = start_node;

    while (!open_set.empty())
    {
        string n = open_set.top().name;
        open_set.pop();

        // If we reached the goal
        if (n == stop_node)
        {
            vector<string> path;
            while (parents[n] != n)
            {
                path.push_back(n);
                n = parents[n];
            }
            path.push_back(start_node);
            reverse(path.begin(), path.end());
            cout << "Path found: ";
            for (const string &node : path)
            {
                cout << node << " ";
            }
            cout << endl;
            return path;
        }

        // Process neighbors
        for (const auto &[m, weight] : graph.getNeighbors(n))
        {
            int tentative_g_score = g[n] + weight;

            if (g.find(m) == g.end() || tentative_g_score < g[m])
            {
                g[m] = tentative_g_score;
                int f_score = tentative_g_score + h_dist[m];
                parents[m] = n;
                open_set.emplace(m, f_score);
            }
        }
    }

    cout << "Path does not exist!" << endl;
    return {};
}

int main()
{
    Graph graph;

    // Define the edges based on the given graph
    graph.addEdge("S", "A", 3);
    graph.addEdge("S", "D", 4);
    graph.addEdge("A", "B", 4);
    graph.addEdge("A", "D", 5);
    graph.addEdge("B", "C", 4);
    graph.addEdge("B", "E", 5);
    graph.addEdge("D", "E", 2);
    graph.addEdge("E", "F", 4);
    graph.addEdge("F", "G", 3.5);

    aStarAlgo(graph, "S", "G");
    return 0;
}
