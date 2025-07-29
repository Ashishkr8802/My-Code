class Solution {
public:
    bool check(vector<int>& curr, vector<int>& prev) {
        if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2]) {
            return true;
        }
        else {
            return false;
        }
    }

     int solveUsingMemo(vector<vector<int>>& cuboids , int curr , int prev , vector<vector<int>> &dp) {
        if(curr >= cuboids.size()) {
            return 0;
        }

        if(dp[curr][prev+1] != -1) {
            return dp[curr][prev+1];
        }

        int include = 0;
        if(prev == -1 || check( cuboids[curr] , cuboids[prev] )) {
             int heightToAdd = cuboids[curr][2];
            include = heightToAdd + solveUsingMemo(cuboids , curr+1 , curr ,dp);
        }
        int exclude = 0 + solveUsingMemo(cuboids , curr+1 , prev , dp);

        dp[curr][prev+1] = max(include,exclude);

        return dp[curr][prev+1];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid: cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());

        int curr = 0;
        int prev = -1;
        int n = cuboids.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));

        int ans = solveUsingMemo(cuboids , curr , prev , dp);
        return ans;
    }
};