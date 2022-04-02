class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end && s[start] == s[end]) {
            ++start;
            --end;
        }
        
        if (start >= end) return true;
        
        int i = start + 1;
        int j = end;
        while (i < j && s[i] == s[j]) {
            ++i;
            --j;
        }
        
        if (i >= j) return true;
        
        i = start;
        j = end - 1;
        while (i < j && s[i] == s[j]) {
            ++i;
            --j;
        }
                
        return i >= j;
    }
};