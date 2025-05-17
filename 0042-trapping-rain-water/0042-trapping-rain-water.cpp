class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int start = 0;
        int end = n-1;
        int leftMax = 0;
        int rightMax = 0;
        int trap = 0;

        while(start < end) {
            if(height[start] < height[end]) {
                if(leftMax > height[start]) {
                    trap += leftMax - height[start];
                }

                leftMax = max(leftMax , height[start]);
                start++;
            }

            else {
                if(rightMax > height[end]) {
                    trap += rightMax - height[end];
                }

                rightMax = max(rightMax , height[end]);

                end--;
            }
        }

        return trap;
    }
};