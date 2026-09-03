class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int mn = INT_MAX;

        // Find the smallest number
        for(int x : nums1) {
            mn = min(mn, x);
        }

        // If smallest number is odd,
        // answer is always true
        if(mn % 2 == 1) {
            return true;
        }

        // Smallest number is even.
        // Then every number must be even.
        for(int x : nums1) {
            if(x % 2 == 1) {
                return false;
            }
        }

        return true;
    }
};