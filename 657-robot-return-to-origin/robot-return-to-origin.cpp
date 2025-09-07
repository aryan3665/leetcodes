class Solution {
public:
    bool judgeCircle(string moves) {
           int x = 0, y = 0;  // x for left/right, y for up/down

    for(char move : moves) {
        if(move == 'U') y++;
        else if(move == 'D') y--;
        else if(move == 'L') x--;
        else if(move == 'R') x++;
    }

    // Robot returns to origin if both coordinates are 0
    return x == 0 && y == 0;
    }
};