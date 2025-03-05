class Solution {
public:
    string customSortString(string order, string s) {
        string str;
        unordered_map<char , int> charCount;
        for(char ch: s) {
            charCount[ch]++;
        }

        for(char ch : order) {
            if(charCount.find(ch) != charCount.end()) {
                str.append(charCount[ch], ch);
                charCount.erase(ch);
            }
        }


        for (auto pair : charCount) {
            str.append(pair.second, pair.first);
        }

    return str;
    }
};