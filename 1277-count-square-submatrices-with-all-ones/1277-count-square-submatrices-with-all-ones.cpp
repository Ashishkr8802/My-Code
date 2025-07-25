class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));

        for(int i=0 ; i<m ; i++) {
            ans[0][i] = matrix[0][i];
        }

        for(int i=0 ; i<n ; i++) {
            ans[i][0] = matrix[i][0];
        }


        for(int i=1 ; i<n ; i++) {
            for(int j=1 ; j<m ; j++) {
                if(matrix[i][j] != 0) {
                    ans[i][j] = 1 + min(ans[i-1][j] , min(ans[i][j-1] , ans[i-1][j-1]));
                }
            }
        }


        int squares = 0;

        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                squares += ans[i][j];
            }
        }


        return squares;
    }
};