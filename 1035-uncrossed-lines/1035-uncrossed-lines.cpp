class Solution {
public:
    // int solveUsingRecursion(vector<int>& nums1 , vector<int>& nums2 , int i , int j) {
    //     if(i>=nums1.size() || j>=nums2.size()) {
    //         return 0;
    //     }

    //     int ans = 0;

    //     if(nums1[i] == nums2[j]) {
    //         ans = 1 + solveUsingRecursion(nums1 , nums2 , i+1 , j+1);
    //     }
    //     else {
    //         ans = max(solveUsingRecursion(nums1 , nums2 , i+1 , j) , solveUsingRecursion(nums1 , nums2 , i , j+1));
    //     }

    //     return ans;
    // }


    int solveUsingMemo(vector<int>& nums1 , vector<int>& nums2 , int i , int j , vector<vector<int>> &dp) {
        if(i>=nums1.size() || j>=nums2.size()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = 0;

        if(nums1[i] == nums2[j]) {
            ans = 1 + solveUsingMemo(nums1 , nums2 , i+1 , j+1 , dp);
        }
        else {
            ans = max(solveUsingMemo(nums1 , nums2 , i+1 , j , dp) , solveUsingMemo(nums1 , nums2 , i , j+1 , dp));
        }

        dp[i][j] = ans;

        return ans;
    }


    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<int>> dp(nums1.size()+1 , vector<int>(nums2.size()+1 , -1));

        // int ans = solveUsingRecursion(nums1 , nums2 , 0 , 0);

        int ans = solveUsingMemo(nums1 , nums2 , 0 , 0 , dp);
        return ans;
    }
};