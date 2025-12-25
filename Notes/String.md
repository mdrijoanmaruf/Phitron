# C++ String Notes

`std::string` is part of the `<string>` header in C++ and represents a dynamic character container.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "Hello World";
}
```

---

## Capacity Functions

### `size()` - Returns number of characters

```cpp
string s = "Programming";
cout << s.size();   // Output: 11
```

---

### `max_size()` - Maximum size a string can hold

```cpp
string s = "ABC";
cout << s.max_size();   // System dependent (very large number)
```

---

### `capacity()` - Current allocated storage

```cpp
string s = "Hello";
cout << s.capacity(); // capacity >= size (depends on implementation)
```

---

### `clear()` - Makes string empty

```cpp
string s = "Hello";
s.clear();
cout << s;          // Output: (empty)
cout << s.size();   // Output: 0
```

---

### `empty()` - Checks if string is empty

```cpp
string s = "";
if(s.empty())
    cout << "String is empty";
```

---

### `resize(n)` - Changes string length

```cpp
string s = "Hello";
s.resize(10,'*');
cout << s;     // Output: Hello*****
```

---

## Element Access

### `s[i]` - Access character (No bounds check)

```cpp
string s = "Hello";
cout << s[1];   // Output: e
```

---

### `at(i)` - Access with bounds checking

```cpp
string s = "Hello";
cout << s.at(4);   // Output: o
// cout << s.at(10); // Throws exception (safe)
```

---

### `front()` - First character

```cpp
string s = "Hello";
cout << s.front();   // Output: H
```

---

### `back()` - Last character

```cpp
string s = "Hello";
cout << s.back();    // Output: o
```

---

## Modifiers

### `+=` - Append string

```cpp
string s = "Hello";
s += " World";
cout << s;    // Hello World
```

---

### `append()` - Append string

```cpp
string s = "Hello";
s.append(" C++");
cout << s;     // Hello C++
```

---

### `push_back()` - Add single character

```cpp
string s = "Hi";
s.push_back('!');
cout << s;     // Hi!
```

---

### `pop_back()` - Remove last character

```cpp
string s = "Hello!";
s.pop_back();
cout << s;     // Hello
```

---

### Assignment (`=` or `assign()`)

```cpp
string s;
s = "New Text";
cout << s;
```

```cpp
string s;
s.assign("Assigned Text");
cout << s;
```

---

### `erase()` - Remove characters

```cpp
string s = "Programming";
s.erase(3,4);       // erase from index 3, remove 4 chars
cout << s;          // Proing
```

---

### `replace()` - Replace portion

```cpp
string s = "I love Java";
s.replace(7,4,"C++");   // replace from index 7, 4 chars
cout << s;              // I love C++
```

---

### `insert()` - Insert at position

```cpp
string s = "Hello";
s.insert(5, " World");
cout << s;      // Hello World
```

---

## Other Useful Functions

### `find()` - Search substring

```cpp
string s = "Programming";
cout << s.find("gram");   // Output: 3
```

---

### `substr()` - Extract substring

```cpp
string s = "Programming";
cout << s.substr(0,4);    // Prog
```

---

### `compare()` - Compare strings

```cpp
string a = "ABC";
string b = "ABC";

if(a.compare(b) == 0)
    cout << "Equal";
```

---

### `to_string()` - Convert number to string

```cpp
int x = 100;
string s = to_string(x);
cout << s;
```

---

## Iterators

Iterators work like pointers to access string characters. They allow you to traverse and manipulate the string.

### `begin()` and `end()`

Return iterators pointing to the beginning and one past the end of the string.

```cpp
string s = "ABC";

// Using iterators
for(auto it = s.begin(); it != s.end(); it++)
    cout << *it << " ";    
// Output: A B C
```

---

### `rbegin()` and `rend()`

Return reverse iterators for backward traversal.

```cpp
string s = "Hello";

for(auto it = s.rbegin(); it != s.rend(); it++)
    cout << *it;
// Output: olleH
```

---

### Range-Based Loop (Modern Way)

Simplest and most readable way to iterate through a string.

```cpp
string s = "Hello";
for(char c : s)
    cout << c << " ";
// Output: H e l l o
```

---

### Iterator Operations

```cpp
for(string:: iterator it = s.begin(); it < s.end(); it++){
        cout << *it << endl;
}
for(auto it = s.begin(); it < s.end(); it++){
    cout << *it << endl;
}
```

## String Input with Spaces

Use `getline()` (not `cin`).

```cpp
string s;
getline(cin, s);
```

If used after `cin >>`, add:

```cpp
cin.ignore();
getline(cin, s);
```

---

## Multiple String Inputs

**Multiple words separately**

```cpp
string a,b,c;
cin >> a >> b >> c;
```

**Multiple full lines**

```cpp
string s1,s2;
getline(cin,s1);
getline(cin,s2);
```

---

##  `stringstream` (Split / Parse Words & Numbers)

Include:

```cpp
#include <sstream>
```

**Split words**

```cpp
string s = "I love coding";
stringstream ss(s);
string word;

while(ss >> word)
    cout << word << endl;
```

**Convert string → number**

```cpp
string s = "123";
stringstream ss(s);
int x;
ss >> x;
```



### String Constructor , sort using using sort() , range bashed loop , reverse function , 