class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> small;
        vector<int> equal;
        vector<int> greater;

        for(int i:nums) {
            if(i < pivot) {
                small.push_back(i);
            }
        }

        for(int i:nums) {
            if(i == pivot) {
                equal.push_back(i);
            }
        }

        for(int i:nums) {
            if(i > pivot) {
                greater.push_back(i);
            }
        }

        vector<int> ans;

        ans.insert(ans.end() , small.begin() , small.end());
        ans.insert(ans.end() , equal.begin() , equal.end());
        ans.insert(ans.end() , greater.begin() , greater.end());



        for(int i:ans) {
            cout<<i<<" ";
        }
        return ans;
    }
};