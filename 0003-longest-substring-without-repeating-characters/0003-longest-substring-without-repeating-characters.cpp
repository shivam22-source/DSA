class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int high = 0;
        int k = 0;
        int res=INT_MIN;
        unordered_map<char, int> mp;
        int n = s.size();
        while (high < n) {
            mp[s[high]]++;
            k = high - low + 1;
            while (mp.size() < k) {
                mp[s[low]]--;
                if (mp[s[low]] == 0)
                    mp.erase(s[low]);
              
                low++;
                  k = high - low + 1;
            }
            if (k == mp.size()) {
                res = max(res, k);
            }
            high++;
        }
        if(res==INT_MIN)return 0;
        return res;
    }
};