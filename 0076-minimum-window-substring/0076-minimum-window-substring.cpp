class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> mp;
        for (auto it : t)
            mp[it]++;

        int count = t.size();
        int Min = INT_MAX; // min size
        int low = 0;

        int i = 0, j = 0;
        while (j < s.size()) {
            if (mp[s[j]] > 0) {
                count--;
            }
            mp[s[j]]--;
            while (count == 0) {
                int size = j - i + 1;
                if (Min > size) {
                    Min = size;
                    low = i;
                }

                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    count++;
                }
                i++;
            }
            j++;
        }

        if (Min == INT_MAX)
            return "";
        return s.substr(low, Min);
    }
};