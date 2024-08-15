class Solution {
public:
    int n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool isValid(int i, int j) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    int dfs(int i, int j, int left, pair<int, int> dest, vector<vector<int>>& grid) {
        if (left == -1 && pair<int, int>(i, j) == dest) {
            return 1;
        }
        grid[i][j] =- 1;
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (isValid(x, y) && grid[x][y] != -1) {
                ans += dfs(x, y, left-1, dest, grid);
            }
        }
        grid[i][j] = 0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        pair<int, int> src, dest;
        int empty = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) empty++;
                if (grid[i][j] == 1) src = {i, j};
                if (grid[i][j] == 2) dest = {i, j};
            }
        }
        return dfs(src.first, src.second, empty, dest, grid);
    }
};