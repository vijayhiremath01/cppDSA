# Mapping / Hashing --- Complete Notes

> These notes are based on the uploaded handwritten notes, organized and
> expanded with clearer explanations, examples, and C++ snippets.

------------------------------------------------------------------------

## 1. What is Mapping?

A **map** stores data in the form:

``` text
Key → Value
```

Think of it like a dictionary:

``` text
"apple" → 5
"banana" → 3
"mango" → 7
```

Here:

-   `apple`, `banana`, `mango` are **keys**
-   `5`, `3`, `7` are **values**

In C++, a map is useful when we want to connect one piece of information
with another.

### Simple example

Suppose we have:

``` text
1 2 3 1 3 2 1
```

We want to know how many times every number appears.

We can store:

``` text
1 → 3
2 → 2
3 → 2
```

This is called a **frequency map**.

------------------------------------------------------------------------

# 2. `map` in C++

The basic syntax is:

``` cpp
map<KeyType, ValueType> mp;
```

For integer keys and integer values:

``` cpp
map<int, int> mp;
```

Example:

``` cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> mp;

    mp[10] = 100;
    mp[20] = 200;
    mp[30] = 300;

    cout << mp[20] << '\n';

    return 0;
}
```

Output:

``` text
200
```

The map contains:

``` text
10 → 100
20 → 200
30 → 300
```

------------------------------------------------------------------------

# 3. The Most Important Idea: `mp[key]`

This is one of the most important things to understand.

``` cpp
mp[key]
```

means:

> Access the value associated with `key`.

For example:

``` cpp
map<int, int> mp;

mp[5] = 10;

cout << mp[5];
```

Output:

``` text
10
```

------------------------------------------------------------------------

## What happens if the key does not exist?

For a normal `map<int, int>`:

``` cpp
map<int, int> mp;

cout << mp[100];
```

If `100` does not exist, `mp[100]` creates that key with the default
value:

``` text
100 → 0
```

So this is especially useful for frequency counting.

------------------------------------------------------------------------

# 4. Frequency Counting

This is one of the most common uses of mapping in DSA.

Suppose:

``` text
arr = [1, 2, 3, 1, 3, 2, 1]
```

We want:

``` text
1 → 3
2 → 2
3 → 2
```

We can simply write:

``` cpp
map<int, int> mp;

for (int x : arr) {
    mp[x]++;
}
```

Why does this work?

Initially:

``` text
mp[1] = 0
```

When we see `1`:

``` cpp
mp[1]++;
```

becomes:

``` text
1 → 1
```

When we see another `1`:

``` text
1 → 2
```

Another `1`:

``` text
1 → 3
```

So the final map contains the frequency of every number.

------------------------------------------------------------------------

# 5. Complete Frequency Example

``` cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 1, 3, 2, 1};
    int n = 7;

    map<int, int> mp;

    // Store frequency
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    // Print frequencies
    for (auto it : mp) {
        cout << it.first << " -> " << it.second << '\n';
    }

    return 0;
}
```

Output:

``` text
1 -> 3
2 -> 2
3 -> 2
```

------------------------------------------------------------------------

# 6. Precompute and Answer Queries

The uploaded notes also show an important DSA pattern:

``` text
Precompute → Answer queries quickly
```

Suppose we have:

``` text
1 2 3 1 3 2 1
```

and many queries:

``` text
How many times does 1 occur?
How many times does 3 occur?
How many times does 2 occur?
```

Instead of scanning the entire array for every question, we calculate
all frequencies once.

### Step 1: Precompute

``` cpp
map<int, int> mp;

for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
}
```

### Step 2: Answer queries

``` cpp
cout << mp[number] << '\n';
```

This avoids repeatedly traversing the entire array.

------------------------------------------------------------------------

# 7. Full Query Example

``` cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    // Read array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Precompute frequencies
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    // Queries
    int q;
    cin >> q;

    while (q--) {
        int number;
        cin >> number;

        cout << mp[number] << '\n';
    }

    return 0;
}
```

### Example input

``` text
7
1 2 3 1 3 2 1
4
1
2
3
10
```

### Output

``` text
3
2
2
0
```

For `10`, there is no occurrence, so:

``` cpp
mp[10]
```

gives `0` for this `map<int,int>`.

------------------------------------------------------------------------

# 8. Why Not Just Search the Array Every Time?

Suppose:

``` text
n = 100000
```

and we have:

``` text
q = 100000
```

queries.

If we scan the entire array for every query:

``` text
100000 × 100000
```

operations can be required.

That is approximately:

``` text
10^10
```

operations.

Instead:

1.  Build the frequency map once.
2.  Answer each query using the map.

This is the **precomputation idea** shown in the notes.

------------------------------------------------------------------------

# 9. Time Complexity of `map`

C++ `map` is generally implemented using a balanced tree.

For `N` elements:

### Insert

``` cpp
mp[key] = value;
```

Time:

``` text
O(log N)
```

### Search

``` cpp
mp.find(key);
```

Time:

``` text
O(log N)
```

### Access

``` cpp
mp[key]
```

Time:

``` text
O(log N)
```

So the notes' important point is:

``` text
map → O(log N)
```

for storing/finding a key.

------------------------------------------------------------------------

# 10. `unordered_map`

C++ also provides:

``` cpp
unordered_map
```

It works using hashing.

Syntax:

``` cpp
unordered_map<int, int> mp;
```

Example:

``` cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<int, int> mp;

    mp[10] = 100;
    mp[20] = 200;

    cout << mp[10];

    return 0;
}
```

Output:

``` text
100
```

------------------------------------------------------------------------

# 11. `map` vs `unordered_map`

The main difference:

  Feature             `map`                `unordered_map`
  ------------------- -------------------- -----------------------------
  Main idea           Tree-based           Hash-based
  Average lookup      `O(log N)`           `O(1)` average
  Ordering            Sorted by key        No sorted order
  Worst-case lookup   `O(log N)`           `O(N)`
  Useful when         Sorted keys matter   Fast average lookup matters

### Example

For:

``` cpp
map<int, int> mp;
```

keys are maintained in sorted order.

If we insert:

``` text
30
10
20
```

iteration gives:

``` text
10
20
30
```

With:

``` cpp
unordered_map<int, int>
```

you should **not depend on any sorted order**.

------------------------------------------------------------------------

# 12. Why Is `unordered_map` Usually `O(1)`?

`unordered_map` uses a **hash function**.

Imagine we have:

``` text
10
20
30
40
```

A hash function decides where each key should be stored.

A simplified example is:

``` text
index = key % 10
```

So:

``` text
10 % 10 = 0
20 % 10 = 0
30 % 10 = 0
```

Multiple keys can therefore go to the same location.

This is called a:

## Collision

------------------------------------------------------------------------

# 13. Collision

A collision happens when two different keys are mapped to the same
location.

For example, with:

``` text
index = key % 10
```

we get:

``` text
8  → 8
18 → 8
28 → 8
38 → 8
48 → 8
```

All of these produce the same index:

``` text
8
```

This is the type of collision example illustrated in the uploaded notes.

A hash table needs a way to handle such collisions.

------------------------------------------------------------------------

# 14. Collision Handling --- Basic Idea

One common idea is to keep multiple elements in the same bucket.

Conceptually:

``` text
bucket 8:
    8
    18
    28
    38
    48
```

Then, when searching for a key, the hash tells us which bucket to
inspect.

If a bucket contains many elements, searching becomes slower.

In an extreme case, many keys can end up together, causing the operation
to approach:

``` text
O(N)
```

This explains the worst-case complexity of `unordered_map`.

------------------------------------------------------------------------

# 15. `unordered_map` Complexity

For `unordered_map`:

### Average case

``` text
Insert   → O(1)
Search   → O(1)
Delete   → O(1)
```

### Worst case

``` text
Insert   → O(N)
Search   → O(N)
Delete   → O(N)
```

The worst case can happen when collisions become excessive.

So remember:

``` text
unordered_map → O(1) average
unordered_map → O(N) worst case
```

------------------------------------------------------------------------

# 16. Frequency Counting with `unordered_map`

For frequency problems, this is extremely common:

``` cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 1, 3, 2, 1};

    unordered_map<int, int> freq;

    for (int x : arr) {
        freq[x]++;
    }

    for (auto it : freq) {
        cout << it.first << " -> " << it.second << '\n';
    }

    return 0;
}
```

Possible output:

``` text
3 -> 2
2 -> 2
1 -> 3
```

The order is not guaranteed.

------------------------------------------------------------------------

# 17. `map` Is Sorted

If you need sorted keys:

``` cpp
map<int, int> mp;

mp[30]++;
mp[10]++;
mp[20]++;

for (auto it : mp) {
    cout << it.first << '\n';
}
```

Output:

``` text
10
20
30
```

This is one reason to choose `map`.

------------------------------------------------------------------------

# 18. `unordered_map` Does Not Guarantee Sorting

``` cpp
unordered_map<int, int> mp;

mp[30]++;
mp[10]++;
mp[20]++;

for (auto it : mp) {
    cout << it.first << '\n';
}
```

Do **not** expect:

``` text
10
20
30
```

The order is unspecified.

If your algorithm needs sorted keys, use `map` or another appropriate
sorted structure.

------------------------------------------------------------------------

# 19. Checking Whether a Key Exists

Use:

``` cpp
mp.find(key)
```

Example:

``` cpp
map<int, int> mp;

mp[10] = 50;

if (mp.find(10) != mp.end()) {
    cout << "Found";
}
```

Output:

``` text
Found
```

For a key that does not exist:

``` cpp
if (mp.find(100) == mp.end()) {
    cout << "Not found";
}
```

------------------------------------------------------------------------

# 20. Important Difference: `mp[key]` vs `find()`

This is an important interview/DSA detail.

### `mp[key]`

``` cpp
mp[100]
```

can create the key if it does not already exist.

### `find()`

``` cpp
mp.find(100)
```

checks whether the key exists without inserting it.

So if you only want to check existence:

``` cpp
if (mp.find(100) != mp.end()) {
    // exists
}
```

is safer than using:

``` cpp
if (mp[100]) {
    // ...
}
```

------------------------------------------------------------------------

# 21. Updating a Value

Example:

``` cpp
map<string, int> marks;

marks["Rahul"] = 80;

marks["Rahul"] = 90;
```

Now:

``` text
Rahul → 90
```

The second assignment replaces the previous value.

------------------------------------------------------------------------

# 22. Multiple Values for the Same Key

A normal `map` stores one value for each key.

Example:

``` cpp
map<int, string> mp;

mp[1] = "Apple";
mp[1] = "Mango";
```

The final value is:

``` text
1 → Mango
```

If you need multiple values for the same key, there are other structures
such as:

``` cpp
multimap
```

or:

``` cpp
map<int, vector<string>>
```

Example:

``` cpp
map<int, vector<string>> students;

students[1].push_back("A");
students[1].push_back("B");
students[1].push_back("C");
```

Now:

``` text
1 → [A, B, C]
```

------------------------------------------------------------------------

# 23. Common DSA Pattern

Whenever you see a problem asking something like:

-   How many times does each number occur?
-   How many times does this number appear?
-   Have we seen this value before?
-   Find duplicates.
-   Count characters.
-   Count words.
-   Store information against an ID.

Think:

``` text
Can a map/hash map solve this?
```

------------------------------------------------------------------------

# 24. Example: Count Characters

String:

``` text
banana
```

We can count each character:

``` cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "banana";

    map<char, int> freq;

    for (char ch : s) {
        freq[ch]++;
    }

    for (auto it : freq) {
        cout << it.first << " -> " << it.second << '\n';
    }

    return 0;
}
```

Output:

``` text
a -> 3
b -> 1
n -> 2
```

------------------------------------------------------------------------

# 25. Example: Find Duplicate Values

``` cpp
vector<int> arr = {1, 2, 3, 2, 4, 1};

unordered_map<int, int> freq;

for (int x : arr) {
    freq[x]++;
}

for (auto it : freq) {
    if (it.second > 1) {
        cout << it.first << " is duplicated\n";
    }
}
```

Output:

``` text
1 is duplicated
2 is duplicated
```

------------------------------------------------------------------------

# 26. Example: First Number That Appears Twice

``` cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {5, 2, 7, 2, 9};

    unordered_map<int, int> seen;

    for (int x : arr) {
        if (seen[x] > 0) {
            cout << "First duplicate: " << x << '\n';
            break;
        }

        seen[x]++;
    }

    return 0;
}
```

Output:

``` text
First duplicate: 2
```

The map remembers what we have already seen.

------------------------------------------------------------------------

# 27. A Simple Mental Model

Think of a map as a notebook.

You write:

``` text
Key      Value
----------------
101      50
102      80
103      70
```

If you ask:

``` text
What is the value for key 102?
```

the map gives:

``` text
80
```

For a frequency map:

``` text
Number   Count
--------------
1        3
2        2
3        2
```

The value is simply the number of times we have seen the key.

------------------------------------------------------------------------

# 28. The Most Important Code to Remember

### `map`

``` cpp
map<int, int> mp;

for (int x : arr) {
    mp[x]++;
}
```

### `unordered_map`

``` cpp
unordered_map<int, int> mp;

for (int x : arr) {
    mp[x]++;
}
```

### Query

``` cpp
cout << mp[x];
```

### Check existence

``` cpp
if (mp.find(x) != mp.end()) {
    // x exists
}
```

------------------------------------------------------------------------

# 29. Quick Complexity Sheet

  Operation                  `map`   `unordered_map`
  ------------------- ------------ -----------------
  Insert                `O(log N)`    `O(1)` average
  Search                `O(log N)`    `O(1)` average
  Delete                `O(log N)`    `O(1)` average
  Worst-case search     `O(log N)`            `O(N)`
  Sorted keys                  Yes                No

------------------------------------------------------------------------

# 30. How to Choose

Use:

``` cpp
map
```

when:

-   You need keys in sorted order.
-   You want predictable `O(log N)` operations.
-   You need ordered traversal.

Use:

``` cpp
unordered_map
```

when:

-   You mainly need fast average lookup.
-   Key ordering does not matter.
-   You are doing frequency counting or existence checking.

For a basic frequency-counting problem, both can work.

------------------------------------------------------------------------

# 31. Interview/DSA Checklist

Before solving a problem, ask:

``` text
1. Do I need to store key → value?
        ↓
      Yes
        ↓
2. Do I need sorted keys?
        ↓
   Yes → map
        ↓
   No
        ↓
3. Do I mainly need fast average lookup?
        ↓
   Yes → unordered_map
```

For frequency:

``` cpp
unordered_map<int, int> freq;

for (int x : arr) {
    freq[x]++;
}
```

For sorted frequency:

``` cpp
map<int, int> freq;

for (int x : arr) {
    freq[x]++;
}
```

------------------------------------------------------------------------

# 32. Final Takeaway

The core idea from the notes is:

``` text
Mapping = Key → Value
```

A very common DSA use is:

``` text
Array
  ↓
Frequency Map
  ↓
Answer queries quickly
```

Example:

``` text
Array:
1 2 3 1 3 2 1

Map:
1 → 3
2 → 2
3 → 2
```

Then a query such as:

``` text
"How many times does 3 occur?"
```

can be answered using:

``` cpp
cout << mp[3];
```

Remember these three things first:

``` text
map              → sorted keys, O(log N)
unordered_map    → hashing, O(1) average
mp[x]++          → extremely useful for frequency counting
```

And remember the hashing idea:

``` text
Key
 ↓
Hash function
 ↓
Bucket/index
```

If multiple keys go to the same bucket:

``` text
Collision
```

and excessive collisions can make `unordered_map` operations approach:

``` text
O(N)
```

------------------------------------------------------------------------

## One-page Revision

``` cpp
// Sorted map
map<int, int> mp;

// Hash map
unordered_map<int, int> mp;

// Frequency
for (int x : arr) {
    mp[x]++;
}

// Get frequency
cout << mp[x];

// Check existence
if (mp.find(x) != mp.end()) {
    // exists
}
```

### Complexity

``` text
map:
    insert/search → O(log N)

unordered_map:
    average       → O(1)
    worst case    → O(N)
```

### Core pattern

``` text
Input
  ↓
Precompute using map
  ↓
Answer many queries
```
