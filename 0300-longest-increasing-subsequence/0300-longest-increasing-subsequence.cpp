class Solution {
public:
    // int solveUsingRecursion(vector<int>& nums , int prev , int curr) {
    //     if(curr >= nums.size()) {
    //         return 0;
    //     }

    //     int include = 0;

    //     if(prev == -1 || nums[curr] > nums[prev]) {
    //         include = 1 + solveUsingRecursion(nums , curr , curr+1);
    //     }
    //     int exclude = 0 + solveUsingRecursion(nums , prev , curr+1);

    //     int ans = max(include , exclude);

    //     return ans;
    // }

    int solveUsingMemo(vector<int>& nums , int prev , int curr , vector<vector<int>>& dp) {
        if(curr >= nums.size()) {
            return 0;
        }

        if(dp[curr][prev+1] != -1) {
            return dp[curr][prev+1];
        }

        int include = 0;

        if(prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveUsingMemo(nums , curr , curr+1 , dp);
        }
        int exclude = 0 + solveUsingMemo(nums , prev , curr+1 , dp);

        dp[curr][prev+1] = max(include , exclude);


        return dp[curr][prev+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;
        // int ans = solveUsingRecursion(nums , prev , curr);
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1,-1));
        int ans = solveUsingMemo(nums , prev , curr , dp);

        return ans;
    }
};