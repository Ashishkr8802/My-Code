class Solution {
public:
    int solveUsingMemo(vector<int>& nums1, vector<int>& nums2, int idx1,
                       int idx2, vector<vector<int>>& dp, int& ans) {
        if (idx1 >= nums1.size() || idx2 >= nums2.size()) {
            return 0;
        }

        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }

        int curr = 0;
        if (nums1[idx1] == nums2[idx2]) {
            curr =
                1 + solveUsingMemo(nums1, nums2, idx1 + 1, idx2 + 1, dp, ans);
        }

        int first = solveUsingMemo(nums1, nums2, idx1, idx2 + 1, dp, ans);
        int second = solveUsingMemo(nums1, nums2, idx1 + 1, idx2, dp, ans);

        ans = max(ans, curr);
        dp[idx1][idx2] = curr;

        return curr;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = 0;
        solveUsingMemo(nums1, nums2, 0, 0, dp, ans);
        return ans;
    }
};