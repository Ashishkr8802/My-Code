class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin() , tokens.end());
        int n = tokens.size();
        int start = 0;
        int end = n-1;
        int score = 0;
        int maxScore = 0;

        if(n < 1) {
            return 0;
        }

        if(n==1 ) {
            if(power - tokens[0] >= 0) {
                return 1;
            }
        }

        if(tokens[0] > power) {
            return 0;
        }

        while(start <= end) {
            if(power - tokens[start] >=0) {
                score++;
                power = power - tokens[start];
                start++;
                maxScore = max(maxScore , score);
            }
            else if(score >= 1 && power - tokens[start] < 0) {
                score--;
                power = power + tokens[end];
                end--;
                maxScore = max(maxScore , score);
            }
        }
        return maxScore;
    }
};