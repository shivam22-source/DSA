class Solution {
public:
    int fib(int n) {
        //tabulation with litttle optimisation with space
        if(n==1)return 1;
        if(n==0)return 0;
      int prev=1,prev_prev=0;
      int curr=0;
        for(int i=2;i<=n;i++){
           curr=prev+prev_prev;
            prev_prev=prev;
            prev=curr;
        }
        return curr;
    }
};