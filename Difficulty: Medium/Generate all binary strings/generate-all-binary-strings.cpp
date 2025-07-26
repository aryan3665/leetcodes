// User function Template for C++

class Solution {
  public:
void stringRecur(int i, string &s, vector<string> &ans) {
    
    // Base case: If we've filled all positions,
    // add the string to results
    if (i >= s.length()) {
        ans.push_back(s);
        return;
    }
    
    // Case 1: Keep the current position as 
    // '0' and move to next position
    stringRecur(i+1, s, ans);
    
    // Case 2: Try placing '1' at current position. 
    // Skip the next position when we place a '1' 
    // to avoid consecutive 1's
    s[i] = '1';
    
    // Skip next position to avoid consecutive 1's
    stringRecur(i+2, s, ans);  
    
    // Backtrack: Restore the current position back to '0'
    s[i] = '0';
}
    vector<string> generateBinaryStrings(int n) {
    
    // Initialize a string of n zeros 
    // as our starting point
    string s(n, '0');
    
    vector<string> ans;
    
    stringRecur(0, s, ans);
    
    return ans;
}

};