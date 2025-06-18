class Solution {
public:
    int solveUsingRecursion(vector<int> &coins , int amount) {
        if(amount == 0) {
            return 0;
        }

        int mini = INT_MAX;

        for(int i=0 ; i<coins.size() ; i++) {
            if(amount - coins[i] >=0) {
                int recursionKaAns = solveUsingRecursion(coins , amount - coins[i]);
                if(recursionKaAns != INT_MAX) {
                    int ans = 1 + recursionKaAns;
                    mini = min(ans , mini);
                }
            }
        }

        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solveUsingRecursion(coins , amount);
        if(ans == INT_MAX) {
            return -1;
        }

        else {
            return ans;
        }
    }
};