class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n=nums.size();

        long long sum = 0;

        for(int i : nums) {
            sum += i;
        }

        for(int i = n-1 ; i>0 ; i--) {
            if(sum-nums[i] > nums[i]) {
                return sum;
            }
            else {
                sum -= nums[i];
            }
        }

        return -1;
    }
};