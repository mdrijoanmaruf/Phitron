# Binary Search Algorithm

## What is Binary Search?

Binary Search is an efficient searching algorithm that works on **sorted arrays**. It eliminates half of the remaining elements with each comparison by dividing the search space in half, making it much faster than linear search.

**Key Prerequisite:** The array must be sorted.

---

## How It Works

1. Start with the entire sorted array
2. Compare the middle element with the target value
3. If middle element equals target → Found!
4. If target is smaller → Search the left half
5. If target is larger → Search the right half
6. Repeat until found or search space is empty

---

## Algorithm Steps (Iterative Approach)

```
1. Initialize left = 0, right = n-1
2. While left <= right:
   a. Calculate mid = left + (right - left) / 2
   b. If arr[mid] == target, return mid
   c. If arr[mid] > target, right = mid - 1
   d. If arr[mid] < target, left = mid + 1
3. If not found, return -1
```

---

## C++ Code Example (Iterative)

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Iterative Binary Search
int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        // Calculate middle index (avoids integer overflow)
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Target found at index mid
        }
        else if (arr[mid] > target) {
            right = mid - 1;  // Search in left half
        }
        else {
            left = mid + 1;  // Search in right half
        }
    }
    
    return -1;  // Target not found
}

// Main function
int main() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int target = 23;
    
    int result = binarySearch(arr, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    
    return 0;
}
```

**Output:**
```
Element found at index: 5
```

---

## C++ Code Example (Recursive)

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Recursive Binary Search
int binarySearchRecursive(vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1;  // Target not found
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;  // Target found
    }
    else if (arr[mid] > target) {
        return binarySearchRecursive(arr, target, left, mid - 1);  // Search left
    }
    else {
        return binarySearchRecursive(arr, target, mid + 1, right);  // Search right
    }
}

// Main function
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;
    
    int result = binarySearchRecursive(arr, target, 0, arr.size() - 1);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found!" << endl;
    }
    
    return 0;
}
```

**Output:**
```
Element found at index: 3
```

---

## Time Complexity Analysis

| Operation | Complexity |
|-----------|-----------|
| **Best Case** | O(1) - When target is at the middle position on first check |
| **Average Case** | O(log n) - Element found in middle somewhere during search |
| **Worst Case** | O(log n) - Element at one end or not present |

### Why O(log n)?
- Each iteration eliminates half the remaining elements
- Maximum iterations needed = log₂(n)
- Example: For n = 1000, max iterations ≈ 10

---

## Space Complexity

| Approach | Space |
|----------|-------|
| **Iterative** | O(1) - Only uses a few variables |
| **Recursive** | O(log n) - Call stack depth is log n |

---

## Advantages

✅ Very fast for large sorted datasets  
✅ O(log n) complexity is excellent  
✅ Simple to implement  
✅ Better than linear search O(n)  

---

## Disadvantages

❌ **Requires sorted array** - Must sort first if not already sorted  
❌ Not suitable for unsorted data  
❌ Poor performance with linked lists (can't access middle efficiently)  
❌ Overhead of sorting might be significant for small arrays  

---

## When to Use Binary Search

- ✔ Array is already sorted
- ✔ Frequent search operations on large datasets
- ✔ Memory efficiency is important
- ✔ Real-time search applications

---

## Example Walkthrough

**Array:** `[2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78]`  
**Target:** `23`

```
Step 1: left=0, right=10, mid=5 → arr[5]=23 ✓ FOUND!
Result: Index 5
```

**Target:** `100` (not in array)

```
Step 1: left=0, right=10, mid=5 → arr[5]=23 < 100 → left=6
Step 2: left=6, right=10, mid=8 → arr[8]=56 < 100 → left=9
Step 3: left=9, right=10, mid=9 → arr[9]=67 < 100 → left=10
Step 4: left=10, right=10, mid=10 → arr[10]=78 < 100 → left=11
Step 5: left=11, right=10 → left > right → NOT FOUND
Result: -1
```

---

## Important Tips

💡 **Use `mid = left + (right - left) / 2`** instead of `(left + right) / 2` to avoid integer overflow  
💡 **Always ensure array is sorted** before applying binary search  
💡 **For very large datasets**, binary search is significantly faster than linear search  
💡 **Can be modified** to find first occurrence, last o`ccurrence, or closest element  

