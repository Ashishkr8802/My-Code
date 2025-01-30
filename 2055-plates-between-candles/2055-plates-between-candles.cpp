class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> nLc(n,-1);
        vector<int> nRc(n,-1);
        vector<int> nPl(n,0);

        int index = -1;
        for(int i=0 ; i<n ; i++) {
            if(s[i] == '|') {
                index = i;
            }
            nLc[i] = index;
        }

        int indexRight = -1;
        for(int i=n-1 ; i>=0 ; i--) {
            if(s[i] == '|') {
                indexRight = i;
            }
            nRc[i] = indexRight;
        }

        int countStar = 0;
        for(int i=0 ; i<n ; i++) {
            if(s[i] == '*') {
                countStar++;
            }
            nPl[i] = countStar;
        }

        vector<int> ans(queries.size() , 0);

        for(int i=0 ; i<queries.size() ; i++) {
            if(nRc[queries[i][0]] != -1 && nLc[queries[i][1]] != -1 && nRc[queries[i][0]] < nLc[queries[i][1]]) {
                ans[i] = nPl[nLc[queries[i][1]]] - nPl[nRc[queries[i][0]]];
            }
        }
        return ans;
    }
};