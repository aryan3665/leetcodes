class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> p;
        for(int i=0;i<k;i++){
            p.push(nums[i]);

        }
        for(int i=k;i<nums.size();i++){
            if(p.top()<=nums[i]){
                p.pop();
                p.push(nums[i]);
            }
        }

        return p.top();
     
    }
};