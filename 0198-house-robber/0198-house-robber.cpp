class Solution {
public:
    // int solveUsingRecursion(vector<int>& nums , int idx) {
    //     if(idx >= nums.size()) {
    //         return 0;
    //     }

    //     int include = nums[idx] + solveUsingRecursion(nums , idx+2);
    //     int exclude = 0 + solveUsingRecursion(nums , idx+1);

    //     int ans = max(include , exclude);

    //     return ans;
    // }

    int solveUsingMemo(vector<int>& nums , int idx , vector<int> &dp) {
        if(idx >= nums.size()) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int include = nums[idx] + solveUsingMemo(nums , idx+2 , dp);
        int exclude = solveUsingMemo(nums , idx+1 , dp);

        int ans = max(include , exclude);

        dp[idx] = ans;

        return ans;
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        vector<int> dp(n+1 , -1);
        // int ans = solveUsingRecursion(nums , idx);
        int ans = solveUsingMemo(nums , idx , dp);
        return ans;
    }
};