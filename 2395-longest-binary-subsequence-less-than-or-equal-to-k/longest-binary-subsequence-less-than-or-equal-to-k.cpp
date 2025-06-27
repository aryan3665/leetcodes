class Solution {
public:
    int longestSubsequence(string s, int k) {
        int l=0;
        int power=1;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0')l++;
            else if(power*1<=k){
                l++;
                k=k-power;
            }
            if(power<=k){
                power*=2;
            }
            
        }
        return l;
    }
};