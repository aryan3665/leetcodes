class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int count=0;
        int j=0;
        for(int i=0;i<players.size();i++){
            if(j>=trainers.size()) break;
            if(players[i]<=trainers[j]){
               count++;
               j++;
            }
            else{
                while(j<trainers.size() && players[i]>trainers[j]) j++;
                if(j!=trainers.size()) count++;
                j++;
            }
        }
        return count;
    }
};