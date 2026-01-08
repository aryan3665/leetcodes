class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //classical slidng window
        int i=0;
        int j=0;
        int maxi=INT_MIN;
        map<int,int>mp;
        while(j<fruits.size()){
        mp[fruits[j]]++;


while(mp.size()>2){
     if(mp[fruits[i]]==0){
        mp.erase(fruits[i]);
    }
    mp[fruits[i]]--;
    if(mp[fruits[i]]==0){
        mp.erase(fruits[i]);
    }
    i++;
}

        if(mp.size()<=2){
            maxi=max(maxi,j-i+1);
        }

        j++;
        }

        return maxi;
    }
};