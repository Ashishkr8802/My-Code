class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int n = nums.size();

        int i = 0;
        int sum = 0;
        int diff = INT_MAX;
        int currDiff = -1;
        int closestSum = 0;

        for(int i=0 ; i<n-2 ; i++) {
            int j = i+1;
            int k = n-1;
            while(j<k) {
                sum = nums[i] + nums[j] + nums[k];
                currDiff = abs(target - sum);
                if (currDiff < diff) {
                    diff = currDiff;
                    closestSum = sum;
                }

                if (sum < target) {
                    j++; // Increase sum
                } else if (sum > target) {
                    k--; // Decrease sum
                } else {
                    return target; // Found exact match
                }
            }
        }

        return closestSum;
    }
};