// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int first = 1;
        int end = n;

        while(first < end) {
            int mid = first + (end - first)/2;

            if(isBadVersion(mid)) {
                end = mid;
            }

            else {
                first = mid + 1;
            }
        }

        return first;
    }
};