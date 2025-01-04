class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_set<char >letters;
        for(int i=0;i<n;i++){
            letters.insert(s[i]);
        }

        int result=0;
        for(char letter:letters){
            int first=-1;
            int last=-1;
            for(int i=0;i<n;i++){
                if(s[i]==letter){
                    if(first==-1){
                        first=i;
                    }

                    last=i;
                }
            }



        unordered_set<char>st;
        for(int middle=first+1;middle<=last-1;middle++){
            st.insert(s[middle]);
        }
           result+=st.size();
        }

       
     

        return result;
    }
};