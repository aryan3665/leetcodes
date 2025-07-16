class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int a=0,b=0,c=0,d=0,req1=0,req2=1,rem;
        for(auto i:nums){
            rem=i%2;
            if(rem==0)
            a++;
            if(rem==1)
            b++;
            if(rem==req1){
                c++;
                req1=req1^1;
            }
            if(rem==req2){
                d++;
                req2=req2^1;
            }
        }
        return(max(a,max(b,max(c,d))));
    }
};