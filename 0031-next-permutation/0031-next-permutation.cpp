class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int p=-1;   //{1,3,4,5,2}
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                p=i;
                break;
            }   //{1,3,4**,5,2}**->p
        }
        if(p==-1){
            reverse(nums.begin(),nums.end()); //pura hi reverse
            return;
        }
        for(int i=n-1;i>=p+1;i--){  //[1,3,4**,5*,2*] 2,5 ko hi iterate mean gola ** k baad wala m just greater ellment
            if(nums[p]<nums[i]){
                swap(nums[p],nums[i]);  //[1,3,5**,4*,2*]
                break;
            }
        }
 reverse(nums.begin()+p+1,nums.end()); //[1,3,5**,2*,4*]

    }
};