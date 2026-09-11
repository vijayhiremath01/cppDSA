// Good Code for better time complexity 

#include <iostream>
#include <vector>
using namespace std ;

int main() {
    vector<int> prices = {2 , 5, 7, 2, 4 , 8, 9 };
    class Solution {
        public : 
            int maxProfit(vector<int> &prices){
                int n = prices.size();
                int buyAtPrice = INT_MAX ;
                int maxProfit = 0 ; 
                for(int i = 0 ; i < n ; i++){
                    buyAtPrice = min(buyAtPrice , prices[i]);
                    maxProfit = max(maxProfit , prices[i] - buyAtPrice);
                }
                return maxProfit ; 
            }
    };

    cout << "The maximum profit will be : " << Solution().maxProfit(prices);
}