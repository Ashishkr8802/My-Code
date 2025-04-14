class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        stack<char> st;

        if(n == 0) {
            return "";
        }
        st.push(s[0]);

        for(int i=1 ; i<n ; i++ ){
            if(!st.empty() && (abs(s[i] - st.top()) == 32)) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        };

        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};