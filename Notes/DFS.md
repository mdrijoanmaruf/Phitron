# DFS (Depth First Search) - Complete Notes

## Table of Contents
1. [Introduction to DFS](#introduction-to-dfs)
2. [DFS Algorithm](#dfs-algorithm)
3. [DFS Applications](#dfs-applications)
4. [DFS on 2D Grid](#dfs-on-2d-grid)
5. [Complete Examples](#complete-examples)
6. [DFS vs BFS Comparison](#dfs-vs-bfs-comparison)

---

# Introduction to DFS

## What is DFS?
**Depth First Search (DFS) is a graph traversal algorithm that explores as deep as possible before backtracking**

```
  DFS explores one path fully before trying another:

       0                  Visit Order: 0 → 1 → 3 → 4 → 2 → 5
      / \
     1   2                DFS goes deep:
    / \   \                0 → 1 → 3 (dead end, backtrack)
   3   4   5                       → 4 (dead end, backtrack)
                                → 2 → 5 (dead end, done)
```

**Key Characteristics:**
- Uses **Recursion** (or Stack) - LIFO behavior
- Goes as deep as possible before backtracking
- Time Complexity: O(V + E)
- Space Complexity: O(V)

**DFS vs BFS:**
```
  DFS (Go Deep First):            BFS (Level by Level):

  Visit: 0 → 1 → 3 → 4 → 2 → 5   Visit: 0 → 1 → 2 → 3 → 4 → 5

       0                                0
      / \                              / \
     1   2     DFS: dive deep         1   2     BFS: spread wide
    / \   \                          / \   \
   3   4   5                        3   4   5
```

---

# DFS Algorithm

## Basic DFS Implementation (Recursive)
**Traverse graph using DFS starting from source**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];         // adjacency list (global, max 1005 nodes)
bool visited[1005];                  // track visited nodes (avoid revisiting)

void dfs(int src){
    cout << src << " ";              // 1. Process current node (print it)
    visited[src] = true;             // 2. Mark current node as visited

    for(int child : adj_list[src]){         // 3. Visit all neighbors
        if(visited[child] == false){        // if neighbor not visited
            dfs(child);                     // recursively visit it (go deeper)
        }
    }
    // When all neighbors are visited, function returns (backtrack)
}

int main() {
    // Input Vertex, Edge
    int n, e;
    cin >> n >> e;                   // n = nodes, e = edges

    // Input Graph
    while(e--){
        int a, b;
        cin >> a >> b;               // read edge
        adj_list[a].push_back(b);    // add to adjacency list
        adj_list[b].push_back(a);    // undirected graph
    }

    memset(visited, false, sizeof(visited));  // initialize all as unvisited

    // Call DFS from node 0
    dfs(0);

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

**Output:** `0 1 3 5 4 2` (one possible order, depends on adjacency list order)

---

## DFS Step-by-Step Process

```
  Graph:
      0 ---- 1 ---- 3
      |      |      |
      2 ---- 4 ---- 5

  DFS from 0:

  Call Stack          Visited           Action                    Output
  ─────────────────────────────────────────────────────────────────────────
  dfs(0)              {0}               Visit 0, go to neighbor 1   0
  dfs(0)→dfs(1)       {0,1}             Visit 1, go to neighbor 3   0 1
  dfs(0)→dfs(1)→dfs(3){0,1,3}           Visit 3, go to neighbor 5   0 1 3
  →dfs(3)→dfs(5)      {0,1,3,5}         Visit 5, neighbor 4         0 1 3 5
  →dfs(5)→dfs(4)      {0,1,3,4,5}       Visit 4, neighbor 2         0 1 3 5 4
  →dfs(4)→dfs(2)      {0,1,2,3,4,5}     Visit 2, all visited        0 1 3 5 4 2
  backtrack...         {0,1,2,3,4,5}     All returned                0 1 3 5 4 2

  Recursion Tree:
      dfs(0)
      ├── dfs(1)
      │   ├── dfs(3)
      │   │   └── dfs(5)
      │   │       └── dfs(4)
      │   │           └── dfs(2) ← backtrack (all neighbors visited)
      │   └── (4 already visited, skip)
      └── (2 already visited, skip)
```

---

## Iterative DFS Using Stack
**DFS can also be implemented using explicit stack**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];         // adjacency list
bool visited[1005];                  // track visited nodes

void dfs_iterative(int src){
    stack<int> st;                   // use stack instead of recursion
    st.push(src);                    // push source

    while(!st.empty()){
        int node = st.top();         // get top of stack
        st.pop();                    // remove from stack

        if(visited[node]) continue;  // skip if already visited
        
        visited[node] = true;        // mark as visited
        cout << node << " ";         // process node

        // Push all unvisited neighbors to stack
        for(int child : adj_list[node]){
            if(!visited[child]){
                st.push(child);      // push neighbor
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

    memset(visited, false, sizeof(visited));  // all unvisited

    dfs_iterative(0);                // start DFS from node 0
    return 0;
}
```

**Note:** Iterative DFS may visit nodes in different order than recursive DFS because stack reverses the order of neighbors.

---

# DFS Applications

## 1. Connected Components
**Count number of connected components in graph**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];         // adjacency list
bool visited[1005];                  // track visited nodes

void dfs(int src){
    cout << src << " ";              // print current node
    visited[src] = true;             // mark visited

    for(int child : adj_list[src]){         // visit neighbors
        if(visited[child] == false){        // if not visited
            dfs(child);                     // go deeper
        }
    }
}

int main() {
    // Input Vertex, Edge
    int n, e;
    cin >> n >> e;                   // n = nodes, e = edges

    // Input Graph
    while(e--){
        int a, b;
        cin >> a >> b;               // read edge
        adj_list[a].push_back(b);    // add to list
        adj_list[b].push_back(a);    // undirected
    }

    memset(visited, false, sizeof(visited));  // all unvisited

    // Run DFS for each unvisited node → each DFS = one component
    int components = 0;
    for(int i = 0; i < n; i++){
        if(visited[i] == false){     // if node not yet visited
            dfs(i);                  // start new DFS → new component
            cout << endl;            // separate components
            components++;            // count component
        }
    }
    
    cout << "Components: " << components << endl;

    return 0;
}
```

**Diagram:**
```
  Component 1:       Component 2:       Component 3:
    0 ---- 1           4 ---- 5           7
    |      |                              (isolated)
    3 ---- 2           6

  DFS(0) → visits {0,1,2,3}   → components = 1
  DFS(4) → visits {4,5,6}     → components = 2
  DFS(7) → visits {7}         → components = 3

  Total Components: 3
  Graph is connected only if components == 1
```

---

## 2. Cycle Detection (Undirected Graph)
**Detect if graph has a cycle using DFS**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];         // adjacency list
bool visited[1005];                  // track visited nodes

bool dfs_cycle(int src, int parent){
    visited[src] = true;             // mark current as visited

    for(int child : adj_list[src]){         // visit neighbors
        if(!visited[child]){                // not visited → go deeper
            if(dfs_cycle(child, src)){      // pass current as parent
                return true;                // cycle found deeper
            }
        }
        else if(child != parent){           // visited AND not parent
            return true;                    // CYCLE DETECTED!
        }
    }
    return false;                    // no cycle found from this node
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

    memset(visited, false, sizeof(visited));  // all unvisited

    bool has_cycle = false;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(dfs_cycle(i, -1)){    // -1 = no parent for source
                has_cycle = true;
                break;
            }
        }
    }

    if(has_cycle){
        cout << "Cycle exists!" << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}
```

**Diagram: Why parent check is needed**
```
  Without parent check:           With parent check:

    0 ---- 1                        0 ---- 1
                                    
  dfs(0) → visits 1                dfs(0, -1) → visits 1
  dfs(1) → sees 0 (visited!)      dfs(1, 0)  → sees 0 (visited)
           → FALSE CYCLE!                     → but 0 is parent, SKIP!
                                              → No false cycle ✓

  Real cycle example:
    0 ---- 1
    |      |              dfs(0, -1) → dfs(1, 0) → dfs(2, 1)
    3 ---- 2              dfs(2, 1) sees 0: visited AND not parent(1)
                          → CYCLE DETECTED! (0-1-2-3-0)
```

---

## 3. Path Finding
**Find path from source to destination**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];         // adjacency list
bool visited[1005];                  // track visited nodes
int parent[1005];                    // store parent of each node

void dfs(int src){
    visited[src] = true;             // mark visited

    for(int child : adj_list[src]){         // visit neighbors
        if(!visited[child]){                // if not visited
            parent[child] = src;            // set parent
            dfs(child);                     // go deeper
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

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));   // -1 = no parent

    int src, dest;
    cin >> src >> dest;              // read source and destination

    dfs(src);                        // run DFS from source

    if(!visited[dest]){
        cout << "Not reachable" << endl;
        return 0;
    }

    // Backtrack from destination to source
    vector<int> path;
    int node = dest;
    while(node != -1){               // go until source (parent = -1)
        path.push_back(node);        // add to path
        node = parent[node];         // go to parent
    }

    reverse(path.begin(), path.end());  // reverse to get src → dest

    for(int x : path){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
```

**Note:** DFS does NOT guarantee shortest path (unlike BFS).

---

## 4. Topological Sort (Directed Acyclic Graph)
**Order vertices such that for every edge u→v, u comes before v**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];         // adjacency list (directed graph)
bool visited[1005];                  // track visited nodes
stack<int> topo_order;               // store topological order

void dfs(int src){
    visited[src] = true;             // mark visited

    for(int child : adj_list[src]){         // visit neighbors
        if(!visited[child]){                // if not visited
            dfs(child);                     // go deeper
        }
    }
    
    topo_order.push(src);            // push to stack AFTER all children done
}

int main() {
    int n, e;
    cin >> n >> e;                   // n = nodes, e = edges

    while(e--){
        int a, b;
        cin >> a >> b;               // directed edge a → b
        adj_list[a].push_back(b);    // only one direction!
    }

    memset(visited, false, sizeof(visited));  // all unvisited

    // Run DFS for all unvisited nodes
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    // Print topological order (pop from stack)
    while(!topo_order.empty()){
        cout << topo_order.top() << " ";
        topo_order.pop();
    }
    cout << endl;

    return 0;
}
```

**Diagram:**
```
  Directed Graph (DAG):           Topological Order:
    0 → 1 → 3                      0, 2, 1, 4, 3, 5
    ↓       ↓                     
    2 → 4 → 5                    Every edge goes left to right:
                                    0 → 1 → 3
  DFS finishes:                     0 → 2 → 4 → 5
  5 first, then 3, then 4,         1 → 3, 4 → 5
  then 1, then 2, then 0
  Stack (bottom→top): 0,2,1,4,3,5
  Pop order: 0,2,1,4,3,5 ← valid topological order
```

---

# DFS on 2D Grid

## Basic 2D Grid DFS
**Traverse a grid using DFS with 4 directions**

```cpp
#include <bits/stdc++.h>
using namespace std;

char grid[105][105];                 // 2D grid
bool visited[105][105];              // track visited cells
int n, m;                            // grid dimensions

// Direction vectors: up, down, left, right
vector<pair<int,int>> d = {{-1,0}, {1,0}, {0,-1}, {0,1}};

// Check if cell (i,j) is within grid bounds
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;                // out of bounds
    }
    else {
        return true;                 // valid cell
    }
}

void dfs(int si, int sj){
    cout << si << " " << sj << endl; // process current cell
    visited[si][sj] = true;          // mark as visited

    for(int i = 0; i < 4; i++){      // try all 4 directions
        int ci = si + d[i].first;    // new row after moving
        int cj = sj + d[i].second;   // new col after moving
        if(valid(ci, cj) && !visited[ci][cj]){  // valid and unvisited
            dfs(ci, cj);             // go deeper into that cell
        }
    }
}

int main() {
    cin >> n >> m;                    // read grid dimensions
    
    // Read grid
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];        // read each cell
        }
    }

    int si, sj;
    cin >> si >> sj;                  // read starting position
    
    memset(visited, false, sizeof(visited));  // all cells unvisited

    dfs(si, sj);                      // start DFS from (si, sj)
    return 0;
}
```

**Diagram: DFS on Grid**
```
    Grid (3x3):            Direction Vectors:
    +---+---+---+            (-1, 0) = Up
    | . | . | . |  row 0     (+1, 0) = Down
    +---+---+---+            ( 0,-1) = Left
    | . | S | . |  row 1     ( 0,+1) = Right
    +---+---+---+
    | . | . | . |  row 2   DFS from S (1,1):
    +---+---+---+           Goes deep: (1,1)→(0,1)→(0,0)→(1,0)→(2,0)→(2,1)→...
    col: 0   1   2          Explores one path fully before backtracking
```

---

## Count Islands (Classic DFS Problem)
**Count number of islands in a grid**

```cpp
#include <bits/stdc++.h>
using namespace std;

char grid[105][105];                 // grid: '1' = land, '0' = water
bool visited[105][105];              // track visited cells
int n, m;                            // grid dimensions

// Direction vectors for 4 directions
vector<pair<int,int>> d = {{-1,0}, {1,0}, {0,-1}, {0,1}};

// Check if cell is valid
bool valid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

// DFS to visit all connected land cells (one full island)
void dfs(int si, int sj){
    visited[si][sj] = true;          // mark as visited

    for(int i = 0; i < 4; i++){      // try all 4 directions
        int ci = si + d[i].first;    // new row
        int cj = sj + d[i].second;   // new col
        // Valid, unvisited, and is land ('1')
        if(valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '1'){
            dfs(ci, cj);             // continue exploring island
        }
    }
}

int main() {
    cin >> n >> m;                    // read grid dimensions
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];        // read each cell
        }
    }

    memset(visited, false, sizeof(visited));  // all unvisited

    int islands = 0;                  // count islands
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // Found unvisited land → new island!
            if(!visited[i][j] && grid[i][j] == '1'){
                dfs(i, j);           // DFS marks entire island as visited
                islands++;            // count this island
            }
        }
    }

    cout << "Number of islands: " << islands << endl;

    return 0;
}
```

**Diagram:**
```
  Grid:                        Islands:
  +---+---+---+---+---+         Island 1: top-left
  | 1 | 1 | 0 | 0 | 0 |         (0,0)(0,1)(1,0)(1,1)
  +---+---+---+---+---+
  | 1 | 1 | 0 | 0 | 0 |       Island 2: right
  +---+---+---+---+---+         (0,3)(0,4)(1,4)
  | 0 | 0 | 0 | 1 | 1 |
  +---+---+---+---+---+       Island 3: bottom
  | 0 | 0 | 0 | 0 | 1 |         (2,3)(2,4)(3,4)
  +---+---+---+---+---+
                                Total: 3 islands
  DFS(0,0) → visits entire island 1 → islands = 1
  DFS(0,3) → visits entire island 2 → islands = 2
  DFS(2,3) → visits entire island 3 → islands = 3
```

---

## Flood Fill
**Fill connected region with new color (like paint bucket tool)**

```cpp
#include <bits/stdc++.h>
using namespace std;

int grid[105][105];                  // grid with colors
int n, m;                            // grid dimensions

vector<pair<int,int>> d = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool valid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

// Fill all connected cells of oldColor with newColor
void flood_fill(int si, int sj, int oldColor, int newColor){
    if(!valid(si, sj)) return;                // out of bounds
    if(grid[si][sj] != oldColor) return;      // not same color
    if(grid[si][sj] == newColor) return;       // already filled
    
    grid[si][sj] = newColor;          // fill current cell with new color

    for(int i = 0; i < 4; i++){      // try all 4 directions
        int ci = si + d[i].first;    // new row
        int cj = sj + d[i].second;   // new col
        flood_fill(ci, cj, oldColor, newColor);  // fill neighbors
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    int si, sj, newColor;
    cin >> si >> sj >> newColor;      // start position and new color
    
    int oldColor = grid[si][sj];      // old color to replace
    flood_fill(si, sj, oldColor, newColor);

    // Print result
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

**Diagram:**
```
  Before:                    After (flood fill from (1,1), newColor=3):
  +---+---+---+---+         +---+---+---+---+
  | 1 | 1 | 1 | 0 |         | 3 | 3 | 3 | 0 |    All connected 1s
  +---+---+---+---+         +---+---+---+---+    starting from (1,1)
  | 1 | 1 | 0 | 0 |         | 3 | 3 | 0 | 0 |    are replaced with 3
  +---+---+---+---+         +---+---+---+---+
  | 1 | 0 | 0 | 2 |         | 3 | 0 | 0 | 2 |    0s and 2s unchanged
  +---+---+---+---+         +---+---+---+---+
```

---

# Complete Examples

## Example 1: Complete DFS with All Features
**DFS with visited tracking, component counting, and entry/exit times**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];         // adjacency list (global array of vectors)
bool visited[1005];                  // track if node is visited
int entry_time[1005];                // when DFS enters this node
int exit_time[1005];                 // when DFS exits (backtracks from) this node
int timer_count = 0;                 // global timer for entry/exit

// DFS function: src = current node being visited
void dfs(int src){
    visited[src] = true;             // mark current node as visited
    entry_time[src] = timer_count++; // record entry time and increment timer
    
    cout << "Enter: " << src << " (time=" << entry_time[src] << ")" << endl;

    // Explore all neighbors of current node
    for(int child : adj_list[src]){
        if(visited[child] == false){        // only visit unvisited neighbors
            dfs(child);                     // recursive call → go deeper
        }
    }
    
    // All neighbors explored → backtracking now
    exit_time[src] = timer_count++;  // record exit time
    cout << "Exit:  " << src << " (time=" << exit_time[src] << ")" << endl;
}

int main() {
    int n, e;
    cin >> n >> e;                   // read number of nodes and edges

    // Build adjacency list from input edges
    while(e--){
        int a, b;
        cin >> a >> b;               // read edge between a and b
        adj_list[a].push_back(b);    // add b as neighbor of a
        adj_list[b].push_back(a);    // add a as neighbor of b (undirected)
    }

    // Initialize all nodes as unvisited
    memset(visited, false, sizeof(visited));

    // Count connected components
    int components = 0;
    for(int i = 0; i < n; i++){              // check every node
        if(visited[i] == false){             // if not yet visited
            cout << "--- Component " << components + 1 << " ---" << endl;
            dfs(i);                          // DFS will visit all nodes in this component
            components++;                    // increment component count
        }
    }
    
    cout << "\nTotal components: " << components << endl;

    // Print entry/exit times for all nodes
    cout << "\nNode | Entry | Exit" << endl;
    for(int i = 0; i < n; i++){
        cout << "  " << i << "  |   " << entry_time[i] << "   |  " << exit_time[i] << endl;
    }

    return 0;
}
```

**Diagram: Entry and Exit Times**
```
  Graph:                    DFS Tree from 0:
    0 ---- 1                     0 [entry=0, exit=7]
    |      |                    / \
    3 ---- 2                   1   3 (if 3 visited later)
                              /
                             2 [entry=2, exit=3]
  
  Timeline:
  0    1    2    3    4    5    6    7
  |    |    |    |    |    |    |    |
  Enter0 Enter1 Enter2 Exit2  Enter3 Exit3 Exit1 Exit0
  
  Entry/Exit tells us if node B is in subtree of A:
  If entry[A] < entry[B] AND exit[B] < exit[A] → B is in A's subtree
```

---

## Example 2: DFS on 2D Grid with Island Counting
**Complete grid DFS with detailed path tracking**

```cpp
#include <bits/stdc++.h>
using namespace std;

char grid[105][105];                 // 2D grid: '1' = land, '0' = water
bool visited[105][105];              // track which cells are visited
int n, m;                            // n = rows, m = columns

// Direction vectors for 4 neighbors: up, down, left, right
vector<pair<int,int>> d = {{-1,0}, {1,0}, {0,-1}, {0,1}};

// Check if cell (i,j) is inside the grid
bool valid(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m){
        return false;                // out of bounds → invalid
    }
    return true;                     // inside bounds → valid
}

// DFS to explore one complete island
// si, sj = current cell's row and column
void dfs(int si, int sj){
    visited[si][sj] = true;          // mark current cell as visited

    // Try moving in all 4 directions
    for(int i = 0; i < 4; i++){
        int ci = si + d[i].first;    // calculate new row (current row + direction row)
        int cj = sj + d[i].second;   // calculate new col (current col + direction col)
        
        // Check 3 conditions: within bounds, not visited, and is land
        if(valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '1'){
            dfs(ci, cj);             // recursively explore connected land cell
        }
    }
    // When all 4 directions are explored → backtrack to previous cell
}

int main() {
    cin >> n >> m;                    // read grid dimensions

    // Read the entire grid
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];        // read each cell ('1' or '0')
        }
    }

    // Initialize all cells as unvisited
    memset(visited, false, sizeof(visited));

    int islands = 0;                  // island counter

    // Scan every cell in the grid
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // If cell is land AND not yet visited → found new island!
            if(grid[i][j] == '1' && !visited[i][j]){
                dfs(i, j);           // DFS explores entire island (marks all connected land)
                islands++;            // increment island count
            }
        }
    }

    cout << "Number of islands: " << islands << endl;

    return 0;
}
```

**Step-by-Step Diagram:**
```
  Input Grid (4x5):
  1 1 0 0 0
  1 1 0 0 0
  0 0 1 0 0
  0 0 0 1 1

  Scan cell by cell:
  (0,0): grid='1', unvisited → DFS! → visits (0,0)(0,1)(1,0)(1,1) → islands=1
  (0,1): already visited, skip
  (0,2): grid='0', skip (water)
  ...
  (2,2): grid='1', unvisited → DFS! → visits (2,2)              → islands=2
  ...
  (3,3): grid='1', unvisited → DFS! → visits (3,3)(3,4)         → islands=3

  DFS(0,0) exploration:
  (0,0) → try Up(-1,0): invalid
        → try Down(1,0): (1,0) land, unvisited → DFS(1,0)
            (1,0) → Down(2,0): water, skip
                   → Right(1,1): land → DFS(1,1)
                       (1,1) → Right(1,2): water
                              → Up(0,1): land → DFS(0,1)
                                  (0,1) → all neighbors visited
                              → all done, backtrack
                   → all done, backtrack
        → try Right(0,1): already visited
        → all done
```

---

## Example 3: Cycle Detection with Path Printing
**Detect cycle and print the cycle path**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];         // adjacency list for the graph
bool visited[1005];                  // track visited nodes
int parent[1005];                    // parent[i] = who called dfs(i)
int cycle_start = -1;                // node where cycle starts
int cycle_end = -1;                  // node where cycle ends (detected)

// DFS with cycle detection
// src = current node, par = parent node (who called us)
bool dfs(int src, int par){
    visited[src] = true;             // mark current node visited
    parent[src] = par;               // record parent

    // Check all neighbors
    for(int child : adj_list[src]){
        if(!visited[child]){                // neighbor not visited
            if(dfs(child, src)){            // recursively visit
                return true;                // cycle found deeper, propagate up
            }
        }
        else if(child != par){              // visited AND not parent → CYCLE!
            cycle_start = child;            // cycle starts at this visited node
            cycle_end = src;                // cycle detected from current node
            return true;                    // report cycle found
        }
    }
    return false;                    // no cycle from this node
}

int main() {
    int n, e;
    cin >> n >> e;                   // read nodes and edges

    // Build graph
    while(e--){
        int a, b;
        cin >> a >> b;               // read edge
        adj_list[a].push_back(b);    // add edge both ways
        adj_list[b].push_back(a);    // undirected
    }

    memset(visited, false, sizeof(visited));   // all unvisited
    memset(parent, -1, sizeof(parent));        // no parents

    // Check all components for cycles
    bool has_cycle = false;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(dfs(i, -1)){
                has_cycle = true;
                break;
            }
        }
    }

    if(has_cycle){
        cout << "Cycle found!" << endl;
        
        // Print cycle path: backtrack from cycle_end to cycle_start
        vector<int> cycle;
        int node = cycle_end;
        while(node != cycle_start){       // backtrack using parent array
            cycle.push_back(node);
            node = parent[node];
        }
        cycle.push_back(cycle_start);     // add start node
        reverse(cycle.begin(), cycle.end());
        cycle.push_back(cycle_start);     // complete the cycle
        
        // Print the cycle
        cout << "Cycle: ";
        for(int x : cycle){
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}
```

**Diagram:**
```
  Graph with cycle:
    0 ---- 1
    |      |        Cycle: 0 → 1 → 2 → 3 → 0
    |      |
    3 ---- 2

  DFS(0, -1):
    → DFS(1, 0):
        → DFS(2, 1):
            → DFS(3, 2):
                → sees 0: visited AND not parent(2)
                → CYCLE! cycle_start=0, cycle_end=3
  
  Backtrack: 3 → parent[3]=2 → parent[2]=1 → parent[1]=0 = cycle_start
  Cycle: 0 → 1 → 2 → 3 → 0
```

---

# DFS vs BFS Comparison

## Side-by-Side Comparison

```
  DFS (Depth First Search):          BFS (Breadth First Search):

        0                                  0
       / \                                / \
      1   2                              1   2
     / \   \                            / \   \
    3   4   5                          3   4   5

  Order: 0→1→3→4→2→5                Order: 0→1→2→3→4→5
  (dive deep, then backtrack)        (level by level)
  
  Uses: Recursion/Stack (LIFO)       Uses: Queue (FIFO)
```

| Feature | DFS | BFS |
|---------|-----|-----|
| **Data Structure** | Stack / Recursion (LIFO) | Queue (FIFO) |
| **Exploration** | Go deep first, then backtrack | Level by level |
| **Shortest Path** | ❌ No guarantee | ✅ Yes (unweighted) |
| **Memory** | O(height of tree) | O(width of tree) |
| **Complete** | Yes (finite graphs) | Yes (finite graphs) |
| **Implementation** | Easy with recursion | Iterative with queue |

---

## When to Use Which?

| Problem | Use DFS | Use BFS |
|---------|---------|---------|
| **Shortest Path (unweighted)** | ❌ | ✅ |
| **Connected Components** | ✅ | ✅ |
| **Cycle Detection** | ✅ | ✅ |
| **Topological Sort** | ✅ | ❌ (use Kahn's algo) |
| **Path Finding** | ✅ (any path) | ✅ (shortest path) |
| **Flood Fill / Islands** | ✅ | ✅ |
| **Bipartite Check** | ✅ | ✅ |
| **Level-wise Processing** | ❌ | ✅ |
| **Maze Solving (shortest)** | ❌ | ✅ |

---

## Time and Space Complexity

| Operation | DFS | BFS |
|-----------|-----|-----|
| **Traversal** | O(V + E) | O(V + E) |
| **Space** | O(V) | O(V) |
| **Best Case Space** | O(log V) for balanced tree | O(V) always |
| **Worst Case Space** | O(V) for linear graph | O(V) for complete graph |

---

## Common Mistakes to Avoid

1. ❌ Forgetting to mark visited → **infinite loop** (DFS revisits same node)
   ```cpp
   // WRONG: no visited check
   void dfs(int src){
       cout << src;
       for(int child : adj_list[src])
           dfs(child);               // will loop forever in cyclic graph!
   }
   
   // CORRECT: mark visited
   void dfs(int src){
       visited[src] = true;          // prevent revisiting
       for(int child : adj_list[src])
           if(!visited[child]) dfs(child);
   }
   ```

2. ❌ Stack overflow on large graphs → use iterative DFS
   ```
   Recursion depth > 10000 → may crash!
   Solution: Use iterative DFS with explicit stack
   ```

3. ❌ Not handling disconnected components
   ```cpp
   // WRONG: only calls DFS once
   dfs(0);
   
   // CORRECT: check all nodes
   for(int i = 0; i < n; i++)
       if(!visited[i]) dfs(i);
   ```

4. ❌ Using DFS for shortest path → DFS finds A path, not THE shortest path

5. ❌ Wrong parent check in cycle detection (undirected)
   ```cpp
   // Must skip parent: dfs(child, src) and check child != parent
   ```

---

## DFS Template Summary

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[N];                 // adjacency list
bool visited[N];                    // visited array

// Recursive DFS template
void dfs(int src){
    visited[src] = true;            // 1. Mark visited
    // Process node src here        // 2. Work with node

    for(int child : adj[src]){      // 3. Visit children
        if(!visited[child]){
            dfs(child);             // Go deeper
        }
    }
    // Backtrack happens here       // 4. All children done
}
```

---

## Important Notes

1. **DFS uses recursion** (implicit stack) or explicit stack
2. **Mark visited immediately** when entering node
3. **DFS does NOT guarantee shortest path** — use BFS for that
4. **Topological sort** only works with DFS (or Kahn's BFS)
5. **Cycle detection** in undirected graphs needs parent tracking
6. **Entry/exit times** help determine subtree relationships
7. **Grid DFS** uses direction arrays: `{-1,0}, {1,0}, {0,-1}, {0,1}`
8. **Connected components**: run DFS for each unvisited node
