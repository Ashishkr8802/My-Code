class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        long long sum = 0;
        long long maxSum = 0;
        int index = 0;
        
        // Build the first window
        while (index < n && index < k) {
            freq[nums[index]]++;
            sum += nums[index];
            index++;
        }
        
        if (freq.size() == k) {
            maxSum = sum;
        }
        
        // Slide the window
        for (int i = 1; i < n - k + 1; i++) {
            int prevEle = nums[i - 1];
            int nextEle = nums[i + k - 1];
            
            // Remove previous element
            freq[prevEle]--;
            if (freq[prevEle] == 0) {
                freq.erase(prevEle);
            }
            sum -= prevEle;
            
            // Add next element
            freq[nextEle]++;
            sum += nextEle;
            
            // Only update maxSum if all elements are distinct
            if (freq.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }
        
        return maxSum;
    }
};
