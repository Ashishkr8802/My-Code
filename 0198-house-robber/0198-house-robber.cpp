class Solution {
public:
    int solveUsingRecursion(vector<int>& nums , int index) {
        //base case
        if(index >= nums.size()) {
            return 0;
        }

        //include
        int include = nums[index] + solveUsingRecursion(nums , index+2);
        //exclude
        int exclude = 0 + solveUsingRecursion(nums , index+1);

        return max(include , exclude);
    }

    int solveUsingMemo(vector<int> &nums , int index , vector<int> &dp) {
        if(index >= nums.size()) {
            return 0;
        }

        if(dp[index] != -1) {
            return dp[index];
        }

        int include = nums[index] + solveUsingMemo(nums , index+2 ,dp);
        int exclude = 0 + solveUsingMemo(nums , index+1 , dp);

        dp[index] = max(include , exclude);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int index = 0;
        // int ans = solveUsingRecursion(nums , index);
        int n = nums.size();
        vector<int> dp(n+1 , -1);
        int ans = solveUsingMemo(nums , index , dp);
        return ans;
    }
};