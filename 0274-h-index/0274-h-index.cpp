class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> arr(n + 1 , 0);
        for(int i=0 ; i<n ; i++) {
            if(citations[i] >= n) {
                arr[n] += 1;
            }
            else {
                arr[citations[i]] += 1;
            }
        }

        //suffix Sum

        for(int i=n-1 ; i>=0 ; i--) {
            arr[i] = arr[i] + arr[i+1];
        }
        int ans;
        for(int i=n ; i>=0 ; i--) {
            if(arr[i] >= i) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};