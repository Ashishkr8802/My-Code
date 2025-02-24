class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin() , costs.end());
        int n = costs.size();
        int ans = 0;
        for(int i=0 ; i<n ; i++) {
            if(coins > 0) {
                coins -= costs[i];
                if(coins>=0){
                    ans++;
                }          
            }
        }
        return ans;
    }
};