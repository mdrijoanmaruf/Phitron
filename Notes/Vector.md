
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

* **`vector<type> v;`**
  * Creates an empty vector

```cpp
vector<int> v;   // empty vector, size = 0
```

* **`vector<type> v(N);`**
  * Creates a vector with N elements

```cpp
vector<int> v(5);    // size = 5, all values = 0
```

* **`vector<type> v(N, V);`**
  * Creates vector with N elements, each = V

```cpp
vector<int> v(5, 10);   // size = 5, values = 10 10 10 10 10
```

* **`vector<type> v(v2);`**
  * Copies another vector

```cpp
vector<int> a = {1,2,3};
vector<int> b(a);   // copy of a
```

* **`vector<type> v(A, A+N);`**
  * Copies from array

```cpp
int arr[] = {1,2,3};
vector<int> v(arr, arr+3);   // copies array into vector
```

---

## 2️⃣ Capacity Functions

* **`v.size()`** — Returns number of elements

```cpp
cout << v.size();   // prints size of vector
```

* **`v.max_size()`** — Max possible elements

```cpp
cout << v.max_size();
```

* **`v.capacity()`** — Shows allocated capacity

```cpp
cout << v.capacity();
```

* **`v.clear()`** — Removes all elements (keeps allocated memory)

```cpp
v.clear();    // vector becomes empty
```

* **`v.empty()`** — Checks if empty

```cpp
if (v.empty()) cout << "Empty";
```

* **`v.resize()`** — Changes size (grows or shrinks)

```cpp
v.resize(10);   // increases or decreases size
```

---

## 3️⃣ Modifiers

* **`v = / v.assign()`** — Assigns values

```cpp
vector<int> a = {1,2,3};
vector<int> b;
b = a;                  // assignment
b.assign(5, 100);       // 5 elements, each = 100
```

* **`v.push_back()`** — Adds element at end

```cpp
v.push_back(10);   // inserts 10
```

* **`v.pop_back()`** — Removes last element

```cpp
v.pop_back();
```

* **`v.insert()`** — Inserts at position

```cpp
v.insert(v.begin() + 1, 20);  // insert 20 at index 1
```

* **`v.erase()`** — Delete position / range

```cpp
v.erase(v.begin());         // erase first element
// v.erase(v.begin(), v.begin() + 3); → erase range
```

* **`replace(begin, end, value, new_value)`** — Replace values (from <algorithm>)

```cpp
replace(v.begin(), v.end(), 5, 10);  // replace all 5 → 10
```

* **`find(begin, end, V)`** — Find value (from <algorithm>)

```cpp
auto it = find(v.begin(), v.end(), 10);
if (it != v.end()) cout << "Found";
```

---

## 4️⃣ Element Access

* **`v[i]`** — Access by index (no bounds check)

```cpp
cout << v[2];
```

* **`v.at(i)`** — Safe access (throws `out_of_range` on invalid index)

```cpp
cout << v.at(2);
```

* **`v.front()`** — First element

```cpp
cout << v.front();
```

* **`v.back()`** — Last element

```cpp
cout << v.back();
```

---

## 5️⃣ Iterators

* **`v.begin()`** — Iterator to first element

```cpp
auto it = v.begin();
cout << *it;
```

* **`v.end()`** — Iterator past the last element

```cpp
auto it = v.end();
```

> 💡 Tip: to get an iterator to the last element use `--v.end()` (ensure `v` is non-empty).

---

*All original content preserved and formatted for readability.*


