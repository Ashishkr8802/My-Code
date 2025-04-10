class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;

        for(int i : asteroids) {
            if(i > 0) {
                st.push(i);
            }
            while(!st.empty() && st.top() > 0 && st.top() < -i) {
                st.pop();
            }

            if(st.empty() || st.top() < 0) {
                st.push(i);
            }

            if(!st.empty() && st.top() == -i) {
                st.pop();
            }
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};