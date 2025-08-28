class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int i = 0, zeros = 0, maxLen = 0;

    for (int j = 0; j < arr.size(); j++) {
        if (arr[j] == 0) 
            zeros++;

        while (zeros > k) {
            if (arr[i] == 0) 
                zeros--;
            i++;
        }

        maxLen = max(maxLen, j - i + 1);
                                                                                                                                                                                                                                                                                                                                                          
    }
    return maxLen;
    
    }
    
};
