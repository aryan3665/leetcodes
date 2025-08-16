class Solution {
public:
    int maximum69Number (int num) {
        int placevalue=-1;
        int c=0;
        int n=num;
   
        while(n>0){
           int  rem=n%10;
           if(rem==6){
            placevalue=c;
           }
           n=n/10;
            c++;
        }
        if(placevalue==-1){
            return num;
        }
        else{
            return num+3*pow(10,placevalue);
        }
    }
};
