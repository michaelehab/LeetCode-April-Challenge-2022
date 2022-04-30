class Solution {
public:
    void dfs (unordered_map <string, vector<pair<string, double>>> &mp, string s, string d, double& ans, unordered_map <string, int> &visited, double tmp) {
        if (visited.count(s)) return;
        visited[s] = 1;
        if (s == d) {
            ans = tmp; 
            return;
        }
        
        for (auto x: mp[s]) dfs(mp, x.first, d, ans, visited, tmp*x.second);
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map <string, vector<pair<string, double>>> mp;
        
        //Build Graph
        for (int i = 0; i < equations.size(); i++){
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
        
        //DFS 
        vector <double> result;
        for (int i = 0; i < queries.size(); i++){
            string src = queries[i][0];
            string dst = queries[i][1];
            double ans = -1.0;
            unordered_map <string, int> visited;
            if (mp.count(src)) dfs (mp, src, dst, ans, visited, 1.0);
            result.push_back(ans);
        }
        return result;
    }
};