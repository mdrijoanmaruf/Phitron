
# ✅ Vector

A compact reference for C++ `std::vector` built-in functions and common usage patterns. Keep this as a quick cheat sheet while coding.

---

## 📋 Table of contents
- [1️⃣ Initialization](#1️⃣-initialization)
- [2️⃣ Capacity Functions](#2️⃣-capacity-functions)
- [3️⃣ Modifiers](#3️⃣-modifiers)
- [4️⃣ Element Access](#4️⃣-element-access)
- [5️⃣ Iterators](#5️⃣-iterators)

---

## 1️⃣ Initialization

**`vector<type> v;`** — Creates an empty vector — **Time: O(1)**

```cpp
vector<int> v;   // empty vector, size = 0
```

**`vector<type> v(N);`** — Creates a vector with N elements — **Time: O(N)**

```cpp
vector<int> v(5);    // size = 5, all values = 0
```

**`vector<type> v(N, V);`** — Creates vector with N elements, each = V — **Time: O(N)**

```cpp
vector<int> v(5, 10);   // size = 5, values = 10 10 10 10 10
```

**`vector<type> v(v2);`** — Copies another vector — **Time: O(N)**

```cpp
vector<int> a = {1,2,3};
vector<int> b(a);   // copy of a
```

**`vector<type> v(A, A+N);`** — Copies from array — **Time: O(N)**

```cpp
int arr[] = {1,2,3};
vector<int> v(arr, arr+3);   // copies array into vector
```

---

## 2️⃣ Capacity Functions

**`v.size()`** — Returns number of elements — **Time: O(1)**

```cpp
cout << v.size();   // prints size of vector
```

**`v.max_size()`** — Max possible elements — **Time: O(1)**

```cpp
cout << v.max_size();
```

**`v.capacity()`** — Shows allocated capacity — **Time: O(1)**

```cpp
cout << v.capacity();
```

**`v.clear()`** — Removes all elements (keeps allocated memory) — **Time: O(N)**

```cpp
v.clear();    // vector becomes empty
```

**`v.empty()`** — Checks if empty — **Time: O(1)**

```cpp
if (v.empty()) cout << "Empty";
```

**`v.resize()`** — Changes size (grows or shrinks) — **Time: O(N)**

```cpp
v.resize(10);   // increases or decreases size
```

---

## 3️⃣ Modifiers

**`v = / v.assign()`** — Assigns values — **Time: O(N)**

```cpp
vector<int> a = {1,2,3};
vector<int> b;
b = a;                  // assignment
b.assign(5, 100);       // 5 elements, each = 100
```

**`v.push_back()`** — Adds element at end — **Time: Amortized O(1)** (worst-case O(N) when reallocating)

```cpp
v.push_back(10);   // inserts 10
```

**`v.pop_back()`** — Removes last element — **Time: O(1)**

```cpp
v.pop_back();
```

**`v.insert()`** — Inserts at position — **Time: O(N)** (shifts elements; may also cause reallocation)

```cpp
v.insert(v.begin() + 1, 20);  // insert 20 at index 1
```

**`v.erase()`** — Delete position / range — **Time: O(N)** (shifts elements after erased range)

```cpp
v.erase(v.begin());         // erase first element
// v.erase(v.begin(), v.begin() + 3); → erase range
```

**`replace(begin, end, value, new_value)`** — Replace values (from <algorithm>) — **Time: O(N)**

```cpp
replace(v.begin(), v.end(), 5, 10);  // replace all 5 → 10
```

**`find(begin, end, V)`** — Find value (from <algorithm>) — **Time: O(N)**

```cpp
auto it = find(v.begin(), v.end(), 10);
if (it != v.end()) cout << "Found";
```

---

## 4️⃣ Element Access

**`v[i]`** — Access by index (no bounds check) — **Time: O(1)**

```cpp
cout << v[2];
```

**`v.at(i)`** — Safe access (throws `out_of_range` on invalid index) — **Time: O(1)**

```cpp
cout << v.at(2);
```

**`v.front()`** — First element — **Time: O(1)**

```cpp
cout << v.front();
```

**`v.back()`** — Last element — **Time: O(1)**

```cpp
cout << v.back();
```

---

## 5️⃣ Iterators

**`v.begin()`** — Iterator to first element — **Time: O(1)**

```cpp
auto it = v.begin();
cout << *it;
```

**`v.end()`** — Iterator past the last element — **Time: O(1)**

```cpp
auto it = v.end();
```



