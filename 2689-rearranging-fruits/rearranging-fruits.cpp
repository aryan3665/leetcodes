class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp;
        int mine1=INT_MAX;
        for(int&x:basket1){
            mp[x]++;
            mine1=min(mine1,x);
        }
        for(auto&x:basket2){
            mp[x]--;
            mine1=min(mine1,x);
        }

        vector<int>final;
        for(auto&it:mp){
            int cost=it.first;
            int count=it.second;
            if(count==0)continue;
            if(count%2!=0)return -1;
            for(int c=1;c<=abs(count)/2;c++){
                final.push_back(cost);
            }


        }
        sort(begin(final),end(final));
        long long result=0;
        for(int i=0;i<final.size()/2;i++){
            result+=min(final[i],mine1*2);
        }

        return result;
    }
};