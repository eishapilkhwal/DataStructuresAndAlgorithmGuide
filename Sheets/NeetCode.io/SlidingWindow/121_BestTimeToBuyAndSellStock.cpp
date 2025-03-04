// 121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(auto & price : prices){
            minPrice = min(minPrice, price);
            int profit = price - minPrice;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
