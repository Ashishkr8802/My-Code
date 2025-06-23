class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ss = 0;
        int ts = 0;

        while(ss<s.length() && ts < t.length()) {
            if(s[ss] == t[ts]) {
                ss++;
            }
            ts++;
        }

        if(ss == s.length()) {
            return true;
        }
        else {
            return false;
        }
    }
};