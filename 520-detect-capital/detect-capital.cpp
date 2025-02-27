class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        char a=word[0];
        char b=word[n-1];
        if((a>='A'&&a<='Z')&&(b>='A'&&b<='Z')){
            for(int i=1;i<n-1;i++){
                if(word[i]>='a'&&word[i]<='z'){
                    return false;
                }
            }
        }
        else if((a>='a'&&a<='z')&&(b>='a'&&b<='z')){

             for(int i=1;i<n-1;i++){
                if(word[i]>='A'&&word[i]<='Z'){
                    return false;
                }
            }

        }

        else if((a>='A'&&a<='Z')&&(b>='a'&&b<='z')){
             for(int i=1;i<n-1;i++){
                if(word[i]>='A'&&word[i]<='Z'){
                    return false;
                }
            }
        }

        else if((a>='a'&&a<='z')&&(b>='A'&&b<='Z')){
            return false;
        }

        return true;
    }
};