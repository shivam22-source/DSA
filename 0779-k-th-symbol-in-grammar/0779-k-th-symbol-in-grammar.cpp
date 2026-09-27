class Solution {
public:
int flip(int x){
    if(x==0)return 1;
    return 0;
}
    int kthGrammar(int n, int k) {
        if(n==1)
        return 0;

        int len=1<<(n-1);//2^(n-1);
        int half=len/2;

       if(k<=half){
        return kthGrammar(n-1,k);
       }
       return flip(kthGrammar(n-1,k-half));
    }
};