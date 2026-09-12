#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    /*
     * Precompute the frequency of each lowercase English character.
     *
     * hash[0] -> frequency of 'a'
     * hash[1] -> frequency of 'b'
     * ...
     * hash[25] -> frequency of 'z'
     *
     * The expression (s[i] - 'a') converts a character into
     * a zero-based index:
     *
     * 'a' - 'a' = 0
     * 'b' - 'a' = 1
     * ...
     * 'z' - 'a' = 25
     */
    int hash[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++;
    }

    /*
     * Process character-frequency queries.
     *
     * Instead of traversing the string for every query,
     * we directly retrieve the precomputed frequency from
     * the hash array.
     */
    int queries;
    cin >> queries;

    while (queries--) {
        char c;
        cin >> c;

        // Retrieve the precomputed frequency of the character.
        cout << hash[c - 'a'] << endl;
    }

    /*
     * Time Complexity:
     * - Precomputation: O(N), where N is the length of the string.
     * - Each query: O(1).
     * - Total: O(N + Q), where Q is the number of queries.
     *
     * Space Complexity:
     * - O(26) = O(1), since the hash array has a fixed size.
     */

    return 0;
}



// for Upper case and lower both we can use hash size upto 256 and dont have to do s[i] - 'a' we can directly use s[i] as index for hash array and for answer also we can use hash[s[i]] to get the frequency of that character not the c -'a' . 