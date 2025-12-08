class Solution {
public:
    int countTriples(int n) {
        vector<int>vahiyat;
        for(int i=1;i<=n;i++){
            vahiyat.push_back(i*i);
        }

        //a+b=c

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=vahiyat[i]+vahiyat[j];
                for(int k=0;k<n;k++){
                    if(sum==vahiyat[k])count++;
                }
            }
        }
        return count;
    }
};