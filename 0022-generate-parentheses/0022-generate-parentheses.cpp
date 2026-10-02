class Solution {
public:

void fun(int n,int open,int end,string &temp,vector<string>&res){
    if(open==n&&end==n){
        res.push_back(temp);
        return;
    }

    //open
    if(open<n){
        temp.push_back('(');
        fun(n,open+1,end,temp,res);
        temp.pop_back();
    }
    //close
    if(end<open){
         temp.push_back(')');
        fun(n,open,end+1,temp,res);
        temp.pop_back();
    }
    return;
}
    vector<string> generateParenthesis(int n) {
        string temp="";
       vector<string>res;
        fun(n,0,0,temp,res);
        return res;
    }
};