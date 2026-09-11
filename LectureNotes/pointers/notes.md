# C++ Pointers Notes (Improved with Examples)

### 🧠 What are Pointers?

Pointers are **special variables** that store the **address of other variables** in memory.

Every variable in C++ is stored somewhere in memory, and that location has an **address** (usually represented in **hexadecimal** form).

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    cout << "Address of a: " << &a << endl;  // prints the address of variable a
    return 0;
}
```

---

### 🔹 Declaring a Pointer

Syntax:

```cpp
int* ptr = &a;  // pointer to int storing address of a
```

Here,

* `int*` → declares a pointer to an integer.
* `&a` → gives the address of variable `a`.

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* ptr = &a;  // pointer holds address of a

    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Pointer ptr stores: " << ptr << endl;
    return 0;
}
```

---

### 🔹 Dereference Operator (`*`)

The dereference operator `*` is used to **access the value stored at a given address**.

Example:

```cpp
int a = 10;
int* ptr = &a;
cout << *ptr << endl;  // prints value of a (10)
```

This is equivalent to:

```cpp
cout << *(&a) << endl;
```

---

### 🔹 Null Pointer

A **null pointer** does not point to any memory location.

Example:

```cpp
int* ptr = nullptr;  // pointer initialized with null
if (ptr == nullptr)
    cout << "Pointer is null" << endl;
```

---

### 🔹 Pass by Reference using Pointers

Pointers allow you to modify variables outside the function by passing their address.

Example:

```cpp
#include <iostream>
using namespace std;

void increment(int* ptr) {
    (*ptr)++;  // dereference and increment value
}

int main() {
    int num = 5;
    increment(&num);  // pass address of num
    cout << num;  // Output: 6
}
```

---

### 🔹 Pointers and Arrays

An array name acts like a pointer that points to the **first element** of the array.

Example:

```cpp
int arr[] = {1, 2, 3, 4, 5};
cout << arr << endl;       // prints address of arr[0]
cout << *arr << endl;      // prints value of arr[0] → 1
cout << *(arr + 1) << endl; // prints value of arr[1] → 2
```

> Note: `arr` is a constant pointer — you cannot make `arr` point somewhere else.

---

### 🔹 Pointer Arithmetic

You can perform arithmetic operations like increment (`++`) or decrement (`--`) on pointers.

Example:

```cpp
int arr[] = {10, 20, 30};
int* ptr = arr;

cout << ptr << endl;     // address of arr[0]
ptr++;
cout << ptr << endl;     // address of arr[1]
cout << *ptr << endl;    // value at arr[1] → 20
```

---

### 🔹 Pointer Comparison & Subtraction

You can **subtract** or **compare** two pointers **only if they point to elements of the same array**.

Example:

```cpp
int arr[] = {10, 20, 30, 40};
int* p1 = &arr[0];
int* p2 = &arr[3];

cout << (p2 - p1) << endl;  // Output: 3 (distance between pointers)
cout << (p1 < p2) << endl;  // Output: 1 (true)
```

---

### ✅ Summary

| Concept             | Description                        | Example                         |
| ------------------- | ---------------------------------- | ------------------------------- |
| `&`                 | Address-of operator                | `&a` → gives address of `a`     |
| `*`                 | Dereference operator               | `*ptr` → gives value at pointer |
| Null pointer        | Pointer pointing to nothing        | `int* ptr = nullptr;`           |
| Pass by reference   | Modify original value              | `increment(&x);`                |
| Array as pointer    | `arr` points to `arr[0]`           | `*(arr+1)` → `arr[1]`           |
| Pointer arithmetic  | Increment/decrement pointer        | `ptr++`                         |
| Pointer subtraction | Find distance between two pointers | `p2 - p1`                       |

---

💡 **Key Takeaway:** Pointers are one of the most powerful features in C++ that enable direct memory manipulation, dynamic memory allocation, and efficient function parameter passing.
