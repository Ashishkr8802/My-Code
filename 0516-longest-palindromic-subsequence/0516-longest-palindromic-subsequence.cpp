class Solution {
public:
    int solveUsingMemo(string& s , string& a , int i ,int j , vector<vector<int>>& dp) {
        if(i >= s.length() || j >= a.length()) {
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = 0;
        if(s[i] == a[j]) {
            ans = 1 + solveUsingMemo(s,a,i+1,j+1,dp);
        }
        else {
            ans = 0 + max(solveUsingMemo(s,a,i+1,j,dp) , solveUsingMemo(s,a,i,j+1,dp));
        }
        dp[i][j] = ans;
        return ans;
    }
    int longestPalindromeSubseq(string s) {
        string a = s;
        int i=0;
        int j=0;
        reverse(a.begin() , a.end());

        vector<vector<int>> dp(s.length()+1 , vector<int>(a.length()+1 , -1));

        int ans = solveUsingMemo(s,a, i , j ,dp);
        return ans;
    }
};