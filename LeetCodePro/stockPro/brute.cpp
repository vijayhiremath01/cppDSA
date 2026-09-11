// Best time for Buy and Sell 

// Brute Force code 

#include <vector>
#include <iostream>
using namespace std ;

int main() {
    vector<int> prices = {1, 3, 4, 8, 0};
    class Solution {
    public:
        int maxProfit(vector<int>& prices) {
                 int maxProfit = 0 , n = prices.size();
                 for(int i = 0 ; i < n - 1 ; i++){
                    for( int j = i + 1 ; j < n ; j++){
                        if(prices[j] - prices[i] > maxProfit){
                            maxProfit = prices[j] - prices[i];
                        }
                    }
                 }
                 return maxProfit ; 
              }
    };

    cout << "The Maximum will be : " << Solution().maxProfit(prices) << endl;

}