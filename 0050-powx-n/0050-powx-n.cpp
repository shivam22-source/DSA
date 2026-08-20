class Solution {
public:

    double myPow(double x, int n) {
        long long N=n;
        if(n<0){
             N=-N;
            x=1/x;
        }
        
        double ans=1;
        while(N>0){
       if (N % 2 == 1)
            ans *= x;

            x*=x;
            N=N/2;
        }
        return ans;
    }
};