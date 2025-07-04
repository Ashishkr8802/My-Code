class NumArray {
public:
    vector<int> prefixSum;

    NumArray(vector<int>& nums) {
        prefixSum = nums;
        for(int i = 1 ; i < prefixSum.size() ; i++) {
            prefixSum[i] = prefixSum[i] + prefixSum[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? prefixSum[right] : prefixSum[right] - prefixSum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */