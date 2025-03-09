class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int , int> map;
        int sum = 0;
        int ans = 0;
        
        map.insert({0,1});
        for(int i=0 ; i<nums.size() ; i++) {
            sum += nums[i];
            int remainder = sum % k;
            

            if(map.find(remainder) != map.end()) {
            ans += map[remainder];
            map[remainder]++;
            }
            else {
                map[remainder]++;
            }
        }
        return ans;
    }
};