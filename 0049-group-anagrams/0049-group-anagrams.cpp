class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
       for(auto it:strs){
       vector<int>freq(26,0);
       for(auto ch:it)freq[ch-'a']++;

       string token; //use as a key
       for(auto it:freq){
        token+=to_string(it)+"#";
       }
        mp[token].push_back(it);
       } //"#1011##1100"->{["eat"],["ate"],["tea"]}
vector<vector<string>>res;
       for(auto it:mp){
        res.push_back(it.second); //["eat"],["ate"],["tea"]
       }
       return res;
    }
};