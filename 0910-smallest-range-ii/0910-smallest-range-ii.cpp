class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int ans = nums[n-1] - nums[0];
        int bestLeft = nums[0] + k;
        int bestRight = nums[n-1] - k;
        int i=0;
        while (i < n-1) {
            int mini;
            int maxi;
            mini = min(nums[i+1] - k , bestLeft);
            maxi = max(nums[i] + k , bestRight);
            ans = min(maxi - mini , ans);
            i++;
        }

        return ans;
    }
};