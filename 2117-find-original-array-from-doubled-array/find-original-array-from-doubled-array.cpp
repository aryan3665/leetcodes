class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
         sort(changed.begin(), changed.end());  
    vector<int> original;
    
    while (!changed.empty()) {
        int num = changed[0];  
        auto it = find(changed.begin() + 1, changed.end(), num * 2);  // Find its double
        
        if (it != changed.end()) {  // If found
            original.push_back(num);
            changed.erase(it);  // Remove the double
            changed.erase(changed.begin());  // Remove the original number
        } else {
            return {};  // If no valid pair is found, return empty array
        }
    }
    
    return original;
    }
};