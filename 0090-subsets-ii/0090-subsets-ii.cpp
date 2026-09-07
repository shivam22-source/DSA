class Solution {
public:
vector<vector<int>>arr;
void fun(int start,vector<int>&nums,vector<int>&curr){
    arr.push_back(curr);
    for(int i=start;i<nums.size();i++){
        if(i>start && nums[i-1]==nums[i])continue;

        curr.push_back(nums[i]);
        fun(i+1,nums,curr);
        curr.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        fun(0,nums,curr);
        return arr;
    }
};