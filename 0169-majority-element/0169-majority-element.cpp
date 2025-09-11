class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freqMap;

        for (int num : nums) {
            freqMap[num]++;
        }

        int majorityCount = nums.size() / 2;
        
        for (auto pair : freqMap) {
            if (pair.second > majorityCount) {
                return pair.first;
            }
        }

        return -1;
    }
};