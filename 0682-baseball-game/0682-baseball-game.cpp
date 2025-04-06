class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> st;

        for(int i=0 ; i<n ; i++) {
            
            if(operations[i] == "+") {
                int temp = st.top();
                st.pop();
                int newTop = temp + st.top();
                st.push(temp);
                st.push(newTop);
            }

            else if(operations[i] == "D") {
                st.push(2*st.top());
            }

            else if(operations[i] == "C") {
                st.pop();
            }
            else {
                st.push(stoi(operations[i]));
            }
        }

        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};