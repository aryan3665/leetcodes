class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        // we can tak card from start or end agar hamm k cared le sakte hai to n-k card nhi le sakte hai na 
        int total=0;
        int n=c.size();
        for(int i=0;i<n;i++){
            total+=c[i];
        }

   if((n-k)==0)return total;
        //minimum sum nbikal lenge of size n-k 
        int i=0;
        int j=0;
        int s=0;
        int mins=INT_MAX;
        while(j<n){
            s+=c[j];
            if((j-i+1)==(n-k)){
                mins=min(mins,s);
                s-=c[i];
                i++;
            }

            j++;
        }



        return total-mins;

    }
};