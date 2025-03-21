class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            total += mat[i][i];  // Primary diagonal
            if (i != n - i - 1) {
                total += mat[i][n - i - 1];  // Secondary diagonal (excluding center if overlapped)
            }
        }
        return total;
    }
};