class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> ans;
        unordered_map <int,int> freq;
        // Min Heap
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> topK;
        
        for(int i = 0; i < nums.size(); i++) freq[nums[i]]++;
        
        for(auto i : freq){
            topK.push({i.second, i.first});
            if(topK.size() > k) topK.pop();
        }
        
        while(topK.size() > 0){
            ans.push_back(topK.top().second);
            topK.pop();
        }
        
        return ans;
    }
};