class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int TotalSum = 0;
        int sum = 0;

        for(int i=0 ; i<=n ; i++) {
            TotalSum += i;
        }

        for(int i=0 ; i<n ; i++) {
            sum += nums[i];
        }

        int ans = TotalSum - sum;

        return ans;
    }
};