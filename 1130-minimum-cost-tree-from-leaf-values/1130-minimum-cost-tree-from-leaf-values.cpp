class Solution {
public:
    int solveUsingRecusion(vector<int> &arr , int start , int end , map<pair<int,int> , int>&maxi) {
        if(start >= end) {
            return 0;
        }

        int ans = INT_MAX;

        for(int i=start ; i<end ; i++) {
            ans = min(ans , (maxi[{start,i}] * maxi[{i+1 , end}]
                    + solveUsingRecusion(arr , start , i , maxi)
                    + solveUsingRecusion(arr , i+1 , end , maxi)
            ));
        }

        return ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        for(int i=0 ; i<arr.size() ; i++) {
            maxi[{i,i}] = arr[i];
            for(int j=i+1 ; j<arr.size() ; j++) {
                maxi[{i,j}] = max(arr[j] , maxi[{i,j-1}]);
            }
        }

        int start = 0;
        int end = arr.size()-1;
        int ans = solveUsingRecusion(arr , start , end , maxi);
        return ans;
    }
};