class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        while (num != 0) {
            num /= 10;
            count++;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            int ans = countDigits(nums[i]);

            if (ans % 2 == 0) {
                result++;
            }
        }

        return result;
    }
};