class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
       int n = arr.size();
    int i = 0;
    
    // Find index of element just less than x
    while (i < n && arr[i] < x) i++;
    int left = i - 1, right = i;
    
    // If value at right index is x, increment 
    if (arr[right] == x) right++;
    
    vector<int> res;
    
    while (left >=0 && right < n && res.size() < k) {
        int leftDiff = abs(arr[left] - x);
        int rightDiff = abs(arr[right] - x);
        
        if (leftDiff < rightDiff) {
            res.push_back(arr[left]);
            left--;
        }
        else {
            res.push_back(arr[right]);
            right++;
        }
    }
    
    // If k elements are not filled 
    while (left >=0 && res.size() < k) {
        res.push_back(arr[left]);
        left--;
    }
    
    while (right < n && res.size() < k) {
        res.push_back(arr[right]);
        right++;
    }
    
    return res;
    }
};