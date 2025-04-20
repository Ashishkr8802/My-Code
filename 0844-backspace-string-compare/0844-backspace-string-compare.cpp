class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        stack<char> st1;
        stack<char> st2;

        for(int i=0 ; i<n1 ; i++) {
            if(s[i] != '#') {
                st1.push(s[i]);
            }
            else {
                if(!st1.empty()) {
                    st1.pop();
                }
            }
        }

        for(int i=0 ; i<n2 ; i++) {
            if(t[i] != '#') {
                st2.push(t[i]);
            }
            else {
                if(!st2.empty()) {
                    st2.pop();
                }
            }
        }

        if(st1.size() != st2.size()) {
            return false;
        }


        while(!st1.empty() && !st2.empty()) {
            if(st1.top() == st2.top()) {
                st1.pop();
                st2.pop();
            }
            else {
                return false;
            }
        }

        return true;
    }
};