# 📘 Book Allocation Problem — Detailed DSA Explanation

## 🧩 Problem Statement

You are given **N books**, where the **i-th book has A[i] number of pages**. There are **M students**, and your task is to allocate these books among students so that:

1. Each book is assigned to exactly **one student**.
2. Each student gets **at least one book**.
3. Books assigned to a student must be **contiguous** (in order).
4. The goal is to **minimize the maximum number of pages** assigned to any student.

If allocation is not possible (e.g., more students than books), return **-1**.

---

## 💡 Key Intuition

Think of distributing books like dividing workloads — you want to balance the number of pages so that no single student gets too many while ensuring the order of books is maintained.

This problem is a **Binary Search on Answer** type problem.

We guess a value (maximum pages allowed per student) and check if it's **possible** to allocate within that limit.

---

## ⚙️ Step-by-Step Approach

### Step 1: Define Search Space

* **Minimum pages (low)** = 0
* **Maximum pages (high)** = sum of all pages

### Step 2: Feasibility Function — `isValid()`

Checks if it’s possible to allocate books such that **no student reads more than `maxAllowedPages`**.

Algorithm:

* Keep a running sum of pages per student.
* If adding a book exceeds `maxAllowedPages`, assign the next student.
* If students required exceed M → not possible.

### Step 3: Binary Search Logic

Perform binary search between `low` and `high`. For each mid:

* If `isValid()` is true → try smaller `mid` (left part)
* Else → go right to increase the allowed pages.

---

## 🧮 Time & Space Complexity

| Complexity | Description              |
| ---------- | ------------------------ |
| **Time**   | O(N × log(sum of pages)) |
| **Space**  | O(1)                     |

---

## 🧠 Example

### Input

```
Books = [12, 34, 67, 90]
Students = 2
```

### Output

```
113
```

### Explanation

* Student 1 → [12, 34, 67] = 113 pages
* Student 2 → [90] = 90 pages
* Minimum possible maximum = **113**

---

## 🧾 Code Implementation (C++)

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedPages) {
    int studentCount = 1, pageSum = 0;
    for (int i = 0; i < n; i++) {
        if (m > n) return false;
        if (pageSum + arr[i] <= maxAllowedPages) {
            pageSum += arr[i];
        } else {
            studentCount++;
            if (studentCount > m || arr[i] > maxAllowedPages) {
                return false;
            } else {
                pageSum = arr[i];
            }
        }
    }
    return true;
}

int allocateBooks(vector<int> &arr, int n, int m) {
    if (m > n) return -1;

    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    int ans = -1;
    int st = 0, end = sum;

    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (isValid(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1; // Try smaller max value
        } else {
            st = mid + 1; // Increase allowed pages
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter the number of books: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the number of students: ";
    cin >> m;
    cout << "Enter the number of pages in each book: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "The minimum number of pages allocated to a student is "
         << allocateBooks(arr, n, m) << endl;
    return 0;
}
```

---

## 🧩 Real-World Usage

* **Task Distribution:** Assigning projects to teams so that no one is overloaded.
* **Server Load Balancing:** Dividing incoming requests among servers efficiently.
* **Video Streaming:** Allocating file chunks to servers ensuring balanced data load.

---

## ❗ Important to Note

1. **Books must be contiguous.**
2. If `M > N`, return `-1`.
3. The function `isValid()` is the **core** — ensures logical allocation.
4. **Binary search** helps optimize for large datasets.
5. Always handle edge cases — e.g., all books with the same pages.

---

## 🎯 Common Interview Questions

1. Why do we use **binary search** here and not linear search?
2. What happens if books are not contiguous — how would you modify the approach?
3. Can this logic be applied to **Painters Partition Problem** or **Aggressive Cows**?
4. How would you handle **fractional pages** (floating-point data)?
5. How would you modify the code if books could be distributed **non-contiguously**?

---

## 🧠 Concept Links

* **Binary Search on Answer** (Core DSA concept)
* **Partition Problems** — Painters Partition, Split Array Largest Sum

---

### ✅ Summary

> The Book Allocation Problem teaches you how to optimize allocation and balancing problems using **binary search on the answer** — a crucial DSA pattern used in many interview-level challenges.
