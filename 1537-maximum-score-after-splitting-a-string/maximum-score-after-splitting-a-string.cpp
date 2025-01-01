class Solution {
public:
int leftz(string s,int i){
    int c0=0;
    for(int j=0;j<=i;j++){
        if(s[j]=='0'){
      c0++;
        }
    }
    return c0;
}
int right1( string s,int k,int n){
    int c1=0;
    for(int l=k+1;l<n;l++){
        if(s[l]=='1'){
            c1++;
        }
    }
    return c1;
}
    int maxScore(string s) {
        int n=s.size();
        int maxi=-1;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,(leftz(s,i)+right1(s,i,n)));
        }

        return maxi;
    }
};