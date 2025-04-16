class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<string> st;
        vector<string> ans;
        int size = target.size();
        int range = target[size-1];

        for(int i=1 , j = 0 ; i<=range ; i++) {
            if(target[j] == i) {
                st.push("Push");
                j++;
            }
            else {
                st.push("Push");
                st.push("Pop");
            }
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};