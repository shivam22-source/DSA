class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>v;
        vector<int>last_occ(26);
      for(int i=0;i<s.size();i++){
        last_occ[s[i]-'a']=i;
      }
        
        int strt=0,end=0;
        for(int i=0;i<s.size();i++){
end=max(end,last_occ[s[i]-'a']);
if(i==end){
    v.push_back(end-strt+1);
    strt=i+1;
}
        }
        return v;
    }
};