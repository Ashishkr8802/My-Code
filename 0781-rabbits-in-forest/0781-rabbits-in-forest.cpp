class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int , int> countMap;
        int ans = 0;

        for (int i : answers) {
            countMap[i]++;
        }

        // Calculate the minimum number of rabbits
        for (auto& pair : countMap) {
            int groupSize = pair.first + 1;  // Each rabbit reports `x`, meaning `x + 1` are in the group
            int frequency = pair.second;

            // Find how many full groups are needed
            ans += ((frequency + groupSize - 1) / groupSize) * groupSize;  
        }

        return ans;
    }
};