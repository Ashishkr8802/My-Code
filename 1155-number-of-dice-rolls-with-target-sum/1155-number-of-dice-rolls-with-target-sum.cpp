class Solution {
public:

    int solveUsingMemo(int n , int k , int target , vector<vector<int>>& dp) {
        if(n==0 && target ==0){
            return 1;
        }
        else if(n==0 || target == 0) {
            return 0;
        }

        if(dp[n][target] != -1) {
            return dp[n][target];
        }

        int ans = 0;
        int mod = 1000000007;
        for(int face=1 ; face<=k ; face++) {
            if(target-face >= 0) {
                ans = (ans + solveUsingMemo(n-1 , k , target - face , dp)) % mod;
            }
        }

        dp[n][target] = ans;
        return ans;

    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1 , vector<int>(target+1 , -1));
        int ans = solveUsingMemo(n , k , target , dp);
        return ans;
    }
};