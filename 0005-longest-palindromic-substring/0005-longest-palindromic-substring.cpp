class Solution {
public:
    bool isPalindrom(string &s , int i , int j) {
        while(i<=j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int max = INT_MIN;
        int start = 0;
        int end = 0;
        int n = s.length();

        for(int i=0 ; i<n ; i++) {
            for(int j=i ; j<n ; j++) {
                if(isPalindrom(s , i , j) == true) {
                    if((j-i+1) > max) {
                        max = j-i+1;
                        start = i;
                        end = j;
                    }
                }
            }
        }

        return s.substr(start , max);
    }
};