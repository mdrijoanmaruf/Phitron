# Queue (STL) - Complete Notes

## Table of Contents
1. [Introduction to Queue](#introduction-to-queue)
2. [Queue Implementation Methods](#queue-implementation-methods)
3. [Queue Operations](#queue-operations)
4. [STL Queue Functions](#stl-queue-functions)
5. [Complete Examples](#complete-examples)
6. [Comparison with Other Data Structures](#comparison-with-other-data-structures)

---

# Introduction to Queue

## What is Queue?
**Queue is a linear data structure that follows FIFO (First In First Out) principle**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;    // creating empty queue
    return 0;
}
```

**Key Characteristics:**
- FIFO (First In First Out) - First element inserted is first to be removed
- Insertion at rear (back) and deletion at front
- No random access to elements
- Common operations: push, pop, front, back

**Real-life Examples:**
- Queue at ticket counter
- Print job queue
- CPU task scheduling
- Breadth First Search (BFS)

---

# Queue Implementation Methods

## 1. Queue Using Singly Linked List
**Implement queue using singly linked list with head and tail pointers**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class myQueue{
    public:
    Node* head = NULL;      // points to front of queue
    Node* tail = NULL;      // points to rear of queue
    int sz = 0;             // track size

    void push(int val){  
        sz++;
        Node* newNode = new Node(val);    // create new node
        
        if(head == NULL){                  // if queue is empty
            head = newNode;
            tail = newNode;
            return;
        }
        
        tail->next = newNode;              // add at rear
        tail = newNode;                    // update tail
    }

    void pop(){
        if(head == NULL) return;           // if queue is empty
        
        sz--;
        Node* deleteNode = head;           // save front node
        head = head->next;                 // move head forward
        delete deleteNode;                 // free memory

        if(head == NULL){                  // if queue becomes empty
            tail = NULL;
        }
    }

    int front(){
        return head->val;                  // return front element
    }

    int back(){
        return tail->val;                  // return rear element
    }

    int size(){
        return sz;                         // return size
    }

    bool empty(){
        return head == NULL;               // check if empty
    }
};

int main() {
    myQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << q.front() << endl;  // Output: 10
    cout << q.back() << endl;   // Output: 30
    
    return 0;
}
```

**Advantages:**
- No size limitation
- Efficient O(1) operations
- Dynamic memory allocation

**Disadvantages:**
- Extra memory for pointers
- Not cache-friendly

---

## 2. Queue Using Doubly Linked List
**Implement queue using doubly linked list**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myQueue{
    public:
    Node* head = NULL;      // points to front of queue
    Node* tail = NULL;      // points to rear of queue
    int sz = 0;             // track size

    void push(int val){  
        sz++;
        Node* newNode = new Node(val);
        
        if(head == NULL){                  // if queue is empty
            head = newNode;
            tail = newNode;
            return;
        }
        
        tail->next = newNode;              // add at rear
        newNode->prev = tail;              // link back
        tail = newNode;                    // update tail
    }

    void pop(){
        if(head == NULL) return;           // if queue is empty
        
        sz--;
        Node* deleteNode = head;           // save front node
        head = head->next;                 // move head forward
        delete deleteNode;                 // free memory
        
        if(head == NULL){                  // if queue becomes empty
            tail = NULL;
            return;
        }
        head->prev = NULL;                 // remove backward link
    }

    int front(){
        return head->val;                  // return front element
    }

    int back(){
        return tail->val;                  // return rear element
    }

    int size(){
        return sz;                         // return size
    }

    bool empty(){
        return head == NULL;               // check if empty
    }
};

int main() {
    myQueue q;
    int n;
    cin >> n;
    
    while(n--){
        int x;
        cin >> x;
        q.push(x);
    }
    
    return 0;
}
```

**Advantages:**
- Bi-directional traversal possible
- Can implement deque

**Disadvantages:**
- More memory overhead (2 pointers per node)

---

## 3. Queue Using STL List
**Implement queue using STL list container**

```cpp
#include <bits/stdc++.h>
using namespace std;

class myQueue{
    public:
    list<int> l;           // using list as underlying container
    int sz = 0;            // track size

    void push(int val){  
        l.push_back(val);  // add at rear (back)
    }

    void pop(){
        l.pop_front();     // remove from front
    }

    int front(){
        return l.front();  // return first element
    }

    int back(){
        return l.back();   // return last element
    }

    int size(){
        return l.size();   // return size
    }

    bool empty(){
        return l.empty();  // check if empty
    }
};

int main() {
    myQueue q;
    int n;
    cin >> n;
    
    while(n--){
        int x;
        cin >> x;
        q.push(x);
    }
    
    return 0;
}
```

**Advantages:**
- Easy to implement
- Uses tested STL container

---

## 4. STL Queue (Recommended)
**Use built-in STL queue container**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;              // STL queue

    q.push(10);                // insert at rear
    q.push(20);
    q.push(30);
    
    cout << q.front() << endl; // access front
    cout << q.back() << endl;  // access rear
    
    q.pop();                   // remove from front
    
    cout << q.size() << endl;  // get size
    cout << q.empty() << endl; // check if empty
    
    return 0;
}
```

**Why use STL Queue?**
- Already implemented and tested
- Efficient and optimized
- Easy to use
- Default uses deque as underlying container

---

# Queue Operations

## 1. push()
**Insert element at the rear of queue**

```cpp
queue<int> q;

q.push(10);                    // queue: 10
q.push(20);                    // queue: 10, 20
q.push(30);                    // queue: 10, 20, 30
```

**Time Complexity:** O(1)

---

## 2. pop()
**Remove element from the front of queue**

```cpp
queue<int> q;
q.push(10);
q.push(20);
q.push(30);                    // queue: 10, 20, 30

q.pop();                       // removes 10, queue: 20, 30
q.pop();                       // removes 20, queue: 30
```

**Time Complexity:** O(1)

**Note:** pop() does not return the value, use front() before pop() to get the value.

---

## 3. front()
**Access the front element without removing it**

```cpp
queue<int> q;
q.push(10);
q.push(20);
q.push(30);

cout << q.front() << endl;     // Output: 10
cout << q.front() << endl;     // Output: 10 (still there)
```

**Time Complexity:** O(1)

**Warning:** Calling front() on empty queue is undefined behavior.

---

## 4. back()
**Access the rear element without removing it**

```cpp
queue<int> q;
q.push(10);
q.push(20);
q.push(30);

cout << q.back() << endl;      // Output: 30
cout << q.back() << endl;      // Output: 30 (still there)
```

**Time Complexity:** O(1)

**Warning:** Calling back() on empty queue is undefined behavior.

---

## 5. size()
**Returns the number of elements in queue**

```cpp
queue<int> q;
q.push(10);
q.push(20);
q.push(30);

cout << q.size() << endl;      // Output: 3
```

**Time Complexity:** O(1)

---

## 6. empty()
**Check if queue is empty**

```cpp
queue<int> q;

if(q.empty()){
    cout << "Queue is empty" << endl;
}

q.push(10);

if(!q.empty()){
    cout << "Queue is not empty" << endl;
}
```

**Time Complexity:** O(1)

**Best Practice:** Always check empty() before calling front(), back() or pop()

---

# STL Queue Functions

## Complete Function Reference

| Function | Description | Time Complexity |
|----------|-------------|-----------------|
| `push(val)` | Insert element at rear | O(1) |
| `pop()` | Remove front element | O(1) |
| `front()` | Access front element | O(1) |
| `back()` | Access rear element | O(1) |
| `size()` | Number of elements | O(1) |
| `empty()` | Check if empty | O(1) |

---

## Queue with Different Data Types

```cpp
// Integer queue
queue<int> intQueue;

// String queue
queue<string> stringQueue;
stringQueue.push("First");
stringQueue.push("Second");

// Character queue
queue<char> charQueue;
charQueue.push('A');
charQueue.push('B');

// Pair queue
queue<pair<int, int>> pairQueue;
pairQueue.push({10, 20});
pairQueue.push({30, 40});
```

---

# Complete Examples

## Example 1: Basic Queue Operations
**Demonstrate all queue operations**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    
    // Push elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    
    // Check size
    cout << "Size: " << q.size() << endl;        // Output: 5
    
    // Access front and back
    cout << "Front: " << q.front() << endl;      // Output: 10
    cout << "Back: " << q.back() << endl;        // Output: 50
    
    // Pop and print all elements
    while(!q.empty()){
        cout << q.front() << " ";                 // prints in FIFO order
        q.pop();
    }
    cout << endl;
    // Output: 10 20 30 40 50
    
    return 0;
}
```

---

## Example 2: Input and Output
**Take input and print in FIFO order**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    
    int n;
    cin >> n;                      // number of elements
    
    // Input elements
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.push(x);                 // push to queue
    }
    
    // Output in FIFO order
    while(!q.empty()){
        cout << q.front() << endl; // print front
        q.pop();                    // remove front
    }
    
    return 0;
}
```

**Input:**
```
5
10 20 30 40 50
```

**Output:**
```
10
20
30
40
50
```

---

## Example 3: BFS Using Queue
**Breadth First Search traversal**

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100];        // adjacency list
bool visited[100];             // visited array

void BFS(int start){
    queue<int> q;
    q.push(start);             // push starting node
    visited[start] = true;
    
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        cout << current << " ";  // process current node
        
        // visit all neighbors
        for(int neighbor : graph[current]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Create graph
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(5);
    
    memset(visited, false, sizeof(visited));
    
    BFS(0);  // start BFS from node 0
    
    return 0;
}
```

**Output:** `0 1 2 3 4 5` (level-order traversal)

---

## Example 4: First Non-Repeating Character
**Find first non-repeating character in stream**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    queue<char> q;
    int freq[26] = {0};        // frequency of each character
    
    for(char c : s){
        q.push(c);
        freq[c - 'a']++;
        
        // remove characters from front that are repeating
        while(!q.empty() && freq[q.front() - 'a'] > 1){
            q.pop();
        }
        
        // print first non-repeating character
        if(!q.empty()){
            cout << q.front() << " ";
        }
        else{
            cout << "-1 ";
        }
    }
    
    return 0;
}
```

**Input:** `aabbc`  
**Output:** `a -1 b b c`

---

## Example 5: Queue Reversal
**Reverse a queue using stack**

```cpp
#include <bits/stdc++.h>
using namespace std;

void reverseQueue(queue<int> &q){
    stack<int> st;
    
    // Push all elements to stack
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    
    // Push back from stack to queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    
    cout << "Original: ";
    queue<int> temp = q;
    while(!temp.empty()){
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    // Output: 10 20 30 40
    
    reverseQueue(q);
    
    cout << "Reversed: ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    // Output: 40 30 20 10
    
    return 0;
}
```

---

## Example 6: Generate Binary Numbers
**Generate binary numbers from 1 to N using queue**

```cpp
#include <bits/stdc++.h>
using namespace std;

void generateBinary(int n){
    queue<string> q;
    q.push("1");
    
    for(int i = 1; i <= n; i++){
        string current = q.front();
        q.pop();
        
        cout << current << " ";
        
        // Generate next binary numbers
        q.push(current + "0");
        q.push(current + "1");
    }
}

int main() {
    int n;
    cin >> n;
    
    generateBinary(n);
    
    return 0;
}
```

**Input:** `5`  
**Output:** `1 10 11 100 101`

---

# Comparison with Other Data Structures

## Queue vs Stack vs List vs Vector

| Feature | Queue | Stack | List | Vector |
|---------|-------|-------|------|--------|
| **Access Pattern** | FIFO (First In First Out) | LIFO (Last In First Out) | Any position | Any position |
| **Insertion** | Rear only | Top only | Any position | Any position |
| **Deletion** | Front only | Top only | Any position | Any position |
| **Random Access** | ❌ No | ❌ No | ❌ No | ✅ Yes |
| **Front Access** | O(1) | ❌ Not allowed | O(1) | O(1) |
| **Back Access** | O(1) | O(1) top | O(1) | O(1) |
| **Middle Access** | ❌ Not allowed | ❌ Not allowed | O(n) | O(1) |
| **Use Case** | BFS, Task scheduling | DFS, Undo/Redo | Frequent insert/delete | Random access needed |

---

## When to Use Queue?

✅ **Use Queue when:**
- Need FIFO behavior
- Breadth First Search (BFS)
- Level order traversal
- Task scheduling
- Print job management
- Buffer management
- Handling requests in order

❌ **Avoid Queue when:**
- Need LIFO behavior (use stack)
- Need random access (use vector)
- Need to access middle elements
- Need priority-based processing (use priority queue)

---

## Applications of Queue

1. **Graph Algorithms**
   - Breadth First Search (BFS)
   - Level order traversal of tree
   - Finding shortest path

2. **Operating Systems**
   - CPU task scheduling
   - Process management
   - Disk scheduling

3. **Network Systems**
   - Packet routing
   - Request handling
   - Data buffering

4. **Real-world Applications**
   - Print queue
   - Call center systems
   - Waiting lists

5. **String Processing**
   - First non-repeating character
   - Stream processing

---

## Time Complexity Summary

| Operation | Singly LL | Doubly LL | STL List | STL Queue |
|-----------|-----------|-----------|----------|-----------|
| push() | O(1) | O(1) | O(1) | O(1) |
| pop() | O(1) | O(1) | O(1) | O(1) |
| front() | O(1) | O(1) | O(1) | O(1) |
| back() | O(1) | O(1) | O(1) | O(1) |
| size() | O(1) | O(1) | O(1) | O(1) |
| empty() | O(1) | O(1) | O(1) | O(1) |

---

## Important Notes

1. **No Random Access:** Queue does not support accessing elements by index
2. **FIFO Order:** First element pushed is first to be popped
3. **Two-ended Access:** Can access both front and back
4. **Check Empty:** Always check `empty()` before calling `front()`, `back()` or `pop()`
5. **No Iterators:** STL queue does not provide iterators
6. **Underlying Container:** STL queue uses deque by default

---

## Common Mistakes to Avoid

1. ❌ Calling `front()`, `back()` or `pop()` on empty queue - causes undefined behavior
2. ❌ Assuming `pop()` returns the value - it only removes, use `front()` first
3. ❌ Trying to access elements other than front and back
4. ❌ Using queue when stack is needed (LIFO)
5. ❌ Forgetting to check `empty()` before operations
6. ❌ Confusing queue with priority_queue (priority_queue is not FIFO)

---

## Best Practices

1. **Always check empty before operations**
   ```cpp
   if(!q.empty()){
       cout << q.front() << endl;
       q.pop();
   }
   ```

2. **Use while loop with empty check**
   ```cpp
   while(!q.empty()){
       // process front
       q.pop();
   }
   ```

3. **Save front value before pop**
   ```cpp
   int value = q.front();
   q.pop();
   // use value
   ```

4. **Choose right underlying container**
   ```cpp
   queue<int, list<int>> q1;     // using list
   queue<int, deque<int>> q2;    // using deque (default)
   ```

---

## Queue Declaration Options

```cpp
// Default queue (uses deque)
queue<int> q1;

// Queue using list as underlying container
queue<int, list<int>> q2;

// Queue using deque as underlying container
queue<int, deque<int>> q3;

// Queue of strings
queue<string> q4;

// Queue of pairs
queue<pair<int, string>> q5;

// Queue of vectors
queue<vector<int>> q6;
```

---

## Memory Comparison

| Implementation | Memory per Element | Extra Overhead |
|----------------|-------------------|----------------|
| **Singly LL** | sizeof(T) + 1 pointer | Node pointers |
| **Doubly LL** | sizeof(T) + 2 pointers | Node pointers |
| **STL Queue (deque)** | sizeof(T) | Block management |

---

## Queue vs Stack: Key Differences

| Feature | Queue | Stack |
|---------|-------|-------|
| **Order** | FIFO (First In First Out) | LIFO (Last In First Out) |
| **Insertion** | At rear (back) | At top |
| **Deletion** | At front | At top |
| **Access** | Front and back | Top only |
| **Use Case** | BFS, Scheduling | DFS, Undo/Redo |
| **Real Example** | Ticket counter line | Stack of plates |

---

## Quick Reference: Common Operations

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    
    // Push elements
    q.push(10);
    q.push(20);
    q.push(30);
    
    // Check size
    cout << q.size() << endl;      // 3
    
    // Check empty
    if(!q.empty()){
        // Access front and back
        cout << q.front() << endl; // 10
        cout << q.back() << endl;  // 30
        
        // Pop front
        q.pop();                    // removes 10
    }
    
    // Clear queue
    while(!q.empty()){
        q.pop();
    }
    
    return 0;
}
```

---

## Advanced: Circular Queue Concept

**Circular Queue** is a variation where the last position connects back to the first, making efficient use of space.

```cpp
class CircularQueue{
    int* arr;
    int front, rear, capacity, count;
    
    public:
    CircularQueue(int size){
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    
    void push(int val){
        if(count == capacity) return;  // queue full
        
        rear = (rear + 1) % capacity;  // circular increment
        arr[rear] = val;
        count++;
    }
    
    void pop(){
        if(count == 0) return;         // queue empty
        
        front = (front + 1) % capacity;  // circular increment
        count--;
    }
    
    int getFront(){
        if(count == 0) return -1;
        return arr[front];
    }
    
    bool isEmpty(){
        return count == 0;
    }
    
    bool isFull(){
        return count == capacity;
    }
};
```
