class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> spiral;

        int r1=0;
        int r2 = m-1;
        int c1 = 0;
        int c2 = n-1; 

        while(r1<=r2 && c1<=c2) {
            for(int c=c1 ; c<=c2 ; c++) {
                spiral.push_back(matrix[r1][c]);
            }

            for(int r=r1+1 ; r<=r2 ; r++) {
                spiral.push_back(matrix[r][c2]);
            }

            if(r1<r2 && c1<c2) {
                for(int c=c2-1 ; c>=c1 ; c--) {
                    spiral.push_back(matrix[r2][c]);
                }

                for(int r=r2-1 ; r>r1 ; r--) {
                    spiral.push_back(matrix[r][c1]);
                }
            }

            r1++;
            r2--;
            c1++;
            c2--;

        }

        return spiral;
    }
};