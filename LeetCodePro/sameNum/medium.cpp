#include <algorithm>
#include <iostream>
#include <vector>

using namespace std ;

int main() {
    vector<int> nums = {1 , 2, 4, 5, 8 , 6 , 4 , 3 , 2, 5 };

    class Solution {
        public : 
           bool isDuplicate(vector<int> &nums){
             int n = nums.size();
             sort(nums.begin() , nums.end());
             for(int i = 0 ; i < n - 1 ; i++){
                if(nums[i] == nums[i + 1]){
                    return true ; 
                }
             }
             return false ; 
           }  
    };

    cout << "Checking whether the list contains similar numbers or not : " << Solution().isDuplicate(nums);

    return 0 ; 
}