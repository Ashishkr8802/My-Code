class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int start = 0;
        int count = 0;
        int sum = 0;

        for (int end = 0; end < n; ++end) {
            sum += nums[end];

            while (start <= end && sum > goal) {
                sum -= nums[start];
                start++;
            }

            if (sum == goal) {
                // Count all valid starts for current end
                int temp = start;
                int tempSum = sum;
                while (temp <= end && tempSum == goal) {
                    count++;
                    tempSum -= nums[temp];
                    temp++;
                }
            }
        }

        return count;
    }
};