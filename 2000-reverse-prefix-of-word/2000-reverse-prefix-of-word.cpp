class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        int j = 0;
        for(int i=0 ; i<word.length() ; i++) {
            if(word[i] == ch) {
                j = i;
                break;
            }
        }

        while(i<j) {
            swap(word[i] , word[j]);
            i++;
            j--;
        }

        return word;
    }
};