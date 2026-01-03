class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int n = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            // right side me even hai ya odd hai
            bool iseven;
            if ((r - mid) % 2 == 0)
                iseven = true;
            else
                iseven = false;
            if (nums[mid] == nums[mid + 1]) {
                if (iseven) {
                    l = mid + 2;
                } else {
                    r = mid - 1;
                }

            }

            else {

                if(iseven){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
            }
        }
        return nums[r];
    }
};