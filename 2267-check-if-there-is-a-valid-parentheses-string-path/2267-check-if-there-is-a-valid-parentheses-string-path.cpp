class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // A valid parentheses string must have even length.
        int len = m + n - 1;
        if (len % 2 == 1) return false;

        // balance can never exceed len/2 for a valid path
        int maxBalance = len / 2;

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(maxBalance + 1, false))
        );

        // Starting cell
        if (grid[0][0] == '(') {
            dp[0][0][1] = true;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) continue;

                for (int balance = 0; balance <= maxBalance; balance++) {

                    int newBalance;

                    if (grid[i][j] == '(')
                        newBalance = balance - 1;
                    else
                        newBalance = balance + 1;

                    if (newBalance < 0 || newBalance > maxBalance)
                        continue;

                    // From top
                    if (i > 0 && dp[i - 1][j][newBalance])
                        dp[i][j][balance] = true;

                    // From left
                    if (j > 0 && dp[i][j - 1][newBalance])
                        dp[i][j][balance] = true;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};
