# List (STL) - Complete Notes

## Table of Contents
1. [Introduction to List](#introduction-to-list)
2. [List Constructors](#list-constructors)
3. [Capacity Functions](#capacity-functions)
4. [Element Access](#element-access)
5. [Modifiers](#modifiers)
6. [Iterators](#iterators)
7. [Operations](#operations)
8. [Comparison with Vector and Array](#comparison-with-vector-and-array)

---

# Introduction to List

## What is List?
**List is a doubly linked list container in C++ STL**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> mylist;    // creating empty list
    return 0;
}
```

**Key Features:**
- Implemented as doubly linked list
- Fast insertion and deletion at any position
- No random access (cannot use `list[i]`)
- Bi-directional iteration
- Non-contiguous memory allocation

---

# List Constructors

## 1. Default Constructor
**Create an empty list**

```cpp
list<int> mylist;              // empty list
```

---

## 2. Fill Constructor
**Create list with n elements of same value**

```cpp
list<int> mylist(5);           // 5 elements with value 0
// mylist = {0, 0, 0, 0, 0}

list<int> mylist(5, 10);       // 5 elements with value 10
// mylist = {10, 10, 10, 10, 10}
```

---

## 3. Range Constructor
**Create list from another list or array**

```cpp
list<int> list1 = {1, 2, 3, 4, 5};
list<int> list2(list1.begin(), list1.end());  // copy from list1
// list2 = {1, 2, 3, 4, 5}

int arr[] = {10, 20, 30, 40};
list<int> list3(arr, arr + 4);     // create from array
// list3 = {10, 20, 30, 40}
```

---

## 4. Copy Constructor
**Create a copy of existing list**

```cpp
list<int> list1 = {1, 2, 3, 4, 5};
list<int> list2(list1);        // copy of list1
// list2 = {1, 2, 3, 4, 5}
```

---

# Capacity Functions

## 1. size()
**Returns the number of elements in the list**

```cpp
list<int> mylist = {10, 20, 30, 40};
cout << mylist.size() << endl;     // Output: 4
```

**Time Complexity:** O(1)

---

## 2. max_size()
**Returns maximum possible number of elements**

```cpp
list<int> mylist;
cout << mylist.max_size() << endl;  // very large number
```

---

## 3. empty()
**Check if list is empty**

```cpp
list<int> mylist;

if(mylist.empty()){
    cout << "List is empty" << endl;
}

mylist.push_back(10);

if(!mylist.empty()){
    cout << "List is not empty" << endl;
}
```

**Time Complexity:** O(1)

---

## 4. resize()
**Change the size of list**

```cpp
list<int> mylist = {1, 2, 3, 4, 5};

mylist.resize(3);              // reduce size to 3
// mylist = {1, 2, 3}

mylist.resize(5);              // increase size to 5
// mylist = {1, 2, 3, 0, 0}

mylist.resize(7, 100);         // increase size with value 100
// mylist = {1, 2, 3, 0, 0, 100, 100}
```

---

# Element Access

## 1. front()
**Access the first element**

```cpp
list<int> mylist = {10, 20, 30, 40};
cout << mylist.front() << endl;    // Output: 10
```

**Time Complexity:** O(1)

---

## 2. back()
**Access the last element**

```cpp
list<int> mylist = {10, 20, 30, 40};
cout << mylist.back() << endl;     // Output: 40
```

**Time Complexity:** O(1)

---

**Note:** List does NOT support random access using `[]` or `at()` like vector.

```cpp
list<int> mylist = {10, 20, 30};
// cout << mylist[1];    // ERROR - not supported
// cout << mylist.at(1); // ERROR - not supported
```

---

# Modifiers

## 1. push_back()
**Insert element at the end**

```cpp
list<int> mylist;
mylist.push_back(10);          // mylist = {10}
mylist.push_back(20);          // mylist = {10, 20}
mylist.push_back(30);          // mylist = {10, 20, 30}
```

**Time Complexity:** O(1)

---

## 2. push_front()
**Insert element at the beginning**

```cpp
list<int> mylist;
mylist.push_front(10);         // mylist = {10}
mylist.push_front(20);         // mylist = {20, 10}
mylist.push_front(30);         // mylist = {30, 20, 10}
```

**Time Complexity:** O(1)

---

## 3. pop_back()
**Remove last element**

```cpp
list<int> mylist = {10, 20, 30, 40};
mylist.pop_back();             // mylist = {10, 20, 30}
mylist.pop_back();             // mylist = {10, 20}
```

**Time Complexity:** O(1)

---

## 4. pop_front()
**Remove first element**

```cpp
list<int> mylist = {10, 20, 30, 40};
mylist.pop_front();            // mylist = {20, 30, 40}
mylist.pop_front();            // mylist = {30, 40}
```

**Time Complexity:** O(1)

---

## 5. insert()
**Insert element at any position**

```cpp
list<int> mylist = {10, 20, 30, 40};

auto it = mylist.begin();
advance(it, 2);                // move iterator to position 2

mylist.insert(it, 25);         // insert 25 at position 2
// mylist = {10, 20, 25, 30, 40}

// insert multiple elements
mylist.insert(it, 3, 100);     // insert 3 times 100
// mylist = {10, 20, 25, 100, 100, 100, 30, 40}
```

**Time Complexity:** O(1) for insertion, O(n) to reach position

---

## 6. erase()
**Remove element from specific position**

```cpp
list<int> mylist = {10, 20, 30, 40, 50};

auto it = mylist.begin();
advance(it, 2);                // move to position 2

mylist.erase(it);              // erase element at position 2
// mylist = {10, 20, 40, 50}

// erase range
auto it1 = mylist.begin();
auto it2 = mylist.begin();
advance(it1, 1);               // position 1
advance(it2, 3);               // position 3

mylist.erase(it1, it2);        // erase from position 1 to 2
// mylist = {10, 50}
```

**Time Complexity:** O(1) for deletion, O(n) to reach position

---

## 7. assign()
**Assign new content to list**

```cpp
list<int> mylist;

mylist.assign(5, 10);          // assign 5 elements with value 10
// mylist = {10, 10, 10, 10, 10}

list<int> list2 = {1, 2, 3};
mylist.assign(list2.begin(), list2.end());  // assign from another list
// mylist = {1, 2, 3}
```

---

## 8. clear()
**Remove all elements**

```cpp
list<int> mylist = {10, 20, 30, 40};
mylist.clear();                // mylist = {}
cout << mylist.size() << endl; // Output: 0
```

**Time Complexity:** O(n)

---

## 9. swap()
**Exchange contents of two lists**

```cpp
list<int> list1 = {1, 2, 3};
list<int> list2 = {10, 20, 30, 40};

list1.swap(list2);
// list1 = {10, 20, 30, 40}
// list2 = {1, 2, 3}
```

**Time Complexity:** O(1)

---

## 10. emplace()
**Insert element at specific position (efficient)**

```cpp
list<int> mylist = {10, 20, 30};

auto it = mylist.begin();
advance(it, 1);

mylist.emplace(it, 15);        // emplace 15 at position 1
// mylist = {10, 15, 20, 30}
```

---

## 11. emplace_back()
**Insert element at end (efficient)**

```cpp
list<int> mylist = {10, 20, 30};
mylist.emplace_back(40);       // mylist = {10, 20, 30, 40}
```

**More efficient than push_back() for complex objects**

---

## 12. emplace_front()
**Insert element at beginning (efficient)**

```cpp
list<int> mylist = {10, 20, 30};
mylist.emplace_front(5);       // mylist = {5, 10, 20, 30}
```

**More efficient than push_front() for complex objects**

---

# Iterators

## 1. begin() and end()
**Get iterator to first and past-the-last element**

```cpp
list<int> mylist = {10, 20, 30, 40};

// using begin() and end()
for(auto it = mylist.begin(); it != mylist.end(); it++){
    cout << *it << " ";        // Output: 10 20 30 40
}
cout << endl;
```

---

## 2. Iterate Forward
**Traverse from beginning to end**

```cpp
list<int> mylist = {10, 20, 30, 40};

// Method 1: Using iterator
for(auto it = mylist.begin(); it != mylist.end(); it++){
    cout << *it << " ";
}
cout << endl;

// Method 2: Range-based for loop
for(int val : mylist){
    cout << val << " ";
}
cout << endl;
```

---

## 3. Iterate Backward (reverse iterator)
**Traverse from end to beginning**

```cpp
list<int> mylist = {10, 20, 30, 40};

for(auto it = mylist.rbegin(); it != mylist.rend(); it++){
    cout << *it << " ";        // Output: 40 30 20 10
}
cout << endl;
```

---

## 4. next() and prev()
**Move iterator forward or backward**

```cpp
list<int> mylist = {10, 20, 30, 40, 50};

auto it = mylist.begin();      // points to 10

it = next(it);                 // points to 20
it = next(it, 2);              // points to 40

it = prev(it);                 // points to 30
```

---

## 5. advance()
**Move iterator by n positions**

```cpp
list<int> mylist = {10, 20, 30, 40, 50};

auto it = mylist.begin();
advance(it, 3);                // move 3 positions forward
cout << *it << endl;           // Output: 40
```

---

# Operations

## 1. sort()
**Sort elements in ascending order**

```cpp
list<int> mylist = {40, 10, 30, 20, 50};

mylist.sort();                 // ascending order
// mylist = {10, 20, 30, 40, 50}

for(int val : mylist){
    cout << val << " ";
}
cout << endl;
```

**Descending Order:**
```cpp
mylist.sort(greater<int>());   // descending order
// mylist = {50, 40, 30, 20, 10}
```

**Time Complexity:** O(n log n)

---

## 2. reverse()
**Reverse the order of elements**

```cpp
list<int> mylist = {10, 20, 30, 40, 50};

mylist.reverse();
// mylist = {50, 40, 30, 20, 10}

for(int val : mylist){
    cout << val << " ";
}
cout << endl;
```

**Time Complexity:** O(n)

---

## 3. unique()
**Remove consecutive duplicate elements**

```cpp
list<int> mylist = {10, 10, 20, 20, 20, 30, 40, 40};

mylist.unique();               // remove consecutive duplicates
// mylist = {10, 20, 30, 40}

for(int val : mylist){
    cout << val << " ";
}
cout << endl;
```

**Note:** Works only on consecutive duplicates. Sort first for all duplicates.

```cpp
list<int> mylist = {10, 20, 10, 30, 20};
mylist.sort();                 // sort first
mylist.unique();               // then remove duplicates
// mylist = {10, 20, 30}
```

**Time Complexity:** O(n)

---

## 4. remove()
**Remove all elements with specific value**

```cpp
list<int> mylist = {10, 20, 10, 30, 10, 40};

mylist.remove(10);             // remove all 10s
// mylist = {20, 30, 40}

for(int val : mylist){
    cout << val << " ";
}
cout << endl;
```

**Time Complexity:** O(n)

---

## 5. remove_if()
**Remove elements that satisfy a condition**

```cpp
list<int> mylist = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// remove all even numbers
mylist.remove_if([](int x){ return x % 2 == 0; });
// mylist = {1, 3, 5, 7, 9}

for(int val : mylist){
    cout << val << " ";
}
cout << endl;
```

**Time Complexity:** O(n)

---

## 6. merge()
**Merge two sorted lists**

```cpp
list<int> list1 = {1, 3, 5, 7};
list<int> list2 = {2, 4, 6, 8};

list1.merge(list2);            // merge list2 into list1
// list1 = {1, 2, 3, 4, 5, 6, 7, 8}
// list2 = {} (empty)

for(int val : list1){
    cout << val << " ";
}
cout << endl;
```

**Note:** Both lists must be sorted before merging.

**Time Complexity:** O(n + m)

---

## 7. splice()
**Transfer elements from one list to another**

```cpp
list<int> list1 = {1, 2, 3};
list<int> list2 = {10, 20, 30};

auto it = list1.begin();
advance(it, 1);                // position 1 in list1

list1.splice(it, list2);       // transfer entire list2 to list1
// list1 = {1, 10, 20, 30, 2, 3}
// list2 = {} (empty)

for(int val : list1){
    cout << val << " ";
}
cout << endl;
```

**Splice single element:**
```cpp
list<int> list1 = {1, 2, 3};
list<int> list2 = {10, 20, 30};

auto it1 = list1.begin();
advance(it1, 1);

auto it2 = list2.begin();
advance(it2, 1);

list1.splice(it1, list2, it2); // transfer single element
// list1 = {1, 20, 2, 3}
// list2 = {10, 30}
```

**Time Complexity:** O(1) for single element, O(n) for range

---

# Comparison with Vector and Array

## Key Differences

| Feature | Array | Vector | List |
|---------|-------|--------|------|
| **Data Structure** | Fixed array | Dynamic array | Doubly linked list |
| **Size** | Fixed | Dynamic | Dynamic |
| **Random Access** | O(1) with `[]` | O(1) with `[]` | Not supported |
| **Insert at Beginning** | O(n) | O(n) | O(1) |
| **Insert at End** | O(1) | O(1) amortized | O(1) |
| **Insert at Middle** | O(n) | O(n) | O(1) after reaching |
| **Delete at Beginning** | O(n) | O(n) | O(1) |
| **Delete at End** | O(1) | O(1) | O(1) |
| **Delete at Middle** | O(n) | O(n) | O(1) after reaching |
| **Memory** | Contiguous | Contiguous | Non-contiguous |
| **Iterator Invalidation** | N/A | Yes (reallocation) | No |
| **Cache Friendly** | Yes | Yes | No |

---

## When to Use List?

✅ **Use List when:**
- Frequent insertions/deletions at any position
- No need for random access
- Iterator stability is important
- Bi-directional traversal needed

❌ **Avoid List when:**
- Need random access (use vector)
- Memory efficiency is critical (list has overhead)
- Cache performance matters (use vector)
- Need fixed size (use array)

---

## Complete Example: All Functions

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Constructors
    list<int> mylist;              // empty list
    list<int> list1(5, 10);        // {10, 10, 10, 10, 10}
    list<int> list2 = {1, 2, 3, 4, 5};
    
    // Modifiers
    mylist.push_back(10);          // {10}
    mylist.push_back(20);          // {10, 20}
    mylist.push_front(5);          // {5, 10, 20}
    mylist.push_back(30);          // {5, 10, 20, 30}
    
    // Access
    cout << "Front: " << mylist.front() << endl;     // 5
    cout << "Back: " << mylist.back() << endl;       // 30
    
    // Capacity
    cout << "Size: " << mylist.size() << endl;       // 4
    cout << "Empty: " << mylist.empty() << endl;     // 0 (false)
    
    // Iterate
    cout << "Elements: ";
    for(int val : mylist){
        cout << val << " ";
    }
    cout << endl;
    
    // Operations
    mylist.push_back(10);          // add duplicate
    mylist.push_back(20);
    mylist.sort();                 // sort
    mylist.unique();               // remove duplicates
    mylist.reverse();              // reverse
    
    cout << "After operations: ";
    for(int val : mylist){
        cout << val << " ";
    }
    cout << endl;
    
    // Remove
    mylist.pop_front();            // remove first
    mylist.pop_back();             // remove last
    
    // Clear
    mylist.clear();                // remove all
    cout << "After clear size: " << mylist.size() << endl;  // 0
    
    return 0;
}
```

---

## Time Complexity Summary

| Operation | List | Vector | Array |
|-----------|------|--------|-------|
| Access (front/back) | O(1) | O(1) | O(1) |
| Access (random) | O(n) | O(1) | O(1) |
| Insert (front) | O(1) | O(n) | O(n) |
| Insert (back) | O(1) | O(1) | - |
| Insert (middle) | O(1)* | O(n) | O(n) |
| Delete (front) | O(1) | O(n) | O(n) |
| Delete (back) | O(1) | O(1) | - |
| Delete (middle) | O(1)* | O(n) | O(n) |
| Sort | O(n log n) | O(n log n) | O(n log n) |
| Search | O(n) | O(n) | O(n) |

*After reaching the position (O(n) to reach)

---

## Important Notes

1. **No Random Access:** Cannot use `list[i]` or `list.at(i)`
2. **Iterator Stability:** Iterators remain valid after insert/erase (except erased element)
3. **Sorting:** Use `list.sort()` not `sort()` from algorithm library
4. **Memory Overhead:** Each node stores two pointers (next and prev)
5. **Use advance():** To move iterator to specific position
6. **Consecutive Duplicates:** `unique()` removes only consecutive duplicates
7. **Sorted Merge:** Both lists must be sorted before `merge()`

---

## Common Mistakes to Avoid

1. ❌ `mylist[i]` - No random access operator
2. ❌ `sort(mylist.begin(), mylist.end())` - Use `mylist.sort()` instead
3. ❌ Using iterator after erase without updating it
4. ❌ Forgetting to sort before `unique()` for all duplicates
5. ❌ Accessing elements without checking `empty()`
