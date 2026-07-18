class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
       for(auto it:strs){
        string temp=it;
        sort(temp.begin(),temp.end());
        mp[temp].push_back(it);
       } //["aet"]->{["eat"],["ate"],["tea"]}
vector<vector<string>>res;
       for(auto it:mp){
        res.push_back(it.second); //["eat"],["ate"],["tea"]
       }
       return res;
    }
};