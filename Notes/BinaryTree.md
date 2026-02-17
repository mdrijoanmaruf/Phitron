# Binary Tree - Complete Notes

## Table of Contents
1. [Introduction to Binary Tree](#introduction-to-binary-tree)
2. [Node Structure](#node-structure)
3. [Creating Binary Tree](#creating-binary-tree)
4. [Tree Traversals](#tree-traversals)
5. [Binary Tree Operations](#binary-tree-operations)
6. [Complete Examples](#complete-examples)
7. [Comparison and Applications](#comparison-and-applications)

---

# Introduction to Binary Tree

## What is Binary Tree?
**Binary Tree is a hierarchical data structure where each node has at most two children**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
};

int main() {
    Node* root = new Node();     // creating root node
    return 0;
}
```

**Key Terminology:**
- **Root:** Topmost node of the tree
- **Parent:** Node that has children
- **Child:** Node connected below a parent
- **Leaf:** Node with no children
- **Height:** Number of edges from root to deepest leaf
- **Depth:** Number of edges from root to that node
- **Subtree:** Tree formed by a node and its descendants

**Types of Binary Tree:**
- **Full Binary Tree:** Every node has 0 or 2 children
- **Complete Binary Tree:** All levels filled except possibly last
- **Perfect Binary Tree:** All internal nodes have 2 children, all leaves at same level
- **Balanced Binary Tree:** Height is O(log n)

---

# Node Structure

## Basic Node Class
**Node contains value and pointers to left and right children**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;               // value stored in node
    Node* left;            // pointer to left child
    Node* right;           // pointer to right child

    Node(int val){
        this->val = val;          // set value
        this->left = NULL;        // initially no left child
        this->right = NULL;       // initially no right child
    }
};

int main() {
    Node* root = new Node(10);    // create node with value 10
    cout << root->val << endl;     // Output: 10
    return 0;
}
```

---

# Creating Binary Tree

## 1. Manual Node Creation
**Create nodes manually and connect them**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int main() {
    // Create nodes
    Node* root = new Node(10);      // root node
    Node* a = new Node(20);         // left child of root
    Node* b = new Node(30);         // right child of root
    Node* c = new Node(40);         // left child of a
    Node* d = new Node(50);         // left child of b
    Node* e = new Node(60);         // right child of b

    // Connect nodes
    root->left = a;                 // connect a as left child of root
    root->right = b;                // connect b as right child of root
    a->left = c;                    // connect c as left child of a
    b->left = d;                    // connect d as left child of b
    b->right = e;                   // connect e as right child of b
    
    return 0;
}
```

**Tree Structure Created:**
```
        10 (root)
       /  \
      20   30
     /    /  \
    40   50   60
```

---

## 2. Input Binary Tree Using Queue (Level Order)
**Take input using BFS approach**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree(){
    int val;
    cin >> val;                         // input root value
    
    Node* root;
    if(val == -1){                      // -1 means no node
        root = NULL;
    }else {
        root = new Node(val);
    }

    queue<Node*> q;
    if(root != NULL){
        q.push(root);                   // push root to queue
    }

    while(!q.empty()){
        // 1. Bring Out front node
        Node* p = q.front();
        q.pop();

        // 2. Take left and right child input
        int l, r;
        cin >> l >> r;
        
        Node* myLeft;
        Node* myRight;
        
        if(l == -1)
            myLeft = NULL;              // no left child
        else 
            myLeft = new Node(l);       // create left child

        if(r == -1)
            myRight = NULL;             // no right child
        else 
            myRight = new Node(r);      // create right child

        // Connect children to parent
        p->left = myLeft;
        p->right = myRight;

        // 3. Push Children to queue if exist
        if(p->left)
            q.push(p->left);
        if(p->right)
            q.push(p->right);
    }
    return root;
}

int main() {
    Node* root = input_tree();
    return 0;
}
```

**Input Format:**
```
root_value
left_of_root right_of_root
left_of_a right_of_a
left_of_b right_of_b
...
```
Use -1 for NULL node.

---

## 3. Input Binary Tree Using Recursion
**Take input recursively (Preorder style)**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree_recursive(){
    int val;
    cin >> val;
    
    if(val == -1){                      // -1 means NULL
        return NULL;
    }
    
    Node* root = new Node(val);         // create node
    root->left = input_tree_recursive();    // recursively create left subtree
    root->right = input_tree_recursive();   // recursively create right subtree
    
    return root;
}

int main() {
    Node* root = input_tree_recursive();
    return 0;
}
```

---

# Tree Traversals

## 1. Preorder Traversal (Root → Left → Right)
**Visit root first, then left subtree, then right subtree**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorder(Node* root){
    if(root == NULL){                   // base case
        return;
    }

    cout << root->val << " ";           // 1. Visit root
    preorder(root->left);               // 2. Traverse left subtree
    preorder(root->right);              // 3. Traverse right subtree
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    preorder(root);
    // Output: 10 20 40 30 50 60
    return 0;
}
```

**Preorder Memory Trick:** **Root** comes first → R-L-R (Root-Left-Right)

---

## 2. Inorder Traversal (Left → Root → Right)
**Visit left subtree first, then root, then right subtree**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node* root){
    if(root == NULL){                   // base case
        return;
    }

    inorder(root->left);                // 1. Traverse left subtree
    cout << root->val << " ";           // 2. Visit root
    inorder(root->right);               // 3. Traverse right subtree
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    inorder(root);
    // Output: 40 20 10 50 30 60
    return 0;
}
```

**Inorder Memory Trick:** Root is **IN** the middle → L-R-R (Left-Root-Right)

**Important:** Inorder traversal of BST gives sorted order!

---

## 3. Postorder Traversal (Left → Right → Root)
**Visit left subtree first, then right subtree, then root**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void postorder(Node* root){
    if(root == NULL){                   // base case
        return;
    }

    postorder(root->left);              // 1. Traverse left subtree
    postorder(root->right);             // 2. Traverse right subtree
    cout << root->val << " ";           // 3. Visit root
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    postorder(root);
    // Output: 40 20 50 60 30 10
    return 0;
}
```

**Postorder Memory Trick:** Root comes at **POST** (last) → L-R-R (Left-Right-Root)

---

## 4. Level Order Traversal (BFS)
**Visit nodes level by level using queue**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void level_order(Node* root){
    if(root == NULL) return;
    
    queue<Node*> q;
    q.push(root);                       // push root to queue

    while(!q.empty()){
        // 1. Bring out front node
        Node* front = q.front();
        q.pop();

        // 2. Work with this node
        cout << front->val << " ";

        // 3. Push children to queue
        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }
    }
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    level_order(root);
    // Output: 10 20 30 40 50 60
    return 0;
}
```

**Level Order with Levels Separated:**

```cpp
void level_order_with_levels(Node* root){
    if(root == NULL) return;
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int level_size = q.size();      // nodes at current level
        
        for(int i = 0; i < level_size; i++){
            Node* front = q.front();
            q.pop();
            
            cout << front->val << " ";
            
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
        cout << endl;                   // new line after each level
    }
}
```

---

## Traversal Comparison

| Traversal | Order | Use Case |
|-----------|-------|----------|
| **Preorder** | Root → Left → Right | Copy tree, create prefix expression |
| **Inorder** | Left → Root → Right | BST gives sorted order |
| **Postorder** | Left → Right → Root | Delete tree, postfix expression |
| **Level Order** | Level by level | BFS, shortest path in unweighted tree |

---

# Binary Tree Operations

## 1. Count Total Nodes
**Count all nodes in the tree using recursion**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int count_nodes(Node* root){
    if(root == NULL){                   // base case
        return 0;
    }
    
    int left = count_nodes(root->left);      // count left subtree
    int right = count_nodes(root->right);    // count right subtree
    return left + right + 1;                  // +1 for current node
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    cout << count_nodes(root) << endl;
    // Output: 6
    return 0;
}
```

**Time Complexity:** O(n) - visits every node once

---

## 2. Count Leaf Nodes
**Count nodes with no children**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int count_leaf_nodes(Node* root){
    if(root == NULL)
        return 0;
    
    // if both children are NULL, it's a leaf
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    
    int left = count_leaf_nodes(root->left);
    int right = count_leaf_nodes(root->right);
    return left + right;
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    cout << count_leaf_nodes(root) << endl;
    // Output: 3 (nodes 40, 50, 60 are leaves)
    return 0;
}
```

---

## 3. Find Maximum Height (Depth)
**Find the height of the tree**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int max_height(Node* root){
    if(root == NULL)
        return 0;                       // or return -1 depending on definition
    
    if(root->left == NULL && root->right == NULL){
        return 0;                       // leaf node has height 0
    }
    
    int left = max_height(root->left);
    int right = max_height(root->right);
    return max(left, right) + 1;        // take max and add 1
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    cout << max_height(root) << endl;
    // Output: 2
    return 0;
}
```

**Note:** Some definitions count nodes (height = edges + 1), some count edges. Adjust base case accordingly.

---

## 4. Find Sum of All Nodes
**Calculate sum of all node values**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int sum_of_nodes(Node* root){
    if(root == NULL){
        return 0;
    }
    
    int left_sum = sum_of_nodes(root->left);
    int right_sum = sum_of_nodes(root->right);
    return root->val + left_sum + right_sum;
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    cout << sum_of_nodes(root) << endl;
    // Output: 210 (10+20+30+40+50+60)
    return 0;
}
```

---

## 5. Find Maximum Value
**Find the maximum value in tree**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int find_max(Node* root){
    if(root == NULL){
        return INT_MIN;                 // return minimum integer for NULL
    }
    
    int left_max = find_max(root->left);
    int right_max = find_max(root->right);
    
    return max(root->val, max(left_max, right_max));
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);
    Node* e = new Node(60);

    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;

    cout << find_max(root) << endl;
    // Output: 60
    return 0;
}
```

---

## 6. Search Value in Tree
**Check if a value exists in tree**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

bool search(Node* root, int target){
    if(root == NULL){
        return false;                   // not found
    }
    
    if(root->val == target){
        return true;                    // found
    }
    
    // search in left or right subtree
    return search(root->left, target) || search(root->right, target);
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);

    root->left = a;
    root->right = b;

    cout << search(root, 20) << endl;   // Output: 1 (true)
    cout << search(root, 100) << endl;  // Output: 0 (false)
    return 0;
}
```

---

## 7. Mirror a Binary Tree
**Swap left and right children of all nodes**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void mirror(Node* root){
    if(root == NULL){
        return;
    }
    
    // swap left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // recursively mirror subtrees
    mirror(root->left);
    mirror(root->right);
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);

    root->left = a;
    root->right = b;
    
    // Before: 10 -> (20, 30)
    mirror(root);
    // After: 10 -> (30, 20)
    
    return 0;
}
```

---

## 8. Check if Two Trees are Identical
**Compare structure and values of two trees**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

bool is_identical(Node* root1, Node* root2){
    // both NULL means identical
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    
    // one NULL, other not - not identical
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    
    // check current node and recursively check subtrees
    return (root1->val == root2->val) && 
           is_identical(root1->left, root2->left) &&
           is_identical(root1->right, root2->right);
}

int main() {
    // Tree 1
    Node* root1 = new Node(10);
    root1->left = new Node(20);
    root1->right = new Node(30);
    
    // Tree 2
    Node* root2 = new Node(10);
    root2->left = new Node(20);
    root2->right = new Node(30);
    
    cout << is_identical(root1, root2) << endl;  // Output: 1 (true)
    return 0;
}
```

---

# Complete Examples

## Example 1: Complete Binary Tree Implementation
**All operations in one program**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Traversals
void preorder(Node* root){
    if(root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

void level_order(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        cout << front->val << " ";
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
    }
}

// Operations
int count_nodes(Node* root){
    if(root == NULL) return 0;
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}

int count_leaf(Node* root){
    if(root == NULL) return 0;
    if(!root->left && !root->right) return 1;
    return count_leaf(root->left) + count_leaf(root->right);
}

int height(Node* root){
    if(root == NULL) return -1;
    return max(height(root->left), height(root->right)) + 1;
}

int main() {
    // Create tree
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    /*
            10
           /  \
         20    30
        /  \   /
       40  50 60
    */

    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    // Output: 10 20 40 50 30 60

    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    // Output: 40 20 50 10 60 30

    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    // Output: 40 50 20 60 30 10

    cout << "Level Order: ";
    level_order(root);
    cout << endl;
    // Output: 10 20 30 40 50 60

    cout << "Total Nodes: " << count_nodes(root) << endl;
    // Output: 6

    cout << "Leaf Nodes: " << count_leaf(root) << endl;
    // Output: 3

    cout << "Height: " << height(root) << endl;
    // Output: 2

    return 0;
}
```

---

## Example 2: Print Nodes at K Distance
**Print all nodes at distance K from root**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void print_at_distance_k(Node* root, int k){
    if(root == NULL){
        return;
    }
    
    if(k == 0){
        cout << root->val << " ";       // at distance k, print
        return;
    }
    
    // go deeper by 1
    print_at_distance_k(root->left, k - 1);
    print_at_distance_k(root->right, k - 1);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    cout << "Nodes at distance 0: ";
    print_at_distance_k(root, 0);      // Output: 10
    cout << endl;

    cout << "Nodes at distance 1: ";
    print_at_distance_k(root, 1);      // Output: 20 30
    cout << endl;

    cout << "Nodes at distance 2: ";
    print_at_distance_k(root, 2);      // Output: 40 50 60
    cout << endl;

    return 0;
}
```

---

## Example 3: Check if Tree is Balanced
**Check if height difference of subtrees is at most 1**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int height(Node* root){
    if(root == NULL) return -1;
    return max(height(root->left), height(root->right)) + 1;
}

bool is_balanced(Node* root){
    if(root == NULL){
        return true;
    }
    
    int left_height = height(root->left);
    int right_height = height(root->right);
    
    // check if current node is balanced
    if(abs(left_height - right_height) > 1){
        return false;
    }
    
    // check if subtrees are balanced
    return is_balanced(root->left) && is_balanced(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    cout << is_balanced(root) << endl;  // Output: 1 (balanced)
    
    // Add more nodes to make unbalanced
    root->left->left->left = new Node(50);
    
    cout << is_balanced(root) << endl;  // Output: 0 (not balanced)

    return 0;
}
```

---

## Example 4: Diameter of Binary Tree
**Find the longest path between any two nodes**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

int height(Node* root){
    if(root == NULL) return -1;
    return max(height(root->left), height(root->right)) + 1;
}

int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    
    // Diameter through this node
    int left_height = height(root->left);
    int right_height = height(root->right);
    int through_root = left_height + right_height + 2;
    
    // Diameter in left or right subtree
    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);
    
    return max(through_root, max(left_diameter, right_diameter));
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout << "Diameter: " << diameter(root) << endl;
    // Output: 4 (path: 40 -> 20 -> 10 -> 30 or similar)

    return 0;
}
```

---

# Comparison and Applications

## Time Complexity Summary

| Operation | Time Complexity |
|-----------|-----------------|
| Traversals (all) | O(n) |
| Search | O(n) |
| Insert (general) | O(n) |
| Count Nodes | O(n) |
| Height | O(n) |
| Count Leaves | O(n) |

---

## Binary Tree vs Other Data Structures

| Feature | Binary Tree | Array | Linked List |
|---------|-------------|-------|-------------|
| **Structure** | Hierarchical | Linear | Linear |
| **Access** | O(n) | O(1) | O(n) |
| **Insert** | O(n) | O(n) | O(1) |
| **Delete** | O(n) | O(n) | O(1) |
| **Search** | O(n) | O(n) or O(log n) | O(n) |
| **Use Case** | Hierarchical data | Random access | Sequential access |

---

## Applications of Binary Tree

1. **Expression Trees**
   - Represent mathematical expressions
   - Evaluate and parse expressions

2. **Huffman Coding**
   - Data compression
   - Prefix-free codes

3. **Binary Search Tree (BST)**
   - Efficient searching
   - Sorted data maintenance

4. **Heap**
   - Priority queue implementation
   - Heap sort

5. **Syntax Trees**
   - Compiler design
   - Code parsing

6. **File System**
   - Directory structure
   - Hierarchical data

---

## Important Notes

1. **Recursion Pattern:** Most tree problems use recursion
   - Base case: `if(root == NULL)`
   - Process current node
   - Recurse on left and right subtrees

2. **Common Techniques:**
   - DFS: Preorder, Inorder, Postorder
   - BFS: Level order using queue
   - Divide and Conquer approach

3. **Height vs Depth:**
   - Height: measured from node to deepest leaf (bottom-up)
   - Depth: measured from root to node (top-down)

4. **Queue for Level Order:** Always use queue for BFS/level order traversal

5. **NULL Check:** Always check for NULL before accessing node properties

---

## Common Mistakes to Avoid

1. ❌ Forgetting NULL check at the start of recursive function
2. ❌ Not returning value in recursive functions that return something
3. ❌ Confusing preorder, inorder, and postorder
4. ❌ Using wrong base case for height (0 vs -1)
5. ❌ Not handling single node tree case
6. ❌ Forgetting to push both children in level order traversal

---

## Best Practices

1. **Always start with NULL check**
   ```cpp
   if(root == NULL) return;  // or return 0, false, etc.
   ```

2. **Use consistent node structure**
   ```cpp
   class Node{
       int val;
       Node* left;
       Node* right;
   };
   ```

3. **Recursive thinking**
   - Solve for single node
   - Combine results from left and right subtrees

4. **Test with edge cases**
   - Empty tree (NULL root)
   - Single node tree
   - Left-skewed or right-skewed tree

---

## Quick Reference: Traversal Patterns

```cpp
// Preorder: Root -> Left -> Right
void preorder(Node* root){
    if(!root) return;
    process(root);        // first
    preorder(root->left);
    preorder(root->right);
}

// Inorder: Left -> Root -> Right
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    process(root);        // middle
    inorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    process(root);        // last
}

// Level Order: BFS
void levelorder(Node* root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        process(front);
        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
    }
}
```
