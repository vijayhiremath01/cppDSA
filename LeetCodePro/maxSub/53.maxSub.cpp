#include <iostream>
#include <vector>
using namespace std ;

int main(){
vector<int> nums = {1 ,2 , 3, 4, 5 };

class Solution {
    public : 
    int maxSubArray(vector<int> nums){
        int maxSum =INT_MIN , currSum = 0 ; 
        for(int val : nums) {
            currSum += val ;
            maxSum = max(maxSum , currSum ) ;
            if(currSum < 0 ) {
                currSum = 0 ; 
            }
        }
        return maxSum;
    }
};

cout << "The maximum sum of the subarray is : " << Solution().maxSubArray(nums) << endl ;
}