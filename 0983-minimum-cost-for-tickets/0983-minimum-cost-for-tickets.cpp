class Solution {
public:
    // int solveUsingRecursion(vector<int> days , vector<int> costs , int i) {
    //     if(i>=days.size()) {
    //         return 0;
    //     }
    //     //1day cost
    //     int cost1 = costs[0] + solveUsingRecursion(days , costs , i+1);

    //     //7day cost
    //     int endOfday = days[i] + 7-1;
    //     int j=i;
    //     while(j < days.size() && days[j] <= endOfday) {
    //         j++;
    //     }

    //     int cost7 = costs[1] + solveUsingRecursion(days , costs , j);

    //     //30 days cost
    //     endOfday = days[i] + 30-1;
    //     j=i;
    //     while(j < days.size() && days[j] <= endOfday) {
    //         j++;
    //     }

    //     int cost30 = costs[2] + solveUsingRecursion(days , costs , j);

    //     return min({cost1 , cost7 , cost30});

    // }



    int solveUsingMemo(vector<int> days , vector<int> costs , int i , vector<int> &dp) {
        if(i>=days.size()) {
            return 0;
        }


        if(dp[i] != -1) {
            return dp[i];
        }
        //1day cost
        int cost1 = costs[0] + solveUsingMemo(days , costs , i+1 , dp);

        //7day cost
        int endOfday = days[i] + 7-1;
        int j=i;
        while(j < days.size() && days[j] <= endOfday) {
            j++;
        }

        int cost7 = costs[1] + solveUsingMemo(days , costs , j , dp);

        //30 days cost
        endOfday = days[i] + 30-1;
        j=i;
        while(j < days.size() && days[j] <= endOfday) {
            j++;
        }

        int cost30 = costs[2] + solveUsingMemo(days , costs , j ,dp);

        dp[i] = min({cost1 , cost7 , cost30});

        return dp[i];

    }



    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1 , -1);
        // int ans = solveUsingRecursion(days , costs , 0);
        int ans = solveUsingMemo(days , costs , 0 , dp);
        return ans;
    }
};