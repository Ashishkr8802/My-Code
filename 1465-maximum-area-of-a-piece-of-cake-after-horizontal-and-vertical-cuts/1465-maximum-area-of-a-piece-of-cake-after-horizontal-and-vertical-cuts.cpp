class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin() , horizontalCuts.end());
        sort(verticalCuts.begin() , verticalCuts.end());

        long maxHeight = horizontalCuts[0];
        long maxWeidth = verticalCuts[0];
        int n = horizontalCuts.size();
        int m = verticalCuts.size();

        for(int i=1 ; i<n ; i++) {
            maxHeight = max((long)horizontalCuts[i] - (long)horizontalCuts[i-1] , maxHeight);
        }
        maxHeight = max((h - (long)horizontalCuts[n-1]) , maxHeight);


        for(int i=1 ; i<m ; i++) {
            maxWeidth = max((long)verticalCuts[i] - (long)verticalCuts[i-1] , maxWeidth);
        }
        maxWeidth = max((w - (long)verticalCuts[m-1]) , maxWeidth);

        long long ans = (maxHeight * maxWeidth) % 1000000007;

        return (int)ans;
    }
};