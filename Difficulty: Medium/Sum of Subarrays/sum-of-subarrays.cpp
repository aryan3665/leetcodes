class Solution {
  public:
    int subarraySum(vector<int>& arr) {
    int sum = 0 ,cnt = 0;
        for(int i = 0;i < arr.size();i++){
            cnt = (i + 1) * (arr.size() - i);
            sum += arr[i] * cnt;
        }
        return sum;
    }
};