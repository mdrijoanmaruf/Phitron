# BFS (Breadth First Search) - Complete Notes

## Table of Contents
1. [Introduction to Graph](#introduction-to-graph)
2. [Graph Representation](#graph-representation)
3. [Introduction to BFS](#introduction-to-bfs)
4. [BFS Algorithm](#bfs-algorithm)
5. [BFS Applications](#bfs-applications)
6. [Complete Examples](#complete-examples)
7. [Comparison and Time Complexity](#comparison-and-time-complexity)

---

# Introduction to Graph

## What is Graph?
**Graph is a non-linear data structure consisting of vertices (nodes) and edges**

```
    0 ---- 1
    |      |
    |      |
    3 ---- 2
```

**Key Terminology:**
- **Vertex (Node):** A point in graph
- **Edge:** Connection between two vertices
- **Adjacent:** Two vertices connected by an edge
- **Degree:** Number of edges connected to a vertex
- **Path:** Sequence of vertices connected by edges
- **Cycle:** Path that starts and ends at same vertex

**Types of Graph:**
- **Undirected Graph:** Edges have no direction (bidirectional)
- **Directed Graph:** Edges have direction (unidirectional)
- **Weighted Graph:** Edges have weights (costs)
- **Unweighted Graph:** All edges have equal weight

**Undirected Graph:**
```
    0 ---- 1          Edge between 0-1 means
    |      |          you can go both ways:
    |      |          0 → 1 and 1 → 0
    3 ---- 2
```

**Directed Graph:**
```
    0 ---→ 1          Edge from 0→1 means
    ↑      |          you can only go
    |      ↓          from 0 to 1, not 1 to 0
    3 ←--- 2
```

**Weighted Graph:**
```
    0 --5-- 1         Each edge has a cost/weight
    |       |         Edge 0-1 has weight 5
    3       2         Edge 0-3 has weight 3
    |       |         Edge 1-2 has weight 2
    0 --3-- 3         Edge 2-3 has weight 4
```

---

# Graph Representation

## 1. Adjacency List (Most Common)
**Store neighbors of each vertex in a list**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;                      // n = nodes, e = edges

    vector<int> adj_list[n];            // array of vectors (each index stores its neighbors)
    
    while(e--){
        int a, b;
        cin >> a >> b;                  // read edge a-b
        adj_list[a].push_back(b);       // add b to a's neighbors
        adj_list[b].push_back(a);       // add a to b's neighbors (undirected)
    }

    // Print adjacency list
    for(int i = 0; i < n; i++){
        cout << i << " -> ";
        for(int x : adj_list[i]){
            cout << x << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

**Input:**
```
4 4
0 1
0 3
1 2
2 3
```

**Diagram:**
```
 Graph:                    Adjacency List:
    0 ---- 1              0 → [1, 3]
    |      |              1 → [0, 2]
    |      |              2 → [1, 3]
    3 ---- 2              3 → [0, 2]
```

**Output:**
```
0 -> 1 3 
1 -> 0 2 
2 -> 1 3 
3 -> 0 2 
```

**Advantages:**
- Space efficient: O(V + E)
- Fast to iterate over neighbors
- Best for sparse graphs

---

## 2. Adjacency Matrix
**Store edges in 2D matrix**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    int adj_mat[n][n];                     // 2D array
    memset(adj_mat, 0, sizeof(adj_mat));   // initialize all cells with 0

    while(e--){
        int a, b;
        cin >> a >> b;                      // read edge
        adj_mat[a][b] = 1;                 // edge from a to b
        adj_mat[b][a] = 1;                 // edge from b to a (undirected)
    }

    // Print adjacency matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**Diagram:**
```
 Graph:                  Adjacency Matrix:
    0 ---- 1                0  1  2  3
    |      |           0 [  0  1  0  1 ]
    |      |           1 [  1  0  1  0 ]
    3 ---- 2           2 [  0  1  0  1 ]
                       3 [  1  0  1  0 ]

  adj_mat[0][1] = 1  means edge exists between 0 and 1
  adj_mat[0][2] = 0  means no edge between 0 and 2
```

**Output:**
```
0 1 0 1 
1 0 1 0 
0 1 0 1 
1 0 1 0 
```

**Advantages:**
- O(1) edge lookup
- Best for dense graphs

**Disadvantages:**
- Space: O(V²)
- Slow to iterate over all edges

---

## 3. Edge List
**Store all edges as pairs**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;
    
    vector<pair<int,int>> edge_list;        // list of all edges

    while(e--){
        int a, b;
        cin >> a >> b;                      // read edge
        edge_list.push_back({a, b});        // store edge as pair
    } 

    // Print all edges
    for(pair<int, int> p : edge_list){
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}
```

**Diagram:**
```
 Graph:                 Edge List:
    0 ---- 1            Index    Edge
    |      |              0     (0, 1)
    |      |              1     (0, 3)
    3 ---- 2              2     (1, 2)
                          3     (2, 3)
```

**Output:**
```
0 1
0 3
1 2
2 3
```

**Advantages:**
- Simple to implement
- Good for Kruskal's algorithm

**Disadvantages:**
- O(E) to find neighbors
- Not efficient for traversal

---

## Graph Representation Comparison

| Representation | Space | Check Edge | Find Neighbors | Best For |
|----------------|-------|------------|----------------|----------|
| **Adjacency List** | O(V + E) | O(degree) | O(degree) | Sparse graphs, BFS/DFS |
| **Adjacency Matrix** | O(V²) | O(1) | O(V) | Dense graphs |
| **Edge List** | O(E) | O(E) | O(E) | Edge-based algorithms |

---

# Introduction to BFS

## What is BFS?
**Breadth First Search (BFS) is a graph traversal algorithm that explores vertices level by level**

```cpp
#include <bits/stdc++.h>
using namespace std;

// BFS explores all neighbors first before going deeper
// Level 0: source
// Level 1: direct neighbors of source
// Level 2: neighbors of level 1 nodes
// ...
```

**Key Characteristics:**
- Uses **Queue** data structure (FIFO)
- Explores all vertices at current level before moving to next
- Guarantees **shortest path** in unweighted graphs
- Time Complexity: O(V + E)
- Space Complexity: O(V)

**BFS Level-by-Level Exploration:**
```
    0 ---- 1 ---- 3         Level 0:  [0]         (source)
    |      |      |         Level 1:  [1, 2]       (neighbors of 0)
    2 ---- 4 ---- 5         Level 2:  [3, 4]       (neighbors of 1, 2)
                             Level 3:  [5]          (neighbors of 3, 4)
```

**BFS vs Tree Level Order:**
- BFS is essentially level order traversal applied to graphs
- Difference: graphs can have cycles, so we need **visited array**

---

# BFS Algorithm

## Basic BFS Implementation
**Traverse graph using BFS starting from source**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];         // adjacency list (global, max 1005 nodes)
bool visited[1005];                  // track visited nodes (avoid revisiting)

void bfs(int src){
    queue<int> q;                    // create queue for BFS
    q.push(src);                     // push source to queue
    visited[src] = true;             // mark source as visited

    while(!q.empty()){               // run until queue is empty
        // 1. Bring out front node
        int parent = q.front();      // get front of queue
        q.pop();                     // remove from queue

        // 2. Work with this node
        cout << parent << " ";       // process current node

        // 3. Push unvisited children
        for(int child : adj_list[parent]){   // iterate over neighbors
            if(!visited[child]){             // only push if not visited
                q.push(child);               // add to queue
                visited[child] = true;       // mark visited when pushing
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;                   // n = nodes, e = edges

    while(e--){
        int a, b;
        cin >> a >> b;               // read edge
        adj_list[a].push_back(b);    // add to adjacency list
        adj_list[b].push_back(a);    // undirected graph
    }
    
    memset(visited, false, sizeof(visited));  // initialize all as unvisited

    bfs(0);                           // start BFS from node 0
    return 0;
}
```

**Input:**
```
6 7
0 1
0 2
1 3
1 4
2 4
3 5
4 5
```

**Graph Diagram:**
```
    0 ---- 1 ---- 3
    |      |      |
    2 ---- 4 ---- 5
```

**Output:** `0 1 2 3 4 5`

---

## BFS Step-by-Step Process

```
Graph:
    0 ---- 1 ---- 3
    |      |      |
    2 ---- 4 ---- 5

BFS from 0:

  Queue          Visited          Action                  Output
  ----------------------------------------------------------------
  [0]            {0}              Start: push source 0
  [1, 2]         {0,1,2}          Pop 0, push 1,2         0
  [2, 3, 4]      {0,1,2,3,4}      Pop 1, push 3,4         0 1
  [3, 4]         {0,1,2,3,4}      Pop 2, 4 already visited 0 1 2
  [4, 5]         {0,1,2,3,4,5}    Pop 3, push 5           0 1 2 3
  [5]            {0,1,2,3,4,5}    Pop 4, 5 already visited 0 1 2 3 4
  []             {0,1,2,3,4,5}    Pop 5, no new neighbors  0 1 2 3 4 5

  Queue empty → BFS complete!
```

---

## Why Mark Visited When Pushing?

```cpp
// CORRECT: Mark visited when pushing
for(int child : adj_list[parent]){
    if(!visited[child]){
        q.push(child);
        visited[child] = true;    // mark here to avoid duplicates
    }
}

// WRONG: Mark visited when popping
// This causes same node to be pushed multiple times
```

**Example of duplicate push without immediate marking:**
```
If nodes 1 and 2 both connect to 4:

    1 ---- 4           Without immediate marking:
           |             Pop 1 → push 4        Queue: [2, 4]
    2 -----+             Pop 2 → push 4 again! Queue: [4, 4] ← DUPLICATE!

                        With immediate marking:
                         Pop 1 → push 4, mark 4  Queue: [2, 4]
                         Pop 2 → 4 visited, skip  Queue: [4] ← CORRECT!
```

---

# BFS Applications

## 1. Check if Node is Reachable
**Check if destination is reachable from source**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);                     // push source node
    visited[src] = true;             // mark source visited

    while(!q.empty()){
        // 1. Bring out front
        int parent = q.front();      // get front node
        q.pop();                     // remove from queue

        // 2. Work with this
        cout << parent << " ";       // print current node

        // 3. Push unvisited children
        for(int child : adj_list[parent]){    // go through neighbors
            if(!visited[child]){              // if not visited
                q.push(child);                // push to queue
                visited[child] = true;        // mark visited
            }
        }
    }
    cout << endl;
}

int main() {
    int n, e;
    cin >> n >> e;                   // n = nodes, e = edges

    while(e--){
        int a, b;
        cin >> a >> b;               // read edge
        adj_list[a].push_back(b);    // add to list
        adj_list[b].push_back(a);    // undirected
    }
    
    memset(visited, false, sizeof(visited));  // initialize visited
    
    int source, destination;
    cin >> source >> destination;    // read source and destination
    
    bfs(source);                     // run BFS from source

    // After BFS, check if destination was visited
    if(visited[destination]){
        cout << "Yes" << endl;          // reachable
    } else {
        cout << "No" << endl;           // not reachable
    }
    
    return 0;
}
```

**Diagram:**
```
    0 ---- 1        5 ---- 6
    |      |        (disconnected)
    3 ---- 2

  Source: 0, Destination: 2 → Yes (reachable)
  Source: 0, Destination: 5 → No  (not reachable, different component)
```
```

**Use Cases:**
- Check connectivity between two nodes
- Check if graph is connected

---

## 2. Single Source Shortest Distance
**Find shortest distance from source to all nodes (unweighted graph)**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];
int level[1005];                        // level[i] = distance from source to i

void bfs(int src){
    queue<int> q;
    q.push(src);                        // push source
    visited[src] = true;                // mark source visited
    level[src] = 0;                     // source is at distance 0

    while(!q.empty()){
        // 1. Bring out front
        int parent = q.front();         // get front node
        q.pop();                        // remove from queue

        // 2. Work with this (nothing to print here)

        // 3. Push unvisited children
        for(int child : adj_list[parent]){
            if(!visited[child]){
                q.push(child);                      // push to queue
                visited[child] = true;              // mark visited
                level[child] = level[parent] + 1;   // child is 1 step away from parent
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;                      // n = nodes, e = edges

    while(e--){
        int a, b;
        cin >> a >> b;                  // read edge
        adj_list[a].push_back(b);       // add to list
        adj_list[b].push_back(a);       // undirected
    }
    
    memset(visited, false, sizeof(visited));  // initialize visited
    memset(level, -1, sizeof(level));         // -1 means not reachable
    
    int src, destination;
    cin >> src >> destination;          // read source and destination
    
    bfs(src);                           // run BFS
    
    cout << level[destination] << endl;  // shortest distance to destination

    return 0;
}
```

**Diagram: How Level Works**
```
    0 ---- 1 ---- 3          level[0] = 0   (source)
    |      |      |          level[1] = 1   (1 edge from 0)
    2 ---- 4 ---- 5          level[2] = 1   (1 edge from 0)
                              level[3] = 2   (2 edges from 0)
  Source: 0                   level[4] = 2   (2 edges from 0)
  Destination: 5              level[5] = 3   (3 edges from 0)
                    
  Shortest distance 0 → 5 = level[5] = 3
  Path: 0 → 1 → 3 → 5
```

---

## 3. Path Printing
**Print the actual path from source to destination**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];
int level[1005];
int parent[1005];                       // parent[i] = who discovered i

void bfs(int src){
    queue<int> q;
    q.push(src);                        // push source
    visited[src] = true;                // mark visited
    level[src] = 0;                     // source at level 0

    while(!q.empty()){
        // 1. Bring out front
        int par = q.front();            // get front node
        q.pop();                        // remove from queue

        // 2. Work with this (nothing to print here)

        // 3. Push unvisited children
        for(int child : adj_list[par]){
            if(!visited[child]){
                q.push(child);                    // push child
                visited[child] = true;            // mark visited
                level[child] = level[par] + 1;    // set distance
                parent[child] = par;              // remember who discovered this child
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;                      // n = nodes, e = edges

    while(e--){
        int a, b;
        cin >> a >> b;                  // read edge
        adj_list[a].push_back(b);       // add to list
        adj_list[b].push_back(a);       // undirected
    }

    memset(visited, false, sizeof(visited));  // initialize visited
    memset(level, -1, sizeof(level));         // -1 = not reachable
    memset(parent, -1, sizeof(parent));       // -1 means no parent (source)

    int src, destination;
    cin >> src >> destination;          // read source and destination
    
    bfs(src);                           // run BFS

    // Backtrack from destination to source using parent array
    vector<int> path;
    int node = destination;
    
    while(node != -1){                  // keep going until source (parent = -1)
        path.push_back(node);           // add current node to path
        node = parent[node];            // go to parent
    }
    
    reverse(path.begin(), path.end());  // reverse: destination→source becomes source→destination

    // Print path
    for(int i : path){
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
```

**Input:**
```
6 7
0 1
0 2
1 3
1 4
2 4
3 5
4 5
0 5
```

**Output:** `0 1 3 5` (one of the shortest paths)

**How Path Backtracking Works:**
```
  Graph:                     Parent Array after BFS(0):
    0 ---- 1 ---- 3          parent[0] = -1 (source, no parent)
    |      |      |          parent[1] = 0   (discovered by 0)
    2 ---- 4 ---- 5          parent[2] = 0   (discovered by 0)
                              parent[3] = 1   (discovered by 1)
                              parent[4] = 1   (discovered by 1)
                              parent[5] = 3   (discovered by 3)

  Backtrack path 0 → 5:
    Start at 5 → parent[5]=3 → parent[3]=1 → parent[1]=0 → parent[0]=-1 (STOP)
    Collected: [5, 3, 1, 0]
    Reversed:  [0, 1, 3, 5]  ← Shortest path!
```

---

## 4. Connected Components
**Count number of connected components in graph**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool visited[1005];

void bfs(int src){
    queue<int> q;
    q.push(src);                     // push source
    visited[src] = true;             // mark visited

    while(!q.empty()){
        int parent = q.front();      // get front
        q.pop();                     // remove

        for(int child : adj_list[parent]){   // visit neighbors
            if(!visited[child]){
                q.push(child);               // push unvisited
                visited[child] = true;       // mark visited
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;                   // n = nodes, e = edges

    while(e--){
        int a, b;
        cin >> a >> b;               // read edge
        adj_list[a].push_back(b);    // add to list
        adj_list[b].push_back(a);    // undirected
    }
    
    memset(visited, false, sizeof(visited));  // initialize visited

    int components = 0;              // count components
    
    for(int i = 0; i < n; i++){      // check every node
        if(!visited[i]){             // if node is unvisited
            bfs(i);                  // start new BFS → new component found
            components++;            // increment component count
        }
    }
    
    cout << "Number of components: " << components << endl;
    
    return 0;
}
```

**Diagram:**
```
  Component 1:       Component 2:       Component 3:
    0 ---- 1           4 ---- 5           7
    |      |                              (isolated)
    3 ---- 2           6

  Total Components: 3

  BFS(0) → visits {0,1,2,3}  → components = 1
  BFS(4) → visits {4,5,6}    → components = 2
  BFS(7) → visits {7}        → components = 3
```
```

**Use Cases:**
- Check if graph is connected (components == 1)
- Find isolated nodes
- Network analysis

---

## 5. Bipartite Check
**Check if graph can be colored with 2 colors**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
int color[1005];                        // -1 = uncolored, 0 or 1 = color

bool bfs_bipartite(int src){
    queue<int> q;
    q.push(src);                         // push source
    color[src] = 0;                      // color source with 0

    while(!q.empty()){
        int parent = q.front();          // get front
        q.pop();                         // remove

        for(int child : adj_list[parent]){       // visit neighbors
            if(color[child] == -1){
                // uncolored → give opposite color of parent
                color[child] = 1 - color[parent];
                q.push(child);
            }
            else if(color[child] == color[parent]){
                // same color as parent → conflict → not bipartite
                return false;
            }
        }
    }
    return true;                         // no conflict found
}

int main() {
    int n, e;
    cin >> n >> e;                       // n = nodes, e = edges

    while(e--){
        int a, b;
        cin >> a >> b;                   // read edge
        adj_list[a].push_back(b);        // add to list
        adj_list[b].push_back(a);        // undirected
    }
    
    memset(color, -1, sizeof(color));    // all uncolored initially

    bool is_bipartite = true;
    
    for(int i = 0; i < n; i++){          // check all components
        if(color[i] == -1){              // if uncolored
            if(!bfs_bipartite(i)){       // check bipartiteness
                is_bipartite = false;
                break;
            }
        }
    }
    
    if(is_bipartite){
        cout << "Graph is Bipartite" << endl;
    } else {
        cout << "Graph is NOT Bipartite" << endl;
    }
    
    return 0;
}
```

**Diagram:**
```
  Bipartite (YES):                Not Bipartite (NO):

    0(R) ---- 1(B)                  0(R) ---- 1(B)
    |          |                    |  \       |
    |          |                    |    \     |
    3(B) ---- 2(R)                  3(B) ---- 2(R)
                                        \
  Set A (Red):  {0, 2}                    Odd cycle: 0-1-2-3-0
  Set B (Blue): {1, 3}                    Cannot 2-color!
  No edge within same set ✓
```

**Bipartite Property:**
- Graph with no odd-length cycle
- Can divide vertices into two sets where no edge is within same set

---

# Complete Examples

## Example 1: BFS Template
**Standard BFS template for competitive programming**

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;                   // max nodes (100005)
vector<int> adj[N];                      // adjacency list
bool visited[N];                         // track visited nodes
int dist[N];                             // distance from source
int parent[N];                           // parent of each node in BFS tree

void bfs(int src){
    queue<int> q;                        // create queue for BFS
    q.push(src);                         // push source node
    visited[src] = true;                 // mark source as visited
    dist[src] = 0;                       // distance of source is 0
    parent[src] = -1;                    // source has no parent

    while(!q.empty()){                   // process until queue is empty
        int u = q.front();               // get front node
        q.pop();                         // remove from queue

        for(int v : adj[u]){             // iterate over all neighbors of u
            if(!visited[v]){             // if neighbor is not visited
                visited[v] = true;       // mark as visited
                dist[v] = dist[u] + 1;   // distance = parent's distance + 1
                parent[v] = u;           // set parent for path reconstruction
                q.push(v);               // push to queue for processing
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);    // fast I/O
    cin.tie(NULL);                       // untie cin from cout
    
    int n, e;
    cin >> n >> e;                       // read number of nodes and edges

    for(int i = 0; i < e; i++){          // read all edges
        int a, b;
        cin >> a >> b;                   // read edge a-b
        adj[a].push_back(b);             // add b to a's neighbor list
        adj[b].push_back(a);             // add a to b's neighbor list (undirected)
    }

    memset(visited, false, sizeof(visited));  // all nodes unvisited
    memset(dist, -1, sizeof(dist));           // -1 = unreachable
    memset(parent, -1, sizeof(parent));       // -1 = no parent

    bfs(0);                              // start BFS from node 0

    // Print distances from source 0 to all nodes
    for(int i = 0; i < n; i++){
        cout << "Distance to " << i << ": " << dist[i] << endl;
    }

    return 0;
}
```

---

## Example 2: 2D Grid BFS
**Find shortest path in a grid**

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;                                // grid dimensions
char grid[105][105];                     // 2D grid
bool visited[105][105];                  // track visited cells
int dist[105][105];                      // distance from start

// Direction arrays for 4 directions: up, right, down, left
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// Check if cell (x,y) is valid to visit
bool isValid(int x, int y){
    return x >= 0 && x < n &&            // within row bounds
           y >= 0 && y < m &&            // within column bounds
           grid[x][y] != '#' &&          // not a wall
           !visited[x][y];               // not already visited
}

int bfs(int startX, int startY, int endX, int endY){
    queue<pair<int,int>> q;              // queue of (row, col) pairs
    q.push({startX, startY});            // push starting cell
    visited[startX][startY] = true;      // mark start as visited
    dist[startX][startY] = 0;            // distance of start is 0

    while(!q.empty()){
        auto [x, y] = q.front();         // get front cell (structured binding)
        q.pop();                         // remove from queue

        // Check if we reached the destination
        if(x == endX && y == endY){
            return dist[x][y];           // return shortest distance
        }

        // Explore all 4 directions: up, right, down, left
        for(int i = 0; i < 4; i++){
            int newX = x + dx[i];        // new row after moving
            int newY = y + dy[i];        // new col after moving

            if(isValid(newX, newY)){              // if valid cell
                visited[newX][newY] = true;       // mark visited
                dist[newX][newY] = dist[x][y] + 1; // distance = parent + 1
                q.push({newX, newY});             // push to queue
            }
        }
    }
    return -1;                           // destination not reachable
}

int main() {
    cin >> n >> m;                       // read grid dimensions
    
    int startX, startY, endX, endY;      // start and end coordinates
    
    // Read grid and find S (start) and E (end)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];           // read each cell
            if(grid[i][j] == 'S'){       // found start
                startX = i; startY = j;
            }
            if(grid[i][j] == 'E'){       // found end
                endX = i; endY = j;
            }
        }
    }

    memset(visited, false, sizeof(visited));  // all cells unvisited
    memset(dist, -1, sizeof(dist));           // -1 = unreachable

    int result = bfs(startX, startY, endX, endY);  // run BFS
    cout << result << endl;              // print shortest distance

    return 0;
}
```

**Grid Diagram:**
```
    0   1   2   3   4
  +---+---+---+---+---+
0 | S | . | . | . | . |     S = Start (0,0)
  +---+---+---+---+---+     E = End   (4,4)
1 | # | # | # | . | # |     # = Wall  (blocked)
  +---+---+---+---+---+     . = Open   (can walk)
2 | . | . | . | . | . |
  +---+---+---+---+---+
3 | . | # | # | # | # |
  +---+---+---+---+---+
4 | . | . | . | . | E |
  +---+---+---+---+---+

  Direction Array:         Shortest Path:
  dx = {-1, 0, 1, 0}      S → → → ↓
  dy = { 0, 1, 0,-1}      # # #   #
                           ← ← ← ← 
  (-1,0)=Up                ↓ # # # #
  (0,+1)=Right             → → → → E
  (+1,0)=Down
  (0,-1)=Left              Distance = 8
```

---

## Example 3: Multi-Source BFS
**BFS from multiple sources simultaneously**

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;                                // grid dimensions
char grid[105][105];                     // 2D grid
int dist[105][105];                      // distance from nearest source

// Direction arrays for 4 directions
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    cin >> n >> m;                       // read grid dimensions
    
    queue<pair<int,int>> q;              // queue for BFS
    
    // Read grid and push all sources to queue
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];           // read each cell
            
            if(grid[i][j] == '1'){       // source cell found
                q.push({i, j});          // push ALL sources initially
                dist[i][j] = 0;          // source is at distance 0
            } else {
                dist[i][j] = -1;         // -1 = not visited yet
            }
        }
    }

    // BFS from all sources simultaneously
    while(!q.empty()){
        auto [x, y] = q.front();         // get front cell
        q.pop();                         // remove from queue

        for(int i = 0; i < 4; i++){      // explore 4 directions
            int nx = x + dx[i];          // new row
            int ny = y + dy[i];          // new col

            // Check bounds and if not visited
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;  // distance from nearest source
                q.push({nx, ny});                // push to queue
            }
        }
    }

    // Print minimum distance to nearest source for each cell
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << dist[i][j] << " ";   // print distance
        }
        cout << endl;
    }

    return 0;
}
```

**Diagram: Multi-Source BFS**
```
  Input Grid:              Distance Result:
  +---+---+---+---+       +---+---+---+---+
  | 1 | 0 | 0 | 0 |       | 0 | 1 | 2 | 3 |
  +---+---+---+---+       +---+---+---+---+
  | 0 | 0 | 0 | 0 |       | 1 | 2 | 3 | 2 |
  +---+---+---+---+       +---+---+---+---+
  | 0 | 0 | 0 | 1 |       | 2 | 2 | 1 | 0 |
  +---+---+---+---+       +---+---+---+---+

  Sources (1) start at distance 0
  Each cell gets distance to nearest source
  Both sources expand simultaneously in queue
```
```

**Use Cases:**
- Find nearest facility (hospital, fire station)
- Rotten oranges problem
- Flood fill with multiple starting points

---

# Comparison and Time Complexity

## BFS vs DFS

```
  BFS (Level by Level):           DFS (Go Deep First):

  Visit: 0 → 1 → 2 → 3 → 4 → 5     Visit: 0 → 1 → 3 → 5 → 4 → 2

       0                                0
      / \                              / \
     1   2     BFS: level 0,1,2       1   2     DFS: go deep
    / \   \                          / \   \
   3   4   5                        3   4   5
```

| Feature | BFS | DFS |
|---------|-----|-----|
| **Data Structure** | Queue (FIFO) | Stack/Recursion (LIFO) |
| **Exploration** | Level by level | Go deep first |
| **Shortest Path** | ✅ Yes (unweighted) | ❌ No |
| **Memory** | O(width) | O(height) |
| **Use Case** | Shortest path, level order | Cycle detection, topological sort |
| **Implementation** | Iterative | Recursive or Iterative |

---

## Time and Space Complexity

| Operation | Time | Space |
|-----------|------|-------|
| **BFS Traversal** | O(V + E) | O(V) |
| **Shortest Distance** | O(V + E) | O(V) |
| **Path Finding** | O(V + E) | O(V) |
| **Connected Components** | O(V + E) | O(V) |

Where:
- V = Number of vertices
- E = Number of edges

---

## When to Use BFS?

✅ **Use BFS when:**
- Finding shortest path in **unweighted** graph
- Level order traversal
- Finding nearest/closest node
- Checking connectivity
- Bipartite checking
- Multi-source shortest path

❌ **Avoid BFS when:**
- Graph has **weighted** edges (use Dijkstra)
- Need to explore all paths (use DFS)
- Memory is limited (DFS uses less for deep graphs)

---

## Common Mistakes to Avoid

1. ❌ Marking visited when **popping** instead of **pushing**
   ```cpp
   // WRONG
   int node = q.front();
   q.pop();
   visited[node] = true;  // Too late! May have duplicates
   
   // CORRECT
   q.push(child);
   visited[child] = true; // Mark immediately when pushing
   ```

2. ❌ Forgetting to initialize visited array
   ```cpp
   memset(visited, false, sizeof(visited));  // Don't forget!
   ```

3. ❌ Not handling disconnected components
   ```cpp
   // Need to run BFS for each unvisited node
   for(int i = 0; i < n; i++){
       if(!visited[i]){
           bfs(i);
       }
   }
   ```

4. ❌ Using BFS for weighted shortest path (use Dijkstra instead)

5. ❌ Forgetting direction arrays for grid BFS
   ```cpp
   int dx[] = {-1, 0, 1, 0};
   int dy[] = {0, 1, 0, -1};
   ```

---

## BFS Template Summary

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[N];
bool visited[N];
int dist[N];
int parent[N];

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src] = 0;
    parent[src] = -1;

    while(!q.empty()){
        int u = q.front();          // 1. Bring out
        q.pop();

        // Process node u here      // 2. Work with node

        for(int v : adj[u]){        // 3. Push children
            if(!visited[v]){
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}
```

---

## Applications Summary

| Application | What to Track |
|-------------|---------------|
| **Traversal** | visited[] |
| **Shortest Distance** | visited[], dist[] |
| **Path Printing** | visited[], parent[] |
| **Connected Components** | visited[], component count |
| **Bipartite Check** | color[] |
| **Level-wise Processing** | level[] or process by queue size |

---

## Important Notes

1. **BFS guarantees shortest path** in unweighted graphs
2. **Mark visited when pushing**, not when popping
3. **Use adjacency list** for most problems (efficient)
4. **Direction arrays** simplify grid BFS
5. **Multi-source BFS**: push all sources initially
6. **Parent array** enables path reconstruction
7. **Level array** gives distance from source
