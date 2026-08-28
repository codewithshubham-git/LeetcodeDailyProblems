class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        vector<int> cnt(26, 0);

        // Count characters
        for(char ch : s) {
            cnt[ch - 'a']++;
        }

        // Check if palindrome is possible
        int odd = 0;
        char middle = 0;

        for(int i = 0; i < 26; i++) {
            if(cnt[i] % 2 == 1) {
                odd++;
                middle = 'a' + i;
            }
        }

        if(odd > 1)
            return "";

        // We only need to build the left half
        vector<int> half(26);

        for(int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        int len = n / 2;

        string left = "";

        // Build the left half
        for(int i = 0; i < len; i++) {

            bool found = false;

            for(int ch = 0; ch < 26; ch++) {

                if(half[ch] == 0)
                    continue;

                half[ch]--;
                left += char('a' + ch);

                // Make the largest possible remaining palindrome
                string temp = left;

                for(int x = 25; x >= 0; x--) {
                    temp += string(half[x], char('a' + x));
                }

                string right = temp.substr(0, n / 2);
                reverse(right.begin(), right.end());

                string candidate = temp;

                if(n % 2 == 1)
                    candidate += middle;

                candidate += right;

                if(candidate > target) {
                    found = true;
                    break;
                }

                // Undo
                left.pop_back();
                half[ch]++;
            }

            if(!found)
                return "";
        }

        string answer = left;

        if(n % 2 == 1)
            answer += middle;

        reverse(left.begin(), left.end());
        answer += left;

        return answer > target ? answer : "";
    }
};