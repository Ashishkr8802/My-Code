class Solution {
public:
    // int solveUsingRecursion(vector<int> &cost , int idx) {
    //     if(idx >= cost.size()) {
    //         return 0;
    //     }

    //     int oneStep = cost[idx] + solveUsingRecursion(cost , idx+1);
    //     int twoStep = cost[idx] + solveUsingRecursion(cost , idx+2);

    //     int ans = min(oneStep , twoStep);

    //     return ans;
    // }


    int solveUsingMemo(vector<int> &cost , int idx , vector<int>& dp) {
        if(idx >= cost.size()) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int oneStep = cost[idx] + solveUsingMemo(cost , idx+1 , dp);
        int twoStep = cost[idx] + solveUsingMemo(cost , idx+2 , dp);

        int ans = min(oneStep , twoStep);
        dp[idx] = ans;
        return ans;
    }


    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1 , -1);
        int ans = min(solveUsingMemo(cost , 0 ,dp) , solveUsingMemo(cost , 1, dp));
        return ans;
    }
};