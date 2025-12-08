class Solution {
public:
    int countTriples(int n) {
        

        //a+b=c

        int count=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int sum=(i*i)+(j*j);
                for(int k=1;k<=n;k++){
                    if(sum==k*k)count++;
                }
            }
        }
        return count;
    }
};