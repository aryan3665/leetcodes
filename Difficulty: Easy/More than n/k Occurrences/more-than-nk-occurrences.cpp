class Solution {
  public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(vector<int>& arr, int k) {
                // Your code here
        unordered_map<int,int>map;
        for(auto i : arr) map[i]++;
        
        int ans = 0;
        for(auto i : map){
            if(arr.size()/k<i.second)
                ans++;
        }
        return ans;
    }
};