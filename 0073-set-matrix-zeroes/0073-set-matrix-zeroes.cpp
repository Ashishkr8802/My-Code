class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();

        bool firstRow = false;
        bool firstCol = false;

        //traverse first row

        for(int i=0 ; i<n ; i++) {
            if(matrix[0][i] == 0) {
                firstRow = true;
                break;
            }
        }

        //traverse first column

        for(int i=0 ; i<m ; i++) {
            if(matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }

        //traverse matrix from 1,1 till end

        for(int i=1 ; i<m ; i++) {
            for(int j=1 ; j<n ; j++) {
                    if(matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
            }
        }

        //again traverse matrix from 1,1 till end and check left most and top most element if this is 0 then 
        // make this element 0

        for(int i=1 ; i<m ; i++) {
            for(int j=1 ; j<n ; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }


        //now check first row and forst column is it is true then make full row or column 0

        if(firstRow == true) {
            for(int i=0 ; i<n ; i++) {
                matrix[0][i] = 0;
            }
        }
        if(firstCol == true) {
            for(int i=0 ; i<m ; i++) {
                matrix[i][0] = 0;
            }
        }

    }
};