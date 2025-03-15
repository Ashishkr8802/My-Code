class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n*n;
        vector<int> ans();
        int repeated = -1;
        int missing = -1;

        for(auto x : grid) {
            for(auto it : x) {
                ans[it]++;
            }
        }

        for(int num = 1 ; num < size ; num++) {
            if(ans[num] == 2) {
                repeated = num;
            }
            if(ans[num] == 0) {
                missing = num;
            }
        }

        return {repeated , missing};
    }
};