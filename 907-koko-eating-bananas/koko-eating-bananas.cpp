class Solution {
public:
bool ispossible(int m,vector<int>&piles,int h){
    long long total=0;
    for(int i=0;i<piles.size();i++){
        total+=(piles[i] + m - 1) / m;
    }
    return total<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int maxi=*max_element(piles.begin(),piles.end());
        int hi=maxi;
        int ans=hi;
        while(l<=hi){
            int mid=l+(hi-l)/2;
            if(ispossible(mid,piles,h)){
                ans=mid;
                hi=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};