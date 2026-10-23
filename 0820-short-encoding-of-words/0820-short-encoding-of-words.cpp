
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());

        for (string word : words) {
            for (int i = 1; i < word.size(); i++) {
                st.erase(word.substr(i));
            }
        }

        int ans = 0;

        for (string word : st) {
            ans += word.size() + 1;
        }

        return ans;
    }
};
