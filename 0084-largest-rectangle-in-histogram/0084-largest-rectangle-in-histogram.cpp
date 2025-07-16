class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmallest(n,0);
        vector<int> rightSmallest(n,0);
        stack<int> st;

        //right smallest

        for(int i=n-1 ; i>=0 ; i--) {
            while(st.size() > 0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            rightSmallest[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) {
            st.pop();
        }

        //left smallest

        for(int i=0 ; i<n ; i++) {
            while(st.size() > 0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            leftSmallest[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i=0 ; i < n ; i++) {
            
            int width = rightSmallest[i] - leftSmallest[i] - 1;
            int currArea = heights[i]*width;

            ans = max(ans , currArea);
        }

        return ans;
    }
};