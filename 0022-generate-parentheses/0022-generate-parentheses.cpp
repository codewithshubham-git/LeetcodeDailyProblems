class Solution {
public:
    vector<string> result;

    void backtrack(string current, int open, int close, int n) {
        
        // If the string contains 2*n brackets
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // We can add '(' if we haven't used all n opening brackets
        if (open < n) {
            backtrack(current + "(", open + 1, close, n);
        }

        // We can add ')' only if there are unmatched '('
        if (close < open) {
            backtrack(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
};