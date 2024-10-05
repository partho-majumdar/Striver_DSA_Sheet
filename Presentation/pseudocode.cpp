// class Node:
//     string name 
//     int cost     // Total cost (g(n) + h(n))

// // Graph structure to represent the graph
// class Graph:
//     map<string, list<pair<string, int>>> adj

//     function addEdge(string u, string v, int weight):
//         adj[u].add(v, weight)

//     function getNeighbors(string v) -> list<pair<string, int>>:
//         return adj[v]

// // Heuristic distances map h(n)
// map<string, int> h_dist = {
//     {"S", 11.5}, {"A", 10.1}, {"B", 5.8}, {"C", 3.4}, {"D", 9.2}, {"E", 7.1}, {"F", 3.5}, {"G", 0}
// }

// // A* Search Algorithm
// function aStarAlgo(Graph graph, string start_node, string stop_node) -> list<string>:
//     // Priority queue (min-heap) to store nodes to be explored
//     priority_queue<Node> open_set
//     map<string, int> g
//     map<string, string> parents

//     open_set.push(start_node, 0)
//     g[start_node] = 0
//     parents[start_node] = start_node

//     while not open_set.empty():
//         string n = open_set.top().name
//         open_set.pop()

//         if n == stop_node:
//             list<string> path
//             while parents[n] != n:
//                 path.push_front(n)
//                 n = parents[n]
//             path.push_front(start_node)
//             return path

//         for each (neighbor, weight) in graph.getNeighbors(n):
//             tentative_g_score = g[n] + weight

//             if g[neighbor] is not set OR tentative_g_score < g[neighbor]:
//                 g[neighbor] = tentative_g_score
//                 f_score = tentative_g_score + h_dist[neighbor]
//                 parents[neighbor] = n
//                 open_set.push(neighbor, f_score)

//     // If no path is found
//     return []

// // Main function
// function main():
//     Graph graph

//     // Add edges (define the graph)
//     graph.addEdge("S", "A", 3)
//     graph.addEdge("S", "D", 4)
//     graph.addEdge("A", "B", 4)
//     graph.addEdge("A", "D", 5)
//     graph.addEdge("B", "C", 4)
//     graph.addEdge("B", "E", 5)
//     graph.addEdge("D", "E", 2)
//     graph.addEdge("E", "F", 4)
//     graph.addEdge("F", "G", 3.5)

//     // Run A* algorithm
//     aStarAlgo(graph, "S", "G")








class Node:
    string name
    int cost // g(n) + h(n)

class Graph:
    map<string, list<pair<string, int>>> adj

    function addEdge(string u, string v, int weight): 
        // Add edge (u -> v) with given weight to adj list

    function getNeighbors(string v) -> list<pair<string, int>>: 
        // Return all neighbors of node v

map<string, int> h_dist = { ... } // Heuristic values (h(n))

function aStarAlgo(Graph graph, string start_node, string stop_node) -> list<string>:
    priority_queue<Node> open_set
    map<string, int> g, parents

    // Initialize start node in open_set, g, and parents
    open_set.push(start_node, 0)
    g[start_node] = 0
    parents[start_node] = start_node

    while open_set not empty:
        n = open_set.top().name
        open_set.pop()

        if n == stop_node:
            // Reconstruct path from stop_node to start_node
            return path

        // For each neighbor of n:
        //     Calculate tentative g score
        //     If better path found, update g, f score, and parent
        //     Push neighbor into open_set

    return [] // If no path is found

function main():
    Graph graph
    // Add edges to the graph
    graph.addEdge("S", "A", 3)
    graph.addEdge("S", "D", 4)
    ...
    // Run A* algorithm
    aStarAlgo(graph, "S", "G")
