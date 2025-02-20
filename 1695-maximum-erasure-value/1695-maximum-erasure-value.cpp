class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int , int> mp;

        int maxi = INT_MIN;
        int sum = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();

        while(j < n) {
            sum += nums[j];
            mp[nums[j]]++;

            while(mp[nums[j]] > 1) {
                mp[nums[i]]--;
                sum -= nums[i++];
            }

            maxi = max(sum , maxi);

            j++;
        }

        return maxi;
    }
};