class Solution {
public:
    int maximumCount(vector<int>& nums) {


        auto lambdap=[](int num){
            return num>0;
        };
         auto lambdan=[](int num){
            return num<0;
        };
       int countpo=count_if(begin(nums),end(nums),lambdap);
        int countneg=count_if(begin(nums),end(nums),lambdan);
        return max(countpo,countneg);

    }
};