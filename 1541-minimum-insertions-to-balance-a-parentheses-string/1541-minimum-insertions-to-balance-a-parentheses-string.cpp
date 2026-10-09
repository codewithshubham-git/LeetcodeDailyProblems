class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } 
            else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    // Found a pair of closing brackets
                    i++;
                } 
                else {
                    // Only one ')' available; insert another
                    insertions++;
                }

                if (open > 0) {
                    open--;
                } 
                else {
                    // No matching '('; insert one
                    insertions++;
                }
            }
        }
        return insertions + 2 * open;
    }
};
