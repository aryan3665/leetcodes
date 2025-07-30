class Solution {
public:
    int lengthOfLastWord(string s) {
        int r=s.length()-1;
        while(r>=0 && s[r]==' ')
        {
            r--;
        }
        int count=0;
        for(int i=r;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                count++;
            }
            else
            return count;
        }
        return count;
    }
};