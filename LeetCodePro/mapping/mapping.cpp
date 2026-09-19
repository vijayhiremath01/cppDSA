#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Pre-computing
    map<int, int> mpp;

    for(int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    int q;
    cin >> q;

    while(q--) {
        int number;
        cin >> number;

        // Fetch the frequency
        cout << mpp[number] << endl;
    }

    return 0;
}