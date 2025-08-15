class Solution {
public:
    // int solveUsingRecursion(string s , string t , int i , int j) {
    //     if(j == t.size()) {
    //         return 1;
    //     }
    //     if(i == s.size()) {
    //         return 0;
    //     }

    //     int ans = 0;

    //     if(s[i] == t[j]) {
    //         ans += solveUsingRecursion(s,t,i+1,j+1);
    //     }
    //     ans += solveUsingRecursion(s,t,i+1,j);

    //     return ans;
    // }


    int solveUsingMemo(string s , string t , int i , int j , vector<vector<int>> &dp) {
        if(j == t.size()) {
            return 1;
        }
        if(i == s.size()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;

        if(s[i] == t[j]) {
            ans += solveUsingMemo(s,t,i+1,j+1,dp);
        }
        ans += solveUsingMemo(s,t,i+1,j,dp);

        dp[i][j] = ans;

        return ans;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1 , vector<int>(t.size()+1 , -1));
        // int ans = solveUsingRecursion(s,t,0,0);
        int ans = solveUsingMemo(s,t,0,0,dp);
        return ans;
    }
};