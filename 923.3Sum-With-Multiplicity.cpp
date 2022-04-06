class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long long ans = 0, MOD = 1000000007;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); ++i){
            int remaining = target - arr[i];
            int l = i + 1, r = arr.size() - 1;
            while(l < r){
                if(arr[l] + arr[r] < remaining) ++l;
                else if(arr[l] + arr[r] > remaining) --r;
                else if(arr[l] != arr[r]){
                    int l_occ = 1, r_occ = 1;
                    while(l + 1 < r && arr[l] == arr[l + 1]){
                        ++l_occ;
                        ++l;
                    }
                    while(r - 1 > l && arr[r] == arr[r - 1]){
                        ++r_occ;
                        --r;
                    }
                    ans += (l_occ * r_occ);
                    ans %= MOD;
                    ++l;
                    --r;
                }
                else{
                    ans += ((r - l + 1) * (r - l) / 2);
                    ans %= MOD;
                    break;
                }
            }
        }
        return ans;
    }
};