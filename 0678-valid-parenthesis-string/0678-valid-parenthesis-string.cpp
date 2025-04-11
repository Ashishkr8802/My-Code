class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<char> st;
        stack<char> st2;

        for(int i=0 ; i<n ; i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == '*') {
                st2.push(i);
            }

            else {
                if(!st.empty()) {
                    st.pop();
                }

                else if(!st2.empty()) {
                    st2.pop();
                }

                else {
                    return false;
                }
            }
        }
        // if(st.size() == st2.size()) {
        //     return true;
        // }
        // else if(st.size() == 0 && st2.size() != 0) {
        //     return true;
        // }
        // else {
        //     return false;
        // }

        while(!st.empty() && !st2.empty()) {
            if(st.top() > st2.top()) {
                return false;
            }
            st.pop();
            st2.pop();
        }

        return st.empty();
    }
};