class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(auto i : nums) {
            sum += i;
        }

        if(sum % 2 != 0) {
            return false;
        }

        int targetSum = sum/2;
        
        vector<bool> dp(targetSum+1 , false);
        dp[0] = true;

        for(int num : nums) {
            for(int sum = targetSum ; sum>=num ; sum--) {
                dp[sum] = dp[sum] || dp[sum - num];
                if(dp[targetSum]) {
                    return true;
                }
            }
        }
        return dp[targetSum];
    }
};