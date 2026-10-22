class Solution {
public:
void fun(vector<int>& candidates,int start, int target,vector<vector<int>>&ans,vector<int>&current){
    if(target==0){
        ans.push_back(current);
        return;
    }
    for(int i=start;i<candidates.size();i++){
        if(i>start && candidates[i]==candidates[i-1])continue;
         if (candidates[i] > target)
        break;
        current.push_back(candidates[i]);
        fun(candidates,i+1,target-candidates[i],ans,current);
        current.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>current;
        fun(candidates,0,target,ans,current);
        return ans;
    }
};