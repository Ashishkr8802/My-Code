class Solution {
public:

    // int solveUsingRecursion(int n) {
    //     if(n == 0) {
    //         return 1;
    //     }

    //     if(n < 0) {
    //         return 0;
    //     }


    //     int ans = INT_MAX;
    //     int i = 1;
    //     int end = sqrt(n);

    //     while(i <= end) {
    //         int perfectSquare = i*i;
    //         int noOfPerfectSquare = 1 + solveUsingRecursion(n-perfectSquare);

    //         if(noOfPerfectSquare < ans) {
    //             ans = noOfPerfectSquare;
    //         }
    //         i++;
    //     }

    //     return ans;
    // }


    int solveUsingMemo(int n , vector<int>& dp) {
        if(n == 0) {
            return 1;
        }

        if(n < 0) {
            return 0;
        }

        if(dp[n] != -1) {
            return dp[n];
        }

        int ans = INT_MAX;
        int i = 1;
        int end = sqrt(n);

        while(i <= end) {
            int perfectSquare = i*i;
            int noOfPerfectSquare = 1 + solveUsingMemo(n-perfectSquare , dp);

            if(noOfPerfectSquare < ans) {
                ans = noOfPerfectSquare;
            }
            i++;
        }

        dp[n] = ans;

        return ans;
    }


    int numSquares(int n) {
        vector<int> dp(n+1 , -1);
        int ans = solveUsingMemo(n , dp)-1;

        // int ans = solveUsingRecursion(n)-1;

        return ans;
    }
};