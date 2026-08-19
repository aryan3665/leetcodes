class Solution {
public:

    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>mp;
        for(auto&it:reservedSeats){
            int row=it[0];
            int seat=it[1];
            mp[row].insert(seat);
        }

        int empty=n-mp.size();
        int result=0;
        result+=empty*2;

        for(auto&[row,bookedseats]:mp){
            auto isavilable=[&](int seat){
                return bookedseats.find(seat)==bookedseats.end();
            };
            bool ga=isavilable(2)&&isavilable(3)&&isavilable(4)&&isavilable(5);
              bool gb=isavilable(4)&&isavilable(5)&&isavilable(6)&&isavilable(7);
                bool gc=isavilable(6)&&isavilable(7)&&isavilable(8)&&isavilable(9);


                if(ga&&gc){
                    result+=2;
                }
                else if(ga||gb||gc){
                    result+=1;
                }
        }

        return result;
    }
};