#include <iostream>
#include <vector>
using namespace std ;

// vector<int> pairSum(vector<int> nums , int target){
//    vector<int> ans ;
//    int n = nums.size();

//    for(int i = 0 ; i < n ; i++){
//     for(int j = i + 1 ; j < n ; j++){
//         if(nums[i] + nums[j] == target ){
//             ans.push_back(i);
//             ans.push_back(j);
//             return ans ; 
//         }
//     }
// }
//    return ans ; 
// }


// int main() {
//     vector<int> nums ;
//     int lastNum  ;
//     cout << "Enter the last number for the array : " << endl ;
//     cin >> lastNum ;
//     for(int i = 1 ; i <= lastNum ; i++){
//         nums.push_back(i);
//     }
//     int target ;
//     cout << "Enter the target value : " << endl ;
//     cin >> target ;
//     vector<int> ans = pairSum(nums , target );
//     cout << "The indices of the two numbers are : " << ans[0] << " and " << ans[1] << endl ;
//     return 0 ; 
// }



// by looking at time complexity 

vector<int> pairSum(vector<int> nums , int target){
    vector<int> ans ;
    int n = nums.size();
    
    int i = 0 , j = n - 1 ; 
    while(i < j){
        int pairSum = nums[i] + nums[j];
        if(pairSum > target){
            j-- ; 
        }else if(pairSum < target){
            i++ ; 
        }else {
            ans.push_back(i);
            ans.push_back(j);
            return ans ;  
        }
    }

    return ans ; 
 }

int main() {
        vector<int> nums ;
        int lastNum  ;
        cout << "Enter the last number for the array : " << endl ;
        cin >> lastNum ;
        for(int i = 0 ; i < lastNum ; i++){
            nums.push_back(i);
        }
        int target ;
        cout << "Enter the target value : " << endl ;
        cin >> target ;
        vector<int> ans = pairSum(nums , target );
        cout << "The indices of the two numbers are : " << ans[0] << " and " << ans[1] << endl ;
        return 0 ; 
    }