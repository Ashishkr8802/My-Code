class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int leftptr = 0;
        int rightptr = 0;
        int n = nums.size();

        while(rightptr < n) {
            if(nums[rightptr] != 0) {
                swap(nums[rightptr], nums[leftptr]);
                rightptr++;
                leftptr++;
            }
            else {
                rightptr++;
            }
        }
        
    }
};