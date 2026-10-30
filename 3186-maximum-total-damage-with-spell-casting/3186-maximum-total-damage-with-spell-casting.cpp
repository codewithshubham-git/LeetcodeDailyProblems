class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> mp;

        for(int x : power) {
            mp[x]++;
        }

        vector<int> nums;
        vector<long long> freq;

        for(auto it : mp) {
            nums.push_back(it.first);
            freq.push_back(it.second);
        }

        int n = nums.size();

        vector<long long> dp(n + 1, 0);

        for(int i = 0; i < n; i++) {

            long long damage = 1LL * nums[i] * freq[i];

            // Find the number of previous values < nums[i] - 2
            int j = lower_bound(nums.begin(), nums.begin() + i,
                                nums[i] - 2) - nums.begin();

            // Either skip current damage or take it
            dp[i + 1] = max(dp[i], damage + dp[j]);
        }

        return dp[n];
    }
};
