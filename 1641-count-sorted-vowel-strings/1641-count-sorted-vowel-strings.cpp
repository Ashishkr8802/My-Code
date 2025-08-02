class Solution {
public:
    int solveUsingRecursion(int start , int length , int n) {
        if(length == n) {
            return 1;
        }

        int count = 0;

        for(int i=start ; i<5 ; i++) {
            count += solveUsingRecursion(i , length+1 , n);
        }

        return count;
    }
    int countVowelStrings(int n) {
        int ans = solveUsingRecursion(0,0,n);
        return ans;
    }
};