class Solution {
public:
    string smallestPalindrome(string s) {
        map<char, int> v;
    
        for (auto it : s) {
            v[it]++;
        }
        string ans;
        string mid;
        for (auto it : v) {

            int count = it.second;
            if (count == 0)
                continue;
            if (count % 2 == 0) {
                int r = count / 2;
                while (r--) {
                    ans += it.first;
                }
            }
            if (count % 2 != 0) {
                int r = count / 2;
                while (r--) {
                    ans += it.first;
                }
                mid += it.first;
            }
        }
    
    string rev;
rev=ans;

    reverse(rev.begin(), rev.end());
    ans = ans + mid + rev;
    return ans;
}
};
