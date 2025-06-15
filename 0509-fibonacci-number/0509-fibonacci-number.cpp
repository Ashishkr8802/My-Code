class Solution {
public:
    int solveUsingTabulation(int n , vector<int> &dp) {
        dp[0] = 0;
        if(n == 0) {
            return dp[0];
        }
        dp[1] = 1;

        for(int i=2 ; i<=n ; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1 , -1);
        int ans = solveUsingTabulation(n , dp);
        return ans;
    }
};