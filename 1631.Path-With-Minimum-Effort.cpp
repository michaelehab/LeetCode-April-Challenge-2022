// Dijkstra
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        int directions[5] = {-1, 0, 1, 0, -1};

        vector<vector<int>> efforts(rows, vector<int>(cols, INT_MAX));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.emplace(0, 0);
        while (!pq.empty()) {
          int effort = pq.top().first;
          int x = pq.top().second / 100, y = pq.top().second % 100;
          pq.pop();

          if (x == rows - 1 && y == cols - 1) return effort;
          if (effort >= efforts[x][y]) continue;
          efforts[x][y] = effort;

          for (int i = 0; i < 4; i++) {
            int new_x = x + directions[i], new_y = y + directions[i + 1];
            if (new_x < 0 || new_x >= rows || new_y < 0 || new_y >= cols) continue;
            int n_effort = max(effort, abs(heights[x][y] - heights[new_x][new_y]));
            pq.emplace(n_effort, new_x * 100 + new_y);
          }
        }
        return -1;
    }
};