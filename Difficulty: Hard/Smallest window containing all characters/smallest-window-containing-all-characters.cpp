class Solution {
  public:
    string smallestWindow(string &s, string &t) {
        // code here
       int n = s.size();
        int m = t.size();
        if (m > n) return "";

        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;

        int need = m;
        int i = 0, j = 0;
        int minwindowsize = INT_MAX;
        int start_i = 0;

        while (j < n) {
            char ch = s[j];
            if (mp[ch] > 0) need--;   // we found a needed char
            mp[ch]--;                 // consume it

            // shrink while window is valid
            while (need == 0) {
                int currentwindow = j - i + 1;
                if (currentwindow < minwindowsize) {
                    minwindowsize = currentwindow;
                    start_i = i;
                }

                mp[s[i]]++;
                if (mp[s[i]] > 0) {   // we lost a required char
                    need++;
                }
                i++;
            }
            j++;
        }

        if (minwindowsize == INT_MAX) return "";
        return s.substr(start_i, minwindowsize);
    }
};