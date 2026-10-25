
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        function<bool(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || j < 0 || i >= m || j >= n) {
                return false;
            }

            if (grid[i][j] == 1) {
                return true;
            }

            grid[i][j] = 1;

            bool a = dfs(i + 1, j);
            bool b = dfs(i - 1, j);
            bool c = dfs(i, j + 1);
            bool d = dfs(i, j - 1);

            return a && b && c && d;
        };

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(i, j)) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
