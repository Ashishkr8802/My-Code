class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int hash[256] = {-1};
        // fill(hash, hash + 256, -1);
        int l = 0;
        int r = 0;
        int maxLength = 0;

        while(r < n) {
            if(hash[s[r]] != -1) {
                if(hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxLength = max(len , maxLength);
            hash[s[r]] = r;
            r++;
        }
        return maxLength;
    }
};