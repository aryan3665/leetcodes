class Solution {
public:
bool ispossible(long long m,int x){
    return m*m<=x;
}
    int mySqrt(int x) {
        long long low=1;
        long long high=x;
        long long ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(ispossible(mid,x)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};