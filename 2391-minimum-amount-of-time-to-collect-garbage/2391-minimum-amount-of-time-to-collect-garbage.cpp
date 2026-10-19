class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int ans = 0;

        // Time to collect all garbage
        for (int i = 0; i < n; i++) {
            ans += garbage[i].size();
        }

        // Prefix sum of travel times
        for (int i = 1; i < n - 1; i++) {
            travel[i] += travel[i - 1];
        }

        // Find the last house containing each garbage type
        for (char c : {'M', 'P', 'G'}) {
            for (int i = n - 1; i >= 0; i--) {
                if (garbage[i].find(c) != string::npos) {
                    if (i > 0) {
                        ans += travel[i - 1];
                    }
                    break;
                }
            }
        }

        return ans;
    }
};
