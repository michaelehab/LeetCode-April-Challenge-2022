class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans (n, vector<int>(n));
        int num = 1;
        for (int i = 0; i < (n + 1) / 2; ++i) {
            for (int j = i; j < n - i; ++j) ans[i][j] = num++;

            for (int j = i + 1; j < n - i; ++j) ans[j][n - i - 1] = num++;

            for (int j = n - i - 2; j >= i; --j) ans[n - i - 1][j] = num++;

            for (int j = n - i - 2; j > i; --j) ans[j][i] = num++;
        }

        return ans;
    }
};