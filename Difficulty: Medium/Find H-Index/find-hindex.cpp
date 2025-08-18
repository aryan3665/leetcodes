// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // code here
sort(citations.begin(), citations.end(), greater<int>());

    int n = citations.size();
    int idx = 0;

    // Keep incrementing idx till citations[idx] > idx
    while(idx < n && citations[idx] > idx) {
        idx += 1;
    }
    return idx;
    }
};
