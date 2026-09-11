#include <iostream>
#include <vector>
using namespace std;

int main() {

  vector<int> nums = {1, 2, 2, 3, 2, 1, 3, 2, 1, 3, 2, 2, 2, 3, 1, 2, 2, 2, 2};

  class Solution {
  public:
    int majorityElement(vector<int> &nums) {
      int n = nums.size();
      for (int val : nums) {
        int freq = 0;
        for (int el : nums) {
          if (el == val) {
            freq++;
          }
        }
        if (freq > n / 2) {
          return val;
        }
      }
      return -1;
    }
  };

  Solution sol;
  cout << "Majority element in an array is : " << sol.majorityElement(nums)
       << endl;
  return 0;
}