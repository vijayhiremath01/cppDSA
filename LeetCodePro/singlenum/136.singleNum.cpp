#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {4,1,2,1,2};
    int ans = 0 ; 
    for(int i = 0 ; i < nums.size() ; i++){
        ans ^= nums[i];
    }
    cout << "The single number is "<< ans << endl ; 
    return 0 ; 
}


// same code like leetocde 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0 ; 
        for(int i = 0 ; i < nums.size() ; i++){
            ans ^= nums[i];
        }
        return ans ; 
    }
};