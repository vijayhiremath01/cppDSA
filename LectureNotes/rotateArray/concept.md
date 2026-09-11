# Rotated Sorted Array - Notes

## 🔹 What is a Rotated Sorted Array?

A **sorted array** is one where all elements are arranged in increasing (or sometimes decreasing) order.

Example:

```
Sorted Array: [1, 3, 4, 5, 6]
```

If we rotate this array (move some elements from the beginning to the end or vice versa), we get a **rotated sorted array**.

Example:

```
Rotated Sorted Array: [4, 5, 6, 1, 3]
```

> Note: In your example `[6, 5, 4, 1, 3]`, it’s not a valid rotated sorted array because the order is not preserved — elements must remain sorted within their respective halves.

A rotated sorted array is essentially a sorted array that’s been rotated around a **pivot point**.

---

## 🔹 Why Normal Binary Search Doesn’t Work

In a rotated sorted array, the order is partially disrupted due to rotation. Hence, we can’t apply normal binary search directly — we first need to identify which part (left or right half) of the array is sorted.

---

## 🔹 Approach to Search Target in Rotated Sorted Array

1. **Find the middle element (mid)**
2. **Check if the target equals arr[mid]** → If yes, return `mid`.
3. **Determine which half is sorted**:

   * If `arr[start] <= arr[mid]`: Left half is sorted.
   * Else: Right half is sorted.
4. **Decide where to search next**:

   * If left half is sorted and target lies in that range → search left.
   * Else → search right.

---

## 🔹 Binary Search Logic for Rotated Array

```cpp
int search(vector<int>& arr, int target) {
    int st = 0, end = arr.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (arr[mid] == target)
            return mid;

        // Check if left half is sorted
        if (arr[st] <= arr[mid]) {
            if (arr[st] <= target && target < arr[mid])
                end = mid - 1; // Search in left half
            else
                st = mid + 1;  // Search in right half
        }
        // Else right half is sorted
        else {
            if (arr[mid] < target && target <= arr[end])
                st = mid + 1;  // Search in right half
            else
                end = mid - 1; // Search in left half
        }
    }

    return -1; // Target not found
}
```

---

## 🔹 Example Walkthrough

**Input:**

```
arr = [4, 5, 6, 7, 0, 1, 2]
target = 0
```

**Step 1:** mid = (0 + 6) / 2 = 3 → arr[mid] = 7

* Left half [4, 5, 6, 7] is sorted.
* Target (0) is not in range [4, 7] → search right.

**Step 2:** New range [4..6]

* mid = (4 + 6) / 2 = 5 → arr[mid] = 1
* Left half [0, 1, 2] is sorted.
* Target (0) is in range [0, 1] → move left.

**Step 3:** mid = (4 + 4) / 2 = 4 → arr[mid] = 0 ✅ Found.

**Output:** index = 4

---

## 🔹 Time and Space Complexity

* **Time Complexity:** O(log n)
* **Space Complexity:** O(1)

---

## 🔹 Summary

| Step | Condition                       | Action           |
| ---- | ------------------------------- | ---------------- |
| 1    | arr[mid] == target              | return mid       |
| 2    | arr[start] <= arr[mid]          | Left half sorted |
| 3    | arr[start] <= target < arr[mid] | Search left      |
| 4    | arr[mid] < target <= arr[end]   | Search right     |

---

✅ **Key Takeaway:** Identify the sorted half first, then apply binary search only within that half.
