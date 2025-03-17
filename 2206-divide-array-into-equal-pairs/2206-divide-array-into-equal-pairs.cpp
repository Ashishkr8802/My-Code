class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        int pairs = n/2;
        int count = 0;
        sort(nums.begin() , nums.end());

        for(int i=1 ; i<n ; i += 2) {
            if(nums[i-1] == nums[i]) {
                count++;
            }
        }

        if(count == pairs) {
            return true;
        }
        else{
            return false;
        }
    }
};