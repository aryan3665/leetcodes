class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
      
        const int MOD = 1e9 + 7; 
       
       vector<int>pre(n,0);
       pre[0]=arr[0];
       for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+arr[i];
    }
    int count=0;
    int odd=0;
    int even=1;
    for(int i=0;i<n;i++){
        if(pre[i]%2==0){
            count=(count+odd)%MOD;
            even++;
        }
        else{
            count=(count+even)%MOD;
            odd++;
        }
    }
    return count;

    }
};
