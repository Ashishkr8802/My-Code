class Solution {
public:
    int maxVowels(string s, int k) {
        int size = s.length();
        int count = 0;
        int maxCount = 0;

        //count for 1st window
        for(int i=0 ; i<k ; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count++;
            }
        }

        maxCount = count;

        for(int i=k ; i < size ; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                count++;
            }

            if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u') {
                count--;
            }

            maxCount = max(maxCount , count);
        }

        return maxCount;
    }
};