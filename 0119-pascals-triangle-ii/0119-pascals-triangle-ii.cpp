class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)return {1};
        vector<vector<int>>arr(rowIndex+1);
        for(int i=0;i<rowIndex+1;i++){
            vector<int>temp(i+1,1);
            arr[i]=temp;
            for(int j=1;j<i;j++){
arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
            }
        }
        return arr[rowIndex];
    }
};