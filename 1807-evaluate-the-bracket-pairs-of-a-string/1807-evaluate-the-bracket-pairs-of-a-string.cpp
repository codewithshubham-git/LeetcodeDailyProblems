class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        // Store key -> value
        unordered_map<string, string> mp;

        for (auto &pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string ans = "";

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {

                // Find the closing bracket
                int j = i + 1;

                while (s[j] != ')') {
                    j++;
                }

                // Extract the key
                string key = s.substr(i + 1, j - i - 1);

                // If key exists, use its value
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                }
                else {
                    ans += "?";
                }

                // Move i to ')'
                i = j;
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};