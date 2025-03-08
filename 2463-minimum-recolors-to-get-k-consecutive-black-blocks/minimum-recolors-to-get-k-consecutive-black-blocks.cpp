class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
       int i=0;
       int j=0;
       int op=k;

        int c = 0;
        while(j<n){
            if(blocks[j]=='W'){
                c++;
            }
            if((j-i+1)==k){
                op=min(op,c);
                if(blocks[i]=='W'){
                    c--;
                }
                i++;
            }
            j++;
        }
        return op;

      
        

   
    }
};
