class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> mp;
        if (bills[0] == 10 || bills[0] == 20)
            return false;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                mp[5]++;
            } else if (bills[i] == 10) {
                if (mp[5] != 0) {
                    mp[10]++;
                    mp[5]--;
                } else {
                    return false;
                }
            } else if (bills[i] == 20) {
                if (mp[10] >= 1 && mp[5] >= 1) {
                    mp[20]++;
                    mp[5]--;
                    mp[10]--;
                } 
                else if(mp[10]==0&&mp[5]>=3){
                    mp[20]++;
                    mp[5]-=3;
                }
                    else {
                    return false;
                }
            }
        }
        return true;
    }
};