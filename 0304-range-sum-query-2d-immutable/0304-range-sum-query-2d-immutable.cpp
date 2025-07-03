class NumMatrix {
public:
    vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        prefixSum = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0)); //initialize with 0
        prefixSum[0][0] = matrix[0][0];

        // rows = matrix.size();
        // cols = matrix[0].size();


        //first row
        for(int i = 1 ; i<matrix[0].size() ; i++) {
            prefixSum[0][i] = prefixSum[0][i-1] + matrix[0][i];
        }

        //first column
        for(int i = 1 ; i < matrix.size() ; i++) {
            prefixSum[i][0] = prefixSum[i-1][0] + matrix[i][0];
        }

        //all the other elements 

        for(int i = 1 ; i < matrix.size() ; i++) {
            for(int j = 1 ; j < matrix[0].size() ; j++) {
                prefixSum[i][j] = matrix[i][j] + prefixSum[i][j-1] + prefixSum[i-1][j] - prefixSum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int Answer = prefixSum[row2][col2];
        
        if(row1 - 1 >= 0) {
            Answer = Answer - prefixSum[row1-1][col2];
        }

        if(col1 - 1 >= 0) {
            Answer = Answer - prefixSum[row2][col1-1];
        }

        if(row1 - 1 >= 0 && col1 - 1 >= 0) {
            Answer = Answer + prefixSum[row1-1][col1-1];
        }
        
        return Answer;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */