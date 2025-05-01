class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;

        int n = pushed.size();

        // st.push(pushed[0]);
        int j = 0;

        for(int i=0 ; i<n ; i++) {
            st.push(pushed[i]);
            while(j<n && !st.empty()) {
                if(st.top() == popped[j]) {
                    st.pop();
                    j++;
                }
                else {
                    break;
                }
            }
        }

        if(st.empty()) {
            return true;
        }

        return false;
    }
};