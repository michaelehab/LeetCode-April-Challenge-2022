class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> category(n);

        queue<int> q; // 1 or -1

        for (int i = 0; i < n; ++i) {
          if (category[i]) continue;
          category[i] = 1;
          for (q.push(i); !q.empty(); q.pop()) {
            int curr = q.front();
            for (int neighbor : graph[curr]) {
              if (!category[neighbor]){ 
                  category[neighbor] = -1 * category[curr]; 
                  q.push(neighbor); 
              } 

              else if (category[neighbor] == category[curr]) return false;
            }        
          }
        }

        return true;
    }
};