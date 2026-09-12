#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int>& arr, int n){

    for(int i = 0; i < n - 1; i++){

        int min = i;

        for(int j = i + 1; j < n; j++){

            if(arr[j] < arr[min]){
                min = j;
            }
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    cout << "After selection sort: " << "\n";

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << "\n";
}

int main(){

    int n;

    cout << "Enter the size of the array: " << endl;
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: " << endl;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    selection_sort(arr, n);

    return 0;
}