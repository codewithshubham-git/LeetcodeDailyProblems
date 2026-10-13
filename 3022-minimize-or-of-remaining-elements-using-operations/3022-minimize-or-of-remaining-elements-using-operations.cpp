
class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int ans = 0;
        int mask = 0;

        for (int bit = 30; bit >= 0; bit--) {
            mask |= (1 << bit);
            int operations = 0;
            int curr = mask;

            for (int num : nums) {
                curr &= num;

                if ((curr | ans) == ans) {
                    curr = mask;
                } else {
                    operations++;
                }
            }

            if (operations > k) {
                ans |= (1 << bit);
            }
        }

        return ans;
    }
};
