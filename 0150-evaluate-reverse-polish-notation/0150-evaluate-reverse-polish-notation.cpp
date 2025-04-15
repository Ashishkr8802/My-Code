class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        for(int i = 0 ; i<n ; i++) {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/" ){
                st.push(stoi(tokens[i]));
            }
            else {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();

                if(tokens[i] == "+") {
                    st.push(second + first);
                }
                else if (tokens[i] == "-") {
                    st.push(second - first);
                }

                else if(tokens[i] == "*") {
                    st.push(second * first);
                }

                else if(tokens[i] == "/") {
                    st.push(second / first);
                }
            }
        }

        return st.top();
    }
};