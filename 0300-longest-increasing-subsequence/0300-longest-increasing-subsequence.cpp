class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //tabulation
        int n=nums.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    res[i]=max(res[i],res[j]+1);
                }
            }
        }
        int m=INT_MIN;
        for(int i=0;i<n;i++){
            m=max(m,res[i]);
        }
        return m;
    }
};