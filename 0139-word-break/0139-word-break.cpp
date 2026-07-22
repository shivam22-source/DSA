class Solution {
public:
bool fun(string s,unordered_set<string>&mp,int st, vector<bool>& dp ){
    if (dp[st] == false) return false;
    int n=s.size();

    string temp;
    for(int i=st;i<n;i++){
        temp+=s[i];
        if(mp.find(temp)!=mp.end()){
            if(i==n-1)return true;

            if(i<n-1 && fun(s,mp,i+1,dp))return true;
        }
    }
    return dp[st]=false;

    
}
    bool wordBreak(string s, vector<string>& wordDict) {
          unordered_set<string> mp(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, true);
        return fun(s, mp, 0, dp);
    }
};