class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        set<int> st(begin(nums),end(nums));
        // sort(begin(nums),end(nums));
        for(auto i:st){
            if(i!=0) cnt++;
        }
        return cnt;
    }
};

