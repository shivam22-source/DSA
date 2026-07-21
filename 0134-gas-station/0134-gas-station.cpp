class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0,strt=0,curr=0,cos=0;
        int n=gas.size();

        for(int i=0;i<n;i++){
            total+=gas[i];
            cos+=cost[i];
            curr+=gas[i]-cost[i];

            if(curr<0){
                strt=i+1;
                curr=0;
            }
        }
        if(total<cos)return -1;
        return strt;
    }
};