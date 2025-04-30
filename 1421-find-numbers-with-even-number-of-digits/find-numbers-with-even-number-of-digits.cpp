class Solution {
public:
    int findNumbers(vector<int>& nums) {
        

       int count_even_digits = 0;
    
    for (int i = 0; i < nums.size(); ++i) {
        int absolute_num = abs(nums[i]);
        
        int num_digits = 0;
        while (absolute_num > 0) {
            absolute_num /= 10;
            num_digits++;
        }
        
        if (num_digits % 2 == 0) {
            count_even_digits++;
        }
    }
    
    return count_even_digits;
}
};