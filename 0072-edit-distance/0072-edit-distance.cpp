class Solution {
public:
    int solveUsingRecursion(string a , string b , int i , int j , vector<vector<int>>& dp) {
        if(i == a.length()) {
            return b.length() - j;
        }

        if(j == b.length()) {
            return a.length() - i;
        }

        int ans = 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(a[i] == b[j]) {
            ans = solveUsingRecursion(a , b , i+1 , j+1 , dp);
        }

        else {
            int insert = 1 + solveUsingRecursion(a , b , i , j+1 , dp);
            int replace = 1 + solveUsingRecursion(a , b , i+1 , j+1 , dp);
            int remove = 1 + solveUsingRecursion(a , b , i+1 , j , dp);

            ans = min(insert , min(replace , remove));
        }

        dp[i][j] = ans;

        return ans;
    }
    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;

        vector<vector<int>> dp(word1.length()+1 , vector<int>(word2.length()+1 , -1));

        int ans = solveUsingRecursion(word1 , word2 , i , j , dp);
        return ans;
    }
};