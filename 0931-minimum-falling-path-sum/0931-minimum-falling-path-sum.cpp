class Solution {
public:
    // int solveUsingRecursion(vector<vector<int>>& matrix , int row , int col) {
    //     int n = matrix.size();
    //     int m = matrix[0].size();

    //     if(col < 0 || col >= m) {
    //         return INT_MAX;
    //     }

    //     if (row == n - 1) return matrix[row][col];


    //     long long ans = INT_MAX;
    //     int leftDiag = solveUsingRecursion(matrix, row + 1, col - 1);
    //     int down = solveUsingRecursion(matrix, row + 1, col);
    //     int rightDiag= solveUsingRecursion(matrix, row + 1, col + 1);

    //     ans = matrix[row][col] + min(leftDiag , min(down , rightDiag));

    //     return ans;
        
    // }


    int solveUsingMemo(vector<vector<int>>& matrix , int row , int col , vector<vector<int>> &dp) {
        int n = matrix.size();
        int m = matrix[0].size();

        if(col < 0 || col >= m) {
            return INT_MAX;
        }

        if (row == n - 1) return matrix[row][col];

        if(dp[row][col] != INT_MAX) {
            return dp[row][col];
        }

        int leftDiag = solveUsingMemo(matrix, row + 1, col - 1 , dp);
        int down = solveUsingMemo(matrix, row + 1, col , dp);
        int rightDiag= solveUsingMemo(matrix, row + 1, col + 1 , dp);

        dp[row][col] = matrix[row][col] + min(leftDiag , min(down , rightDiag));
        return dp[row][col];
        
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n , vector<int>(m , INT_MAX));
        int row = 0;
        int ans = INT_MAX;
        for (int col = 0; col < m; col++) {
            // ans = min(ans, solveUsingRecursion(matrix, row, col));
            ans = min(ans, solveUsingMemo(matrix, 0, col , dp));
        }
        return ans;
    }
};