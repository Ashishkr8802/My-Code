class Solution {
public:

    int solveUsingMemo(int i , int j , string &text1 , string &text2 ,  vector<vector<int>> &dp) {
        if(i >= text1.length() || j >= text2.length()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans;
        if(text1[i] == text2[j]) {
            ans = 1 + solveUsingMemo(i+1 , j+1 , text1 , text2 , dp);
        }
        else {
            ans = max(solveUsingMemo(i+1 , j , text1 , text2 , dp) , solveUsingMemo(i , j+1 , text1 , text2 , dp));
        }

        dp[i][j] = ans;

        return ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() , vector<int> (text2.length() , -1));

        int ans = solveUsingMemo(0, 0 , text1 , text2 , dp);

        return ans;
    }
};