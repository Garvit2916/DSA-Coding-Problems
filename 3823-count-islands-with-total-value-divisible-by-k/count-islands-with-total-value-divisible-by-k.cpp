
class Solution {
public:
    int m, n;
    vector<vector<int>>* g;
    vector<vector<bool>> vis;

    long long dfs(int r, int c) {
        if (r < 0 || r >= m || c < 0 || c >= n ||
            vis[r][c] || (*g)[r][c] == 0) {
            return 0;
        }

        vis[r][c] = true;

        long long sum = (*g)[r][c];

        sum += dfs(r + 1, c);
        sum += dfs(r - 1, c);
        sum += dfs(r, c + 1);
        sum += dfs(r, c - 1);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        g = &grid;

        vis.assign(m, vector<bool>(n, false));

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    long long sum = dfs(i, j);

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};
