class Solution {
public:
    bool solveUsingRecursion(vector<int>& nums , int index , int target , int sum) {
        if(index >= nums.size() || sum > target) {
            return false;
        }

        if(sum == target) {
            return true;
        }

        bool include = solveUsingRecursion(nums , index+1 , target , sum+nums[index]);
        bool exclude = solveUsingRecursion(nums , index+1 , target , sum);

        return include||exclude;
    }


    bool solveUsingMemo(vector<int>& nums , int index , int target , int sum ,  vector<vector<int>> &dp) {
        if(index >= nums.size() || sum > target) {
            return false;
        }

        if(sum == target) {
            return true;
        }

        if(dp[index][sum] != -1) {
            return dp[index][sum];
        }

        bool include = solveUsingMemo(nums , index+1 , target , sum+nums[index] , dp);
        bool exclude = solveUsingMemo(nums , index+1 , target , sum ,dp);

        dp[index][sum] = (include||exclude);

        return dp[index][sum];
    }


    bool canPartition(vector<int>& nums) {
        int totalsum  = 0;
        int index = 0;
        int n = nums.size();

        for(int i=0 ; i<n ; i++) {
            totalsum += nums[i];
        }

        if(totalsum %2 != 0) {
            return false;
        }
        int sum=0;

        int target = totalsum/2;

        vector<vector<int>> dp(n+1 , vector<int>(target+1 , -1));

        // bool ans = solveUsingRecursion(nums , index , target , sum);
        bool ans = solveUsingMemo(nums , index , target , sum , dp);
        return ans;
    }
};