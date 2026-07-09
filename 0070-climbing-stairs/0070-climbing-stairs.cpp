class Solution {
public:
//tabulation
    int climbStairs(int n) {
        int last=0;
        int last_s=1;
        int ans=0;
        for(int i=n-1;i>=0;i--){
             ans=last+last_s;
            last=last_s;
            last_s=ans;
        }
return ans;
    }
};