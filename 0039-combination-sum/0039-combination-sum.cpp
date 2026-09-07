class Solution {
public:

void fun(int idx, vector<int>&nums, int sum,int target,vector<int>&diary,vector<vector<int>>&arr){
    if(idx==nums.size()){
        if(sum==target){
            arr.push_back(diary);
        }
            return;
    }

         fun(idx+1,nums, sum, target, diary,arr);
   

    if(sum+nums[idx]<=target){
    diary.push_back(nums[idx]);
    sum+=nums[idx];
    fun(idx,nums, sum, target, diary,arr);
    diary.pop_back();
    sum-=nums[idx];
    }
    return;
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //your code goes here
        vector<int>diary;
        int sum=0;
        vector<vector<int>>arr;
        sort(candidates.begin(),candidates.end());
        fun(0,candidates,sum,target,diary,arr);
        return arr;
    }
};