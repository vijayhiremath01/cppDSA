#include <iostream>
using namespace std ;

int main(){
    vector<int> arr = {2,5,8,1,4,6};

    class Solution {
        public : 
             int peakIndexInMountainArray(vector<int> &arr){
                int st = 1 , end = arr.size() - 2 ;
                while(st <= end) {
                    int mid = st + (end - st) / 2;
                    if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid - 1]){
                        return mid ;
                    }else if (arr[mid] > arr[mid - 1 ]){
                        st = mid + 1 ;
                    } else {
                        end = mid - 1 ; 
                    }
                }
                return -1 ; 
             }
    };

    cout << Solution().peakIndexInMountainArray( arr) << endl ; 
}