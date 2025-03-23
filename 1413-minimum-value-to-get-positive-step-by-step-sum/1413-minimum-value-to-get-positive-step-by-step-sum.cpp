class Solution {
public:
    int minStartValue(vector<int>& nums) {
        // int n = nums.size();
        // int startValue = 1;
        // nums[0] += startValue;

        // for(int i=1 ; i<n ; i++) {
            
        //     nums[i] += nums[i-1];
        //     if(nums[i] < 1 || nums[0] < 1) {
        //         startValue++;
        //         break;
        //     }
        // }

        // return startValue;


        int minPrefixSum = 0, sum = 0;

        for (int num : nums) {
            sum += num;                      // Compute the running sum
            minPrefixSum = min(minPrefixSum, sum);  // Track the minimum prefix sum
        }

        return 1 - minPrefixSum;
    }
};