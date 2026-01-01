class Solution {
public:
bool ispossible(vector<int>&dist,double hour,int mid){
    double sum=0;
    for(int i=0;i<dist.size()-1;i++){
        sum+=ceil(double(dist[i])/mid);
    }
   sum += (double)dist.back() / mid;


    return sum<=hour;
}
    int minSpeedOnTime(vector<int>& dist, double hour) {
       int l=1;
       int r=10e7;
       int ans=-1;
       while(l<=r){
        int mid=l+(r-l)/2;
        if(ispossible(dist,hour,mid)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
       }
       return ans; 
    }
};