class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        int n = str.length();
        int start;
        if(str[0] == '-') {
            start = 1;
        }
        else {
            start = 0;
        }
        
        int end = n-1;

        while(start < end) {
            swap(str[start] , str[end]);
            start++;
            end--;
        }
        long reversedNum = stol(str); // Use long to check for overflow

        // Check 32-bit signed integer range
        if(reversedNum < INT_MIN || reversedNum > INT_MAX) {
            return 0;
        }
        return (int)reversedNum;
    }
};