class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimumPrice = INT_MAX;
        int profit = 0;

        for(int price : prices) {
            minimumPrice = min(minimumPrice , price);
            profit = max(profit , price-minimumPrice);
        }

        return profit;
    }
};