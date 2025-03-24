class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int col = colsum.size();
        vector<vector<int>> mat(2 , vector<int> (col));

        for(int i=0 ; i<col ; i++) {
            if(colsum[i] == 2) {
                if(upper != 0 && lower != 0) {
                    mat[0][i] = 1;
                    mat[1][i] = 1;
                    upper--;
                    lower--;
                    colsum[i] = 0;
                }
            }
        }

        for(int i=0 ; i < col ; i++) {
            if(colsum[i] != 0 && upper != 0) {
                mat[0][i] = 1;
                colsum[i]--;
                upper--;
            }
        }

        for(int i=0 ; i < col ; i++) {
            if(colsum[i] != 0 && lower != 0) {
                lower--;
                mat[1][i] = colsum[i];
                colsum[i]--;
            }
        }

        int sum = 0;

        for(int i=0 ; i<col ; i++) {
            sum += colsum[i];
        }

        if(upper != 0 || lower != 0 || sum != 0) {
            return {};
        }

        return mat;
    }
};