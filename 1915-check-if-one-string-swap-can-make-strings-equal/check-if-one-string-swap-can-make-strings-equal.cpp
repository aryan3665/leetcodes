class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
       int count=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                count++;
            }
        }
       map<char,int>m1;
       map<char,int>m2;
       for(int i=0;i<n;i++){
        m1[s1[i]]++;
        m2[s2[i]]++;
       }
       bool flag=1;

        for (auto &[key, value] : m1) {
        if (m2[key] != value) flag=0;; // Check if value is different for any key
    }

    if(flag==0){
        return false;
    }
    else if(count>2){
        return false;
    }
    else if(count==1){
        return false;
    }

    return true;
    }
};