class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int ans = 1;
        for(int i=n-1 ; i>=n-3 ; i--) {
            ans *= nums[i];
        }

        return ans;
    }
};