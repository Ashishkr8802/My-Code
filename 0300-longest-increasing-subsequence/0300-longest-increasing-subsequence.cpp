class Solution {
public:
    int solveUsingRec(vector<int> &nums , int curr , int prev) {
        if(curr >= nums.size()) {
            return 0;
        }
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solveUsingRec(nums , curr+1 , curr);
        }
        int exclude = 0 + solveUsingRec(nums , curr+1 , prev);

        int ans = max(include,exclude);

        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0;
        int prev = -1;
        int ans = solveUsingRec(nums , curr , prev);
        return ans;
    }
};