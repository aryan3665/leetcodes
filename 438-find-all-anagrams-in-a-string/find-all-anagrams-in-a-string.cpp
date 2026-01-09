class Solution {
public:

bool allzero(vector<int>&fre,string p){
    for(int i=0;i<p.size();i++){
        if(fre[p[i]-'a']!=0)return false;
    }
    return true;
}
    vector<int> findAnagrams(string s, string p) {
        int k=p.size();
        vector<int>fre(26,0);
        for(int i=0;i<k;i++){
            fre[p[i]-'a']++;
        }
        int i=0;
        int j=0;
        vector<int>ans;
        while(j<s.size()){
            fre[s[j]-'a']--;

            if(j-i+1==k){
                if(allzero(fre,p)){
                    ans.push_back(i);
                }

            
                fre[s[i]-'a']++;
                    i++;
            }
            j++;
        }

        return ans;
    }
};