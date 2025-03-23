class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int maxi = INT_MIN;
        if(n == 1) {
            if(gain[0] < 0) {
                return 0;
            }
            else {
                return gain[0];
            }
        }

        for(int i=1 ; i<n ; i++) {
            gain[i] = gain[i-1] + gain[i];
            maxi = max(maxi , max(gain[i] , gain[i-1]));
        }

        if(maxi < 0) {
            return 0;
        }

        return maxi;
    }
};