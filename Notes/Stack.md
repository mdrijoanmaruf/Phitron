# Stack (STL) - Complete Notes

## Table of Contents
1. [Introduction to Stack](#introduction-to-stack)
2. [Stack Implementation Methods](#stack-implementation-methods)
3. [Stack Operations](#stack-operations)
4. [STL Stack Functions](#stl-stack-functions)
5. [Complete Examples](#complete-examples)
6. [Comparison with Other Data Structures](#comparison-with-other-data-structures)

---

# Introduction to Stack

## What is Stack?
**Stack is a linear data structure that follows LIFO (Last In First Out) principle**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;    // creating empty stack
    return 0;
}
```

**Key Characteristics:**
- LIFO (Last In First Out) - Last element inserted is first to be removed
- Insertion and deletion only at one end (top)
- No random access to elements
- Common operations: push, pop, top

**Real-life Examples:**
- Stack of plates
- Browser back button
- Undo/Redo operations
- Function call stack

---

# Stack Implementation Methods

## 1. Stack Using Array (Vector)
**Implement stack using dynamic array**

```cpp
#include <bits/stdc++.h>
using namespace std;

class myStack{
    public:
    vector<int> v;              // using vector as underlying container
    
    void push(int val){
        v.push_back(val);       // add element at end
    }

    void pop(){
        v.pop_back();           // remove element from end
    }

    int top(){
        return v.back();        // return last element
    }

    int size(){
        return v.size();        // return number of elements
    }

    bool empty(){
        return v.empty();       // check if stack is empty
    }
};

int main() {
    myStack st;
    st.push(10);               // stack: 10
    st.push(20);               // stack: 10 20
    st.push(30);               // stack: 10 20 30
    st.push(40);               // stack: 10 20 30 40

    cout << st.top() << endl;  // Output: 40 (top element)
    return 0;
}
```

**Advantages:**
- Cache-friendly (contiguous memory)
- Fast access
- Good for fixed or predictable size

**Disadvantages:**
- May need reallocation when capacity exceeded
- O(n) worst case for push when resizing

---

## 2. Stack Using Linked List (STL List)
**Implement stack using doubly linked list**

```cpp
#include <bits/stdc++.h>
using namespace std;

class myStack{
    public:
    list<int> l;               // using list as underlying container
    
    void push(int val){
        l.push_back(val);      // add element at end
    }

    void pop(){
        l.pop_back();          // remove element from end
    }

    int top(){
        return l.back();       // return last element
    }

    int size(){
        return l.size();       // return number of elements
    }

    bool empty(){
        return l.empty();      // check if stack is empty
    }
};

int main() {
    myStack st;

    int n;
    cin >> n;                  // number of elements

    while(n--){
        int x;
        cin >> x;
        st.push(x);            // push elements
    }

    while(!st.empty()){
        cout << st.top() << endl;  // print top element
        st.pop();                   // remove top element
    }
    
    return 0;
}
```

**Advantages:**
- No reallocation needed
- Consistent O(1) push/pop
- Good for unpredictable size

**Disadvantages:**
- Extra memory for pointers
- Not cache-friendly
- Slower than array-based

---

## 3. STL Stack (Recommended)
**Use built-in STL stack container**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;             // STL stack

    int n;
    cin >> n;                  // number of elements

    while(n--){
        int x;
        cin >> x;
        st.push(x);            // push elements
    }

    while(!st.empty()){
        cout << st.top() << endl;  // print top element
        st.pop();                   // remove top element
    }
    
    return 0;
}
```

**Why use STL Stack?**
- Already implemented and tested
- Efficient and optimized
- Easy to use
- Default uses deque as underlying container

---

# Stack Operations

## 1. push()
**Insert element at the top of stack**

```cpp
stack<int> st;

st.push(10);                   // stack: 10
st.push(20);                   // stack: 10, 20
st.push(30);                   // stack: 10, 20, 30
```

**Time Complexity:** O(1) amortized

---

## 2. pop()
**Remove element from the top of stack**

```cpp
stack<int> st;
st.push(10);
st.push(20);
st.push(30);                   // stack: 10, 20, 30

st.pop();                      // removes 30, stack: 10, 20
st.pop();                      // removes 20, stack: 10
```

**Time Complexity:** O(1)

**Note:** pop() does not return the value, use top() before pop() to get the value.

---

## 3. top()
**Access the top element without removing it**

```cpp
stack<int> st;
st.push(10);
st.push(20);
st.push(30);

cout << st.top() << endl;      // Output: 30
cout << st.top() << endl;      // Output: 30 (still there)
```

**Time Complexity:** O(1)

**Warning:** Calling top() on empty stack is undefined behavior.

---

## 4. size()
**Returns the number of elements in stack**

```cpp
stack<int> st;
st.push(10);
st.push(20);
st.push(30);

cout << st.size() << endl;     // Output: 3
```

**Time Complexity:** O(1)

---

## 5. empty()
**Check if stack is empty**

```cpp
stack<int> st;

if(st.empty()){
    cout << "Stack is empty" << endl;
}

st.push(10);

if(!st.empty()){
    cout << "Stack is not empty" << endl;
}
```

**Time Complexity:** O(1)

**Best Practice:** Always check empty() before calling top() or pop()

---

# STL Stack Functions

## Complete Function Reference

| Function | Description | Time Complexity |
|----------|-------------|-----------------|
| `push(val)` | Insert element at top | O(1) |
| `pop()` | Remove top element | O(1) |
| `top()` | Access top element | O(1) |
| `size()` | Number of elements | O(1) |
| `empty()` | Check if empty | O(1) |

---

## Stack with Different Data Types

```cpp
// Integer stack
stack<int> intStack;

// String stack
stack<string> stringStack;
stringStack.push("Hello");
stringStack.push("World");

// Character stack
stack<char> charStack;
charStack.push('A');
charStack.push('B');

// Pair stack
stack<pair<int, int>> pairStack;
pairStack.push({10, 20});
pairStack.push({30, 40});
```

---

# Complete Examples

## Example 1: Basic Stack Operations
**Demonstrate all stack operations**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    
    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    
    // Check size
    cout << "Size: " << st.size() << endl;        // Output: 5
    
    // Access top element
    cout << "Top: " << st.top() << endl;          // Output: 50
    
    // Pop and print all elements
    while(!st.empty()){
        cout << st.top() << " ";                   // prints in reverse order
        st.pop();
    }
    cout << endl;
    // Output: 50 40 30 20 10
    
    return 0;
}
```

---

## Example 2: Input and Output
**Take input and print in reverse order**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    
    int n;
    cin >> n;                      // number of elements
    
    // Input elements
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        st.push(x);                // push to stack
    }
    
    // Output in reverse order (LIFO)
    while(!st.empty()){
        cout << st.top() << endl;  // print top
        st.pop();                   // remove top
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
50
40
30
20
10
```

---

## Example 3: String Reversal Using Stack
**Reverse a string using stack**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;                      // input string
    
    stack<char> st;
    
    // Push all characters to stack
    for(char c : s){
        st.push(c);
    }
    
    // Pop to get reversed string
    string reversed = "";
    while(!st.empty()){
        reversed += st.top();
        st.pop();
    }
    
    cout << reversed << endl;
    
    return 0;
}
```

**Input:** `hello`  
**Output:** `olleh`

---

## Example 4: Balanced Parentheses Check
**Check if parentheses are balanced**

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s){
    stack<char> st;
    
    for(char c : s){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);            // push opening brackets
        }
        else{
            if(st.empty()){
                return false;      // closing bracket without opening
            }
            
            char top = st.top();
            st.pop();
            
            // check if brackets match
            if(c == ')' && top != '(') return false;
            if(c == '}' && top != '{') return false;
            if(c == ']' && top != '[') return false;
        }
    }
    
    return st.empty();             // should be empty if balanced
}

int main() {
    string s;
    cin >> s;
    
    if(isBalanced(s)){
        cout << "Balanced" << endl;
    }
    else{
        cout << "Not Balanced" << endl;
    }
    
    return 0;
}
```

**Input:** `{[()]}` → **Output:** `Balanced`  
**Input:** `{[(])}` → **Output:** `Not Balanced`

---

## Example 5: Custom Stack with Maximum Element
**Stack that tracks maximum element**

```cpp
#include <bits/stdc++.h>
using namespace std;

class MaxStack{
    stack<int> mainStack;          // main stack
    stack<int> maxStack;           // stack to track max
    
    public:
    void push(int val){
        mainStack.push(val);
        
        // update max stack
        if(maxStack.empty() || val >= maxStack.top()){
            maxStack.push(val);
        }
    }
    
    void pop(){
        if(mainStack.top() == maxStack.top()){
            maxStack.pop();
        }
        mainStack.pop();
    }
    
    int top(){
        return mainStack.top();
    }
    
    int getMax(){
        return maxStack.top();     // O(1) max element
    }
    
    bool empty(){
        return mainStack.empty();
    }
};

int main() {
    MaxStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(5);
    
    cout << "Max: " << st.getMax() << endl;  // Output: 30
    
    return 0;
}
```

---

# Comparison with Other Data Structures

## Stack vs Queue vs List vs Vector

| Feature | Stack | Queue | List | Vector |
|---------|-------|-------|------|--------|
| **Access Pattern** | LIFO (Last In First Out) | FIFO (First In First Out) | Any position | Any position |
| **Insertion** | Top only | Rear only | Any position | Any position |
| **Deletion** | Top only | Front only | Any position | Any position |
| **Random Access** | ❌ No | ❌ No | ❌ No | ✅ Yes |
| **Top/Front Access** | O(1) | O(1) | O(1) | O(1) |
| **Middle Access** | ❌ Not allowed | ❌ Not allowed | O(n) | O(1) |
| **Use Case** | Undo/Redo, DFS | BFS, Task scheduling | Frequent insert/delete | Random access needed |

---

## When to Use Stack?

✅ **Use Stack when:**
- Need LIFO behavior
- Implementing undo/redo functionality
- Expression evaluation (postfix, prefix)
- Backtracking algorithms (DFS)
- Function call management
- Balanced parentheses checking
- Browser history (back button)

❌ **Avoid Stack when:**
- Need FIFO behavior (use queue)
- Need random access (use vector)
- Need to access middle elements
- Need to iterate from beginning

---

## Applications of Stack

1. **Expression Evaluation**
   - Infix to Postfix conversion
   - Postfix evaluation
   - Prefix evaluation

2. **Backtracking**
   - Maze solving
   - N-Queens problem
   - Sudoku solver

3. **Memory Management**
   - Function call stack
   - Recursion implementation

4. **String Operations**
   - Reverse string
   - Palindrome check
   - Balanced parentheses

5. **Graph Algorithms**
   - Depth First Search (DFS)
   - Topological sorting

---

## Time Complexity Summary

| Operation | Array-based | List-based | STL Stack |
|-----------|-------------|------------|-----------|
| push() | O(1) amortized* | O(1) | O(1) |
| pop() | O(1) | O(1) | O(1) |
| top() | O(1) | O(1) | O(1) |
| size() | O(1) | O(1) | O(1) |
| empty() | O(1) | O(1) | O(1) |

*Amortized: O(n) worst case when resizing array

---

## Important Notes

1. **No Random Access:** Stack does not support accessing elements by index
2. **LIFO Order:** Last element pushed is first to be popped
3. **Top Access Only:** Can only access/modify the top element
4. **Check Empty:** Always check `empty()` before calling `top()` or `pop()`
5. **No Iterators:** STL stack does not provide iterators
6. **Underlying Container:** STL stack uses deque by default, can use vector or list

---

## Common Mistakes to Avoid

1. ❌ Calling `top()` or `pop()` on empty stack - causes undefined behavior
2. ❌ Assuming `pop()` returns the value - it only removes, use `top()` first
3. ❌ Trying to access elements other than top
4. ❌ Using stack when queue is needed (FIFO)
5. ❌ Forgetting to check `empty()` before operations
6. ❌ Confusing stack with vector (no random access in stack)

---

## Best Practices

1. **Always check empty before operations**
   ```cpp
   if(!st.empty()){
       cout << st.top() << endl;
       st.pop();
   }
   ```

2. **Use while loop with empty check**
   ```cpp
   while(!st.empty()){
       // process top
       st.pop();
   }
   ```

3. **Save top value before pop**
   ```cpp
   int value = st.top();
   st.pop();
   // use value
   ```

4. **Choose right underlying container**
   ```cpp
   stack<int, vector<int>> st1;  // using vector
   stack<int, list<int>> st2;    // using list
   stack<int> st3;               // default (deque)
   ```

---

## Stack Declaration Options

```cpp
// Default stack (uses deque)
stack<int> st1;

// Stack using vector as underlying container
stack<int, vector<int>> st2;

// Stack using list as underlying container
stack<int, list<int>> st3;

// Stack of strings
stack<string> st4;

// Stack of pairs
stack<pair<int, string>> st5;

// Stack of vectors
stack<vector<int>> st6;
```

---

## Memory Comparison

| Implementation | Memory per Element | Extra Overhead |
|----------------|-------------------|----------------|
| **Array/Vector** | sizeof(T) | Capacity management |
| **Linked List** | sizeof(T) + 2 pointers | Node pointers |
| **STL Stack (deque)** | sizeof(T) | Block management |

---

## Quick Reference: Common Operations

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    
    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);
    
    // Check size
    cout << st.size() << endl;     // 3
    
    // Check empty
    if(!st.empty()){
        // Access top
        cout << st.top() << endl;  // 30
        
        // Pop top
        st.pop();                   // removes 30
    }
    
    // Clear stack
    while(!st.empty()){
        st.pop();
    }
    
    return 0;
}
```
