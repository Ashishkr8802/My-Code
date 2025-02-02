class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    float sum = 0;
    float maxi = INT_MIN;
    

    // first window sum
    for(int i=0 ; i<k ; i++) {
        sum += nums[i];
    }
    float avg = sum/k;

    maxi = max(avg , maxi);

    
    int end = k;
    int start = end - k;
    while(end < n) {
        sum = sum + nums[end] - nums[start];
        avg = sum/k;
        maxi = max(avg , maxi);
        start++;
        end++;
    }

    return maxi;
    }
};