class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
            vector<int> num(nums.size()+1 , 0);

            for(int i=0 ; i<requests.size() ; i++) {
                num[requests[i][0]] += 1;
                num[requests[i][1] + 1] -= 1;
            }

            for(int i=1 ; i<num.size() ; i++) {
                num[i] = num[i] + num[i-1];
            }
            num.pop_back();

            sort(num.begin() , num.end());
            sort(nums.begin() , nums.end());

            long long ans = 0;

            for(int i = num.size()-1 ; i>=0 ; i--) {
                ans += (long)num[i] * (long)nums[i];
            }

            return ans % 1000000007;
    }
};