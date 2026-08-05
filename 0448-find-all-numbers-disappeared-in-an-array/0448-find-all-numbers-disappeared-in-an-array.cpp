class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        unordered_map<int,int>fq;
        for(auto it:nums){
            fq[it]++;
        }
        for(int i=1;i<=n;i++){
            if(fq.find(i)==fq.end()){
                res.push_back(i);
            }
        }
        return res;
    }
};