class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> reshaped(r, vector<int>(c));
        int col = mat[0].size();
        int row = mat.size();

        if (row * col != r * c) {
            return mat; // Return the original matrix if reshape is not possible
        }
        int k = 0;
        for(int i=0 ; i<row ; i++) {
            for(int j=0 ; j<col ; j++) {
                reshaped[k/c][k%c] = mat[i][j];
                k++;
            }
        }

        return reshaped;
    }
};