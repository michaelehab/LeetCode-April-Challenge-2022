class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector <int> scores;
        for(int i = 0; i < ops.size(); ++i){
            if(ops[i] == "+"){
                int score = scores[scores.size()- 1] + scores[scores.size()- 2];
                scores.push_back(score);
            }
            else if(ops[i] == "D") scores.push_back(2 * scores[scores.size()- 1]);
            else if(ops[i] == "C") scores.pop_back();
            else scores.push_back(stoi(ops[i]));
        }
        int ans = 0;
        for(const int &i : scores) ans += i;
        return ans;
    }
};