class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1) return;
        int i = nums.size() - 2;
        while (i > 0 && nums[i + 1] <= nums[i]) --i;
        int j = nums.size() - 1;
        while (j > i && nums[j] <= nums[i]) --j;
        swap(nums[i], nums[j]);
        if(i == j) sort(nums.begin(), nums.end());
        else sort(nums.begin() + i + 1, nums.end());
    }
};