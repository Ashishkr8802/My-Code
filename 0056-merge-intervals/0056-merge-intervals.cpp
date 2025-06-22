class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans;
        int m = intervals.size();
        

        for(int i=0; i<m ; i++) {
            if(ans.empty()) {
                ans.push_back(intervals[i]);
            }

            else {
                vector<int> &v = ans.back();
                int x = v[1];

                if(x >= intervals[i][0]) {
                    v[1] = max(x , intervals[i][1]);
                }

                else {
                    ans.push_back(intervals[i]);
                }
            }
        }


        return ans;
    }
};