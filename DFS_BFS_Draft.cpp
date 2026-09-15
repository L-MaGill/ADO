/*
 * Graph Traversal Exercise: DFS and BFS
 * ==========================================================================
 *
 * The Graph class and main() are already implemented for you.
 * Your job: complete the four functions below (marked TODO).
 * Each function has a comment describing what it should do and return.
 *
 * Compile:  g++ -std=c++17 -O2 -o dfs_bfs_exercise dfs_bfs_exercise.cpp
 * Run:      ./dfs_bfs_exercise
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

// --------------------------------------------------------------------------
// Graph representation (adjacency list) -- already implemented
// --------------------------------------------------------------------------
class Graph {
public:
    Graph(int numVertices, bool directed = false)
        : n(numVertices), directed(directed), adj(numVertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    void print() const {
        for (int i = 0; i < n; i++) {
            cout << i << ": [";
            for (size_t j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j] << (j + 1 < adj[i].size() ? ", " : "");
            }
            cout << "]\n";
        }
    }

    int n;
    bool directed;
    vector<vector<int>> adj;
};

// --------------------------------------------------------------------------
// TODO 1: Recursive DFS helper
//
// Visits `node`, marks it visited, and records it in `order`.
// Then recursively visits every neighbor of `node` that has not
// been visited yet.
//
// Parameters:
//   g       - the graph to traverse
//   node    - the current node being visited
//   visited - a vector<bool> tracking which nodes have been visited
//             (modify this in place)
//   order   - a vector<int> collecting nodes in the order they are
//             first visited (modify this in place)
//
// Returns: nothing (void). Results are accumulated into `visited`
//          and `order` via reference parameters.
// --------------------------------------------------------------------------
void dfsRecursiveHelper(const Graph& g, int node, vector<bool>& visited, vector<int>& order) {
    // TODO: implement
   /* if(visited[node] == 0) {
        visited[node] = 1;
        order.push_back(node);

        for (int n : g[node])
        
    }
 */
    visited[node] = 1;
    order.push_back(node);

    for (int neighbor : g.)
}

// --------------------------------------------------------------------------
// TODO 2: Recursive DFS (entry point)
//
// Performs a depth-first traversal of `g` starting at `start`,
// using dfsRecursiveHelper to do the actual recursive work.
//
// Parameters:
//   g     - the graph to traverse
//   start - the node to begin the traversal from
//
// Returns: a vector<int> containing every node reachable from
//          `start`, in the order they were first visited.
// --------------------------------------------------------------------------
vector<int> dfsRecursive(const Graph& g, int start) {
    // TODO: implement
    return {};
}

// --------------------------------------------------------------------------
// TODO 3: Iterative DFS (explicit stack)
//
// Performs the same depth-first traversal as dfsRecursive, but uses
// an explicit stack (std::stack<int>) instead of recursion.
//
// Hint: push `start` onto the stack. While the stack is not empty,
// pop a node; if it hasn't been visited, mark it visited, record it,
// and push its unvisited neighbors onto the stack (push them in
// reverse order if you want the same visiting order as the
// recursive version).
//
// Parameters:
//   g     - the graph to traverse
//   start - the node to begin the traversal from
//
// Returns: a vector<int> containing every node reachable from
//          `start`, in the order they were first visited.
// --------------------------------------------------------------------------
vector<int> dfsIterative(const Graph& g, int start) {
    // TODO: implement
    return {};
}

// --------------------------------------------------------------------------
// TODO 4: Iterative BFS (queue)
//
// Performs a breadth-first traversal of `g` starting at `start`,
// visiting all nodes at distance 1 before any node at distance 2,
// and so on, using a queue (std::queue<int>).
//
// Hint: mark `start` visited and push it onto the queue. While the
// queue is not empty, pop the front node, record it, and for each
// unvisited neighbor, mark it visited and push it onto the queue.
//
// Parameters:
//   g     - the graph to traverse
//   start - the node to begin the traversal from
//
// Returns: a vector<int> containing every node reachable from
//          `start`, in the order they were first visited
//          (i.e., level by level / shortest-hop order).
// --------------------------------------------------------------------------
vector<int> bfs(const Graph& g, int start) {
    // TODO: implement
    return {};
}

// --------------------------------------------------------------------------
// Helper to print a vector<int> -- already implemented
// --------------------------------------------------------------------------
void printOrder(const string& label, const vector<int>& order) {
    cout << label << ": [";
    for (size_t i = 0; i < order.size(); i++) {
        cout << order[i] << (i + 1 < order.size() ? ", " : "");
    }
    cout << "]\n";
}

int main() {
    Graph g(7, /*directed=*/false);
    g.addEdge(0, 1); // A-B
    g.addEdge(0, 2); // A-C
    g.addEdge(1, 3); // B-D
    g.addEdge(2, 4); // C-E
    g.addEdge(2, 5); // C-F
    g.addEdge(3, 6); // D-G
    g.addEdge(4, 6); // E-G

    cout << "Adjacency list:\n";
    g.print();
    cout << "\n";

    printOrder("DFS (recursive) from A(0)", dfsRecursive(g, 0));
    printOrder("DFS (iterative) from A(0)", dfsIterative(g, 0));
    printOrder("BFS             from A(0)", bfs(g, 0));

    // Expected output once implemented:
    // DFS (recursive) from A(0): [0, 1, 3, 6, 4, 2, 5]
    // DFS (iterative) from A(0): [0, 1, 3, 6, 4, 2, 5]
    // BFS             from A(0): [0, 1, 2, 3, 4, 5, 6]

    return 0;
}