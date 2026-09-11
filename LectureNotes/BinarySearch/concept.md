# Binary Search in C++

Binary Search is one of the most efficient searching algorithms used to find the position of a target element in a **sorted** array or vector.

It works on the principle of **divide and conquer**, repeatedly dividing the search range in half until the element is found or the range becomes empty.

---

## 🔹 When to Use Binary Search

* The array (or vector) **must be sorted** in ascending or descending order.
* It is used when you need **fast searching** in large datasets.

If the data is **unsorted**, use **Linear Search** instead.

---

## 🔹 Algorithm Steps

1. Start with two pointers:

   ```cpp
   int start = 0;
   int end = n - 1; // where n is size of array
   ```

2. Calculate the middle index:

   ```cpp
   int mid = start + (end - start) / 2; // avoids overflow
   ```

3. Compare `arr[mid]` with the `target`:

   * If `arr[mid] == target` → element found → return `mid`.
   * If `arr[mid] < target` → search in the **right half** → `start = mid + 1`.
   * If `arr[mid] > target` → search in the **left half** → `end = mid - 1`.

4. Repeat steps 2–3 until `start > end`.

---

## 🔹 Example 1: Odd-sized Array

### Code Example:

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
            return mid; // found
        else if (arr[mid] < target)
            start = mid + 1; // search right half
        else
            end = mid - 1; // search left half
    }

    return -1; // not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 16;

    int result = binarySearch(arr, n, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
```

### Output:

```
Element found at index: 4
```

---

## 🔹 Example 2: Even-sized Array

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = 6;
    int target = 7;

    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            cout << "Found at index: " << mid << endl;
            return 0;
        }
        else if (arr[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }

    cout << "Element not found" << endl;
    return 0;
}
```

### Output:

```
Found at index: 3
```

---

## 🔹 Time Complexity Analysis

| Case             | Description                              | Complexity   |
| ---------------- | ---------------------------------------- | ------------ |
| **Best Case**    | Target found at middle                   | **O(1)**     |
| **Average Case** | Target found after few divisions         | **O(log n)** |
| **Worst Case**   | Target not present (loop runs until end) | **O(log n)** |

### Space Complexity:

* **O(1)** (Iterative version)
* **O(log n)** (Recursive version due to call stack)

---

## 🔹 Visualization Example

Imagine searching for `16` in:

```
[2, 5, 8, 12, 16, 23, 38]
```

* Step 1: mid = 3 → arr[mid] = 12 → 16 > 12 → right half
* Step 2: start = 4, end = 6 → mid = 5 → arr[mid] = 23 → 16 < 23 → left half
* Step 3: start = 4, end = 4 → mid = 4 → arr[mid] = 16 → ✅ Found

---

## 🔹 Key Points to Remember

* Works only on **sorted arrays**.
* Reduces the search space by **half** every iteration.
* Formula for mid must be: `mid = start + (end - start)/2` to prevent overflow.
* Time Complexity ≈ **O(log n)**.
* Space Complexity = **O(1)** (iterative approach).

---

## 🔹 Practice Questions

1. Search element in a sorted array.
2. Find the first and last occurrence of an element.
3. Find the index where element should be inserted (lower bound / upper bound).
4. Find the square root of a number using binary search.
5. Find peak element in a mountain array.

---

### ✅ Summary

Binary Search is a fundamental algorithm that forms the base for many **advanced searching and optimization problems**. Once you master it, you can solve problems like **search in rotated array**, **finding square root**, **search in 2D matrix**, etc.

---
