class Solution {
public:
    int countVowelSubstrings(string word) {
        int n=word.size();
        int count=0;
        for(int i=0;i<n;i++){
            set<int>st;
            for(int j=i;j<n;j++){
                 if (word[j] != 'a' && word[j] != 'e' &&
                    word[j] != 'i' && word[j] != 'o' &&
                    word[j] != 'u') {
                    break;
                }
                st.insert(word[j]);
                if(st.size()==5)count++;
            }
        }
        return count;
    }
};