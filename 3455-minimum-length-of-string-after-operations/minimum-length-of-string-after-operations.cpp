class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> charCount;

        // Count the frequency of each character
        for (char c : s) {
            charCount[c]++;
        }

        int ans=0;
        for(int i=0;i<charCount.size();i++){
            if(charCount[i]<=2){
                ans+=charCount[i];
            }
            else if(charCount[i]%2==0){
                ans+=2;
            }
            else {
                ans+=1;
            }
        }
        return ans;
    }
};