# 🧮 C++ Vectors — Notes (4 October 2025)

---

## 🔹 Introduction

Vectors in C++ are **dynamic arrays** that can **resize at runtime**. Unlike regular arrays with fixed sizes, vectors manage their own memory as elements are added or removed.

To use vectors, include the header:

```cpp
#include <vector>
```

Then create a vector:

```cpp
vector<int> vec; // Creates a vector of integers
```

---

## ⚙️ Common Functions

| Function      | Description                                |
| ------------- | ------------------------------------------ |
| `push_back()` | Adds an element at the end                 |
| `pop_back()`  | Removes the last element                   |
| `front()`     | Returns the first element                  |
| `back()`      | Returns the last element                   |
| `size()`      | Returns the number of elements             |
| `empty()`     | Checks if the vector is empty              |
| `at(index)`   | Accesses element at the given index safely |

---

## 🧠 Static vs Dynamic Allocation

* **Static allocation** → Done at **compile time**.
* **Dynamic allocation** → Done at **runtime**.

When a vector is empty and you start pushing elements:

* First element → vector size = 1
* Push another → capacity doubles (1 → 2)
* Push another → capacity doubles again (2 → 4)
* This process continues as elements are added.

This doubling mechanism allows efficient dynamic resizing.

---

## 📏 Vector Properties

| Property       | Description                         |
| -------------- | ----------------------------------- |
| **size()**     | Number of elements currently stored |
| **capacity()** | Total space currently allocated     |

📌 Example:
If you add 3 elements, the vector might have `size = 3` but `capacity = 4`.

---

## 🔍 Reference and Address

Using `&` before a vector variable gives the **address** (or creates an alias) of that vector in memory.

Example:

```cpp
vector<int> v = {1, 2, 3};
cout << &v; // Prints memory address of the vector
```

---

## 🧩 Bit Manipulation Trick (LeetCode #136 — Single Number)

Important XOR properties:

```
n ^ n = 0  
n ^ 0 = n
```

These properties help find the single non-repeating number in an array where every other number appears twice.

Example:

```cpp
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int n : nums)
        ans ^= n;
    return ans;
}
```
