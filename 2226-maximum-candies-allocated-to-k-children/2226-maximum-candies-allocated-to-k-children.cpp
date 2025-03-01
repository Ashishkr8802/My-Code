class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
       long long start = 1;
        long long end = *max_element(candies.begin(), candies.end()); // Max candy count
        int ans = 0;

        while (start <= end) {
            long long sum = 0;
            long long mid = start + (end - start) / 2;

            for (auto i : candies) {
                sum += i / mid; // Calculate number of children who can get mid-sized candy piles
            }

            if (sum >= k) { 
                ans = mid; // Store potential answer
                start = mid + 1; // Try to maximize mid
            } else {
                end = mid - 1; // Reduce mid
            }
        }

        return ans;
    }
};