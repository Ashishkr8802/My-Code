class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int j=0;
        
        int pos = -1;

        for(int i=0; i<n ; i++) {
            if(word[i] == ch) {
                pos = i;
                break;
            }
        }

        if(pos == -1) {
            return word;
        }

        while(j<pos) {
            swap(word[j] , word[pos]);
            j++;
            pos--;
        }

        return word;
    }
};