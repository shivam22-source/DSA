class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=2*nums.size();
        vector<int>ans;
        int i=0;
       while(i<n){
        if(i<n/2){
            ans.push_back(nums[i]);

        }
        else {
            ans.push_back(nums[i-(n/2)]);
        }
        i++;
       }
       return ans;
    }
};