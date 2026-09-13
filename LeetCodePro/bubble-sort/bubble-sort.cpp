#include <iostream>
#include <vector>
using namespace std ; 

class BubbleSort {
public:
    void bubbleSort(vector<int>& arr){
        int n = arr.size();
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = 0 ; j <= i - 1 ; j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]) ;
                }
            } 
        }
        cout << "After Using Bubble Sort:\n";
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }
};

int main(){

    int n ; 
    cin >> n ;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    BubbleSort bs ;
    bs.bubbleSort(arr);

    return 0 ; 
}