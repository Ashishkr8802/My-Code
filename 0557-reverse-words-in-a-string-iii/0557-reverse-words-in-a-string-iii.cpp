class Solution {
public:
    string reverseWords(string s) {
        int l=0 , r=0;
        while(l < s.length()) {
            while(r < s.length() && s[r] != ' ') {
                r++;
            }

            int i = l;
            int j = r-1;

            while(i < j) {
                swap(s[i],s[j]);
                i++;
                j--;
            }

            l = r+1;
            r = l;
        }

        return s;
    }
};