class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        
        for (char digit : num) {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        
        // Remove remaining k digits from the top
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        // Construct the result string
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        
        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }
        
        result = result.substr(i);
        
        return result.empty() ? "0" : result;
    }
};