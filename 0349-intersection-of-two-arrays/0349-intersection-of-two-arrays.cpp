class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(auto it:nums1){
            mp[it]++;
        }
        set<int>arr;
        for(auto it:nums2){
            if(mp.find(it)!=mp.end()){
                arr.insert(it);
            }
        }
       vector<int>nums(arr.begin(),arr.end());
        return nums;
    }
};