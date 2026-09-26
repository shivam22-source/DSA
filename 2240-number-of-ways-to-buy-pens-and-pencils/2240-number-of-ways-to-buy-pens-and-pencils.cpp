class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0;
    for(int i=0;i*cost1<=total;i++){
int rem=total-(i*cost1);
if(rem<0)return 1;
long long pencil=rem/cost2 +1;
ans+=pencil;
    }
    if(ans==0)return 1;
    return ans;

    }
};