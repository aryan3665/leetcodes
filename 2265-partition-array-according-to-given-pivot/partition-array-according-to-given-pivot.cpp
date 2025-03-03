class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       vector<int> left, mid, right;

    for (int num : nums) {
        if (num < pivot) 
            left.push_back(num);
        else if (num == pivot) 
            mid.push_back(num);
        else 
            right.push_back(num);
    }

    vector<int> result;
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), mid.begin(), mid.end());
    result.insert(result.end(), right.begin(), right.end());

    return result;
    }
};