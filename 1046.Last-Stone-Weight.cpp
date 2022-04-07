class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> tmp(stones.begin(),stones.end());
        while(tmp.size() > 1){
            int heaviest = tmp.top();
            tmp.pop();
            int heaviest2 = tmp.top();
            tmp.pop();
            tmp.push(heaviest - heaviest2);
        }
        return tmp.top();
    }
};