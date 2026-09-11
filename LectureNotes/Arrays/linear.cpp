#include <iostream>
using namespace std;

// Linear Search Algorithm
int main() {
    int n;
    int target;

    cout << "Enter the size of the array: " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " numbers to store in the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target value to search in the array: " << endl;
    cin >> target;

    // Linear Search Logic
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << "Target value found at index " << i << "!" << endl;
            return 0; // Exit program after finding the value
        }
    }

    cout << "Target value not found in the array!" << endl;
    return 0;
}
