#include <iostream> 
#include <vector>
using namespace std ;

int main(){
    vector<int> nums = {1 , 2, 3,4, 5};

 // Creating a class named as Solution 
    class Solution{
        public :  
         int isDuplicate(vector<int> &nums){
            int n = nums.size();
            for(int i = 0 ; i < n ; i++){
                for(int j = i + 1 ; j < n ; j++){
                    if(nums[i] == nums[j]){
                        return true ; 
                    }
                }
            }
            return false ;
         }
    };

    cout << "Lets check whether same number exits or not 😌 : " << Solution().isDuplicate(nums) << endl ; 

    return 0 ;  
}