class Solution {
public:
    // int solveUsingRecursion(string a , string b , int i , int j) {
    //     if(i >= a.length() || j >= b.length()) {
    //         return 0;
    //     }

    //     int ans = 0;
    //     if(a[i] == b[j]) {
    //         ans = 1 + solveUsingRecursion(a , b , i+1 , j+1);
    //     }

    //     else {
    //         ans = 0 + max(solveUsingRecursion(a,b,i,j+1) , solveUsingRecursion(a,b,i+1,j));
    //     }

    //     return ans;
    // }

    int solveUsingMemo(string a , string b , int i , int j , vector<vector<int>>& dp) {
        if(i >= a.length() || j >= b.length()) {
            return 0;
        }

        int ans = 0;

        if(dp[i][j] != -1) {
            return dp[i][j];
        }


        if(a[i] == b[j]) {
            ans = 1 + solveUsingMemo(a , b , i+1 , j+1 , dp);
        }

        else {
            ans = 0 + max(solveUsingMemo(a,b,i,j+1,dp) , solveUsingMemo(a,b,i+1,j,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;

        // int ans = solveUsingRecursion(text1 , text2 , i , j);

        vector<vector<int>> dp(text1.length()+1 , vector<int>(text2.length()+1 , -1));

        int ans = solveUsingMemo(text1 , text2 , i , j , dp);
        return ans;
    }
};