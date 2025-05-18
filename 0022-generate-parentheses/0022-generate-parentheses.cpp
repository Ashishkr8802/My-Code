class Solution {
public:
    void fun(int n , int open , int close , string str, vector<string>& ans) {
        //base case
        if(str.length() == 2*n) {
            ans.push_back(str);
            return;
        }

        //strart with opening bracket
        if(open>0) {
            fun(n , open-1 , close , str+"(" , ans);
        }

        //next choise closing bracket
        if((open - close) < 0) {
            fun(n , open , close-1 , str+")" , ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;    
        fun(n,n,n,"",ans);

        return ans;
    }
};