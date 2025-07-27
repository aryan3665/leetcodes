class Solution {
public:
void paren(int n,int l,int r,vector<string>&ans,string&temp){
if(l==n&&r==n){
    ans.push_back(temp);
    return;
}


    //left parent
    if(l<n){
        temp.push_back('(');
        paren(n,l+1,r,ans,temp);
        temp.pop_back();
    }
//right
    if(r<l){
        temp.push_back(')');
        paren(n,l,r+1,ans,temp);
        temp.pop_back();
    }

}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        paren(n,0,0,ans,temp);
        return ans;
    }
};