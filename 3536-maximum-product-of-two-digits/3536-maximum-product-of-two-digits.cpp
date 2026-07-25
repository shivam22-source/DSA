class Solution {
public:
    int maxProduct(int n) {
        vector<int>no;
        int count=0;
        while(n>0){
            int x=n%10;
            n=n/10;
            no.push_back(x);
count++;
        }
        sort(no.begin(),no.end());
        return no.back()*no[count-2];
    }
};