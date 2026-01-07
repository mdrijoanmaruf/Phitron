
# Vector (STL) - Complete Notes

## Table of Contents
1. [Introduction to Vector](#introduction-to-vector)
2. [Vector Constructors](#vector-constructors)
3. [Capacity Functions](#capacity-functions)
4. [Element Access](#element-access)
5. [Modifiers](#modifiers)
6. [Iterators](#iterators)
7. [Operations](#operations)
8. [Comparison with List and Array](#comparison-with-list-and-array)

---

# Introduction to Vector

## What is Vector?
**Vector is a dynamic array container in C++ STL**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v;    // creating empty vector
    return 0;
}
```

**Key Features:**
- Implemented as dynamic array
- Random access in O(1) time
- Automatic resizing when needed
- Contiguous memory allocation
- Cache-friendly performance

---

# Vector Constructors

## 1. Default Constructor

**Create an empty vector**

```cpp
vector<int> v;              // empty vector, size = 0
```

**Time Complexity:** O(1)

---

## 2. Fill Constructor
**Create a vector with N elements**

```cpp
vector<int> v(5);           // size = 5, all values = 0
// v = {0, 0, 0, 0, 0}

vector<int> v(5, 10);       // size = 5, all values = 10
// v = {10, 10, 10, 10, 10}
```

**Time Complexity:** O(N)

---

## 3. Range Constructor
**Create vector from another vector or array**

```cpp
vector<int> v1 = {1, 2, 3, 4, 5};
vector<int> v2(v1.begin(), v1.end());  // copy from v1
// v2 = {1, 2, 3, 4, 5}

int arr[] = {10, 20, 30, 40};
vector<int> v3(arr, arr + 4);   // create from array
// v3 = {10, 20, 30, 40}
```

**Time Complexity:** O(N)

---

## 4. Copy Constructor
**Create a copy of existing vector**

```cpp
vector<int> v1 = {1, 2, 3, 4, 5};
vector<int> v2(v1);         // copy of v1
// v2 = {1, 2, 3, 4, 5}
```

**Time Complexity:** O(N)

---

# Capacity Functions

## 1. size()
**Returns the number of elements in the vector**

```cpp
vector<int> v = {10, 20, 30, 40};
cout << v.size() << endl;     // Output: 4
```

**Time Complexity:** O(1)

---

## 2. max_size()
**Returns maximum possible number of elements**

```cpp
vector<int> v;
cout << v.max_size() << endl;  // very large number
```

**Time Complexity:** O(1)

---

## 3. capacity()
**Returns the allocated storage capacity**

```cpp
vector<int> v = {10, 20, 30};
cout << v.capacity() << endl;  // may be >= size
```

**Time Complexity:** O(1)

**Note:** Capacity is the size of allocated storage, which can be >= size. When vector grows beyond capacity, it reallocates memory.

---

## 4. empty()
**Check if vector is empty**

```cpp
vector<int> v;

if(v.empty()){
    cout << "Vector is empty" << endl;
}

v.push_back(10);

if(!v.empty()){
    cout << "Vector is not empty" << endl;
}
```

**Time Complexity:** O(1)

---

## 5. clear()
**Remove all elements**

```cpp
vector<int> v = {10, 20, 30, 40};
v.clear();                     // v = {}
cout << v.size() << endl;      // Output: 0
```

**Note:** Clears elements but keeps allocated memory (capacity unchanged).

**Time Complexity:** O(N)

---

## 6. resize()
**Change the size of vector**

```cpp
vector<int> v = {1, 2, 3, 4, 5};

v.resize(3);                   // reduce size to 3
// v = {1, 2, 3}

v.resize(5);                   // increase size to 5
// v = {1, 2, 3, 0, 0}

v.resize(7, 100);              // increase size with value 100
// v = {1, 2, 3, 0, 0, 100, 100}
```

**Time Complexity:** O(N)

---

# Element Access

## 1. operator[]
**Access element by index (no bounds check)**

```cpp
vector<int> v = {10, 20, 30, 40};
cout << v[0] << endl;          // Output: 10
cout << v[2] << endl;          // Output: 30

v[1] = 25;                     // modify element
// v = {10, 25, 30, 40}
```

**Time Complexity:** O(1)

**Warning:** No bounds checking - accessing invalid index is undefined behavior.

---

## 2. at()
**Safe access with bounds checking**

```cpp
vector<int> v = {10, 20, 30, 40};
cout << v.at(2) << endl;       // Output: 30

// v.at(10);                   // throws out_of_range exception
```

**Time Complexity:** O(1)

**Note:** Throws `out_of_range` exception if index is invalid.

---

## 3. front()
**Access the first element**

```cpp
vector<int> v = {10, 20, 30, 40};
cout << v.front() << endl;     // Output: 10
```

**Time Complexity:** O(1)

---

## 4. back()
**Access the last element**

```cpp
vector<int> v = {10, 20, 30, 40};
cout << v.back() << endl;      // Output: 40
```

**Time Complexity:** O(1)

---

# Modifiers

## 1. assign()
**Assign new content to vector**

```cpp
vector<int> v;

v.assign(5, 10);               // assign 5 elements with value 10
// v = {10, 10, 10, 10, 10}

vector<int> v2 = {1, 2, 3};
v.assign(v2.begin(), v2.end());  // assign from another vector
// v = {1, 2, 3}
```

**Time Complexity:** O(N)

---

## 2. push_back()
**Insert element at the end**

```cpp
vector<int> v;
v.push_back(10);               // v = {10}
v.push_back(20);               // v = {10, 20}
v.push_back(30);               // v = {10, 20, 30}
```

**Time Complexity:** Amortized O(1), worst-case O(N) when reallocation occurs

---

## 3. pop_back()
**Remove last element**

```cpp
vector<int> v = {10, 20, 30, 40};
v.pop_back();                  // v = {10, 20, 30}
v.pop_back();                  // v = {10, 20}
```

**Time Complexity:** O(1)

---

## 4. insert()
**Insert element at specific position**

```cpp
vector<int> v = {10, 20, 30, 40};

v.insert(v.begin() + 1, 15);   // insert 15 at index 1
// v = {10, 15, 20, 30, 40}

// insert multiple elements
v.insert(v.begin() + 2, 3, 100);  // insert 3 times 100
// v = {10, 15, 100, 100, 100, 20, 30, 40}
```

**Time Complexity:** O(N) - shifts elements and may cause reallocation

---

## 5. erase()
**Remove element from specific position**

```cpp
vector<int> v = {10, 20, 30, 40, 50};

v.erase(v.begin() + 2);        // erase element at index 2
// v = {10, 20, 40, 50}

// erase range
v.erase(v.begin() + 1, v.begin() + 3);  // erase from index 1 to 2
// v = {10, 50}
```

**Time Complexity:** O(N) - shifts elements after erased range

---

## 6. swap()
**Exchange contents of two vectors**

```cpp
vector<int> v1 = {1, 2, 3};
vector<int> v2 = {10, 20, 30, 40};

v1.swap(v2);
// v1 = {10, 20, 30, 40}
// v2 = {1, 2, 3}
```

**Time Complexity:** O(1)

---

## 7. emplace()
**Insert element at specific position (efficient)**

```cpp
vector<int> v = {10, 20, 30};
v.emplace(v.begin() + 1, 15);  // emplace 15 at index 1
// v = {10, 15, 20, 30}
```

**More efficient than insert() for complex objects**

**Time Complexity:** O(N)

---

## 8. emplace_back()
**Insert element at end (efficient)**

```cpp
vector<int> v = {10, 20, 30};
v.emplace_back(40);            // v = {10, 20, 30, 40}
```

**More efficient than push_back() for complex objects**

**Time Complexity:** Amortized O(1)

---

# Iterators

## 1. begin() and end()
**Get iterator to first and past-the-last element**

```cpp
vector<int> v = {10, 20, 30, 40};

// using begin() and end()
for(auto it = v.begin(); it != v.end(); it++){
    cout << *it << " ";        // Output: 10 20 30 40
}
cout << endl;
```

**Time Complexity:** O(1)

---

## 2. Iterate Forward
**Traverse from beginning to end**

```cpp
vector<int> v = {10, 20, 30, 40};

// Method 1: Using iterator
for(auto it = v.begin(); it != v.end(); it++){
    cout << *it << " ";
}
cout << endl;

// Method 2: Using index
for(int i = 0; i < v.size(); i++){
    cout << v[i] << " ";
}
cout << endl;

// Method 3: Range-based for loop
for(int val : v){
    cout << val << " ";
}
cout << endl;
```

---

## 3. Iterate Backward (reverse iterator)
**Traverse from end to beginning**

```cpp
vector<int> v = {10, 20, 30, 40};

for(auto it = v.rbegin(); it != v.rend(); it++){
    cout << *it << " ";        // Output: 40 30 20 10
}
cout << endl;
```

---

## 4. next() and prev()
**Move iterator forward or backward**

```cpp
vector<int> v = {10, 20, 30, 40, 50};

auto it = v.begin();           // points to 10

it = next(it);                 // points to 20
it = next(it, 2);              // points to 40

it = prev(it);                 // points to 30
```

---

# Operations

## 1. sort() - Using Algorithm Library
**Sort elements in ascending order**

```cpp
#include <algorithm>

vector<int> v = {40, 10, 30, 20, 50};

sort(v.begin(), v.end());      // ascending order
// v = {10, 20, 30, 40, 50}

for(int val : v){
    cout << val << " ";
}
cout << endl;
```

**Descending Order:**
```cpp
sort(v.begin(), v.end(), greater<int>());  // descending order
// v = {50, 40, 30, 20, 10}
```

**Time Complexity:** O(N log N)

---

## 2. reverse() - Using Algorithm Library
**Reverse the order of elements**

```cpp
#include <algorithm>

vector<int> v = {10, 20, 30, 40, 50};

reverse(v.begin(), v.end());
// v = {50, 40, 30, 20, 10}

for(int val : v){
    cout << val << " ";
}
cout << endl;
```

**Time Complexity:** O(N)

---

## 3. find() - Using Algorithm Library
**Find first occurrence of a value**

```cpp
#include <algorithm>

vector<int> v = {10, 20, 30, 40, 50};

auto it = find(v.begin(), v.end(), 30);

if(it != v.end()){
    cout << "Found at index: " << (it - v.begin()) << endl;  // Output: 2
}
else{
    cout << "Not found" << endl;
}
```

**Time Complexity:** O(N)

---

## 4. replace() - Using Algorithm Library
**Replace all occurrences of a value**

```cpp
#include <algorithm>

vector<int> v = {10, 20, 10, 30, 10, 40};

replace(v.begin(), v.end(), 10, 100);  // replace all 10 with 100
// v = {100, 20, 100, 30, 100, 40}

for(int val : v){
    cout << val << " ";
}
cout << endl;
```

**Time Complexity:** O(N)

---

## 5. Binary Search (on sorted vector)
**Search in sorted vector efficiently**

```cpp
#include <algorithm>

vector<int> v = {10, 20, 30, 40, 50};  // must be sorted

// check if element exists
if(binary_search(v.begin(), v.end(), 30)){
    cout << "Found" << endl;
}

// find lower bound (first position where element can be inserted)
auto lb = lower_bound(v.begin(), v.end(), 30);
cout << "Lower bound index: " << (lb - v.begin()) << endl;  // 2

// find upper bound (last position where element can be inserted)
auto ub = upper_bound(v.begin(), v.end(), 30);
cout << "Upper bound index: " << (ub - v.begin()) << endl;  // 3
```

**Time Complexity:** O(log N)

---

# Comparison with List and Array

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

## When to Use Vector?

✅ **Use Vector when:**
- Need random access to elements
- Frequent access by index
- Adding elements at the end
- Memory efficiency is important
- Cache performance matters
- Most common use case

❌ **Avoid Vector when:**
- Frequent insertions/deletions at beginning or middle
- Need guaranteed iterator stability
- Fixed size is required (use array)

---

## Complete Example: All Functions

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Constructors
    vector<int> v;                 // empty vector
    vector<int> v1(5, 10);         // {10, 10, 10, 10, 10}
    vector<int> v2 = {1, 2, 3, 4, 5};
    
    // Modifiers
    v.push_back(10);               // {10}
    v.push_back(20);               // {10, 20}
    v.push_back(30);               // {10, 20, 30}
    v.insert(v.begin() + 1, 15);   // {10, 15, 20, 30}
    
    // Access
    cout << "First: " << v.front() << endl;      // 10
    cout << "Last: " << v.back() << endl;        // 30
    cout << "Index 2: " << v[2] << endl;         // 20
    cout << "At 1: " << v.at(1) << endl;         // 15
    
    // Capacity
    cout << "Size: " << v.size() << endl;        // 4
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Empty: " << v.empty() << endl;      // 0 (false)
    
    // Iterate
    cout << "Elements: ";
    for(int val : v){
        cout << val << " ";
    }
    cout << endl;
    
    // Operations
    v.push_back(10);               // add duplicate
    sort(v.begin(), v.end());      // sort
    reverse(v.begin(), v.end());   // reverse
    
    cout << "After operations: ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    
    // Remove
    v.pop_back();                  // remove last
    v.erase(v.begin());            // remove first
    
    // Clear
    v.clear();                     // remove all
    cout << "After clear size: " << v.size() << endl;  // 0
    
    return 0;
}
```

---

## Time Complexity Summary

| Operation | Vector | List | Array |
|-----------|--------|------|-------|
| Access (by index) | O(1) | O(n) | O(1) |
| Access (front/back) | O(1) | O(1) | O(1) |
| Insert (front) | O(n) | O(1) | O(n) |
| Insert (back) | O(1)* | O(1) | - |
| Insert (middle) | O(n) | O(1)** | O(n) |
| Delete (front) | O(n) | O(1) | O(n) |
| Delete (back) | O(1) | O(1) | - |
| Delete (middle) | O(n) | O(1)** | O(n) |
| Sort | O(n log n) | O(n log n) | O(n log n) |
| Search | O(n) | O(n) | O(n) |
| Binary Search | O(log n) | - | O(log n) |

*Amortized O(1), worst-case O(n) with reallocation  
**After reaching the position (O(n) to reach)

---

## Important Notes

1. **Random Access:** Supports `v[i]` and `v.at(i)` in O(1)
2. **Dynamic Resizing:** Automatically grows when capacity is exceeded
3. **Reallocation:** May invalidate iterators when capacity changes
4. **Capacity vs Size:** Capacity ≥ size; extra space to avoid frequent reallocations
5. **Use Algorithm Library:** For sort, reverse, find, replace, etc.
6. **Bounds Checking:** Use `at()` for safe access, `[]` for performance
7. **Amortized Complexity:** push_back is O(1) on average, O(n) occasionally

---

## Common Mistakes to Avoid

1. ❌ Accessing out of bounds with `[]` - use `at()` for safety
2. ❌ Using iterator after erase without updating it
3. ❌ Modifying vector while iterating (iterator invalidation)
4. ❌ Forgetting that insert/erase at beginning is O(n)
5. ❌ Not reserving capacity when final size is known - causes multiple reallocations
6. ❌ Using `v.size() - 1` when vector is empty (underflow)

---

## Performance Tips

1. **Use reserve()** if you know final size to avoid reallocations
   ```cpp
   vector<int> v;
   v.reserve(1000);  // allocate space for 1000 elements
   ```

2. **Use emplace_back()** instead of push_back() for complex objects
   ```cpp
   v.emplace_back(args...);  // constructs in-place
   ```

3. **Clear vs Resize vs Shrink**
   ```cpp
   v.clear();              // removes elements, keeps capacity
   v.resize(0);            // same as clear
   v.shrink_to_fit();      // reduces capacity to match size
   ```



