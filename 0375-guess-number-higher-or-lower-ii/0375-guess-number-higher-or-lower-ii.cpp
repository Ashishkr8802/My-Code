class Solution {
public:
    // int solveUsingRecursion(int start , int end) {
    //     if(start >= end) {
    //         return 0;
    //     }

    //     int ans = INT_MAX;

    //     for(int i = start ; i<=end ; i++) {
    //         ans = min(ans , i + max(solveUsingRecursion(i+1 , end) , solveUsingRecursion(start , i-1)));
    //     }

    //     return ans;
    // }


    int solveUsingMemo(int start , int end , vector<vector<int>> &dp) {
        if(start >= end) {
            return 0;
        }

        if(dp[start][end] != -1) {
            return dp[start][end];
        }

        int ans = INT_MAX;

        for(int i = start ; i<=end ; i++) {
            ans = min(ans , i + max(solveUsingMemo(i+1 , end , dp) , solveUsingMemo(start , i-1 , dp)));
        }

        dp[start][end] = ans;

        return ans;
    }



    int getMoneyAmount(int n) {
        int start = 0;
        int end = n;

        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
        // int ans = solveUsingRecursion(start , end);

        int ans = solveUsingMemo(start , end , dp);
        return ans;
    }
};