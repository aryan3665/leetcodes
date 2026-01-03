class Solution {
public:
 int M = 1e9 + 7;
 vector<vector<int>>t;
        string states[12] = {"ryr", "ryg", "rgr","rgy","yry", "yrg","ygr", "ygy", "grg", "gry", "gyr", "gyg"};
int solve(int n,int prev){
    if(n==0)return 1;

    if(t[n][prev]!=-1){
        return t[n][prev];
    }
    int result=0;
    string last=states[prev];

    for(int curr=0;curr<12;curr++){
        if(curr==prev)continue;

        string currpat=states[curr];
        bool conflict=false;

        for(int col=0;col<3;col++){
            if(currpat[col]==last[col]){
                conflict=true;
                break;
            }
        }

        if(!conflict){
            result=(result+solve(n-1,curr))%M;
        }
    }

    return t[n][prev]= result;
}
    int numOfWays(int n) {
        // it is a kind of trying all ways with memoization
int result=0;
t.resize(n,vector<int>(12,-1));
        for(int i=0;i<12;i++){//choosing 1st row
        result=(result+solve(n-1,i))%M;

        }
        return result;
       
        
    }
};