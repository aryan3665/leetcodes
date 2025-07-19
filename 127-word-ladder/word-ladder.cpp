class Solution {
public:
    int ladderLength(string start, string end, vector<string>& bank) {
        unordered_set<string> bankst(bank.begin(), bank.end());
        if (bankst.find(end) == bankst.end()) return 0;  // early exit

        unordered_set<string> visited;
        queue<string> q;
        q.push(start);
        visited.insert(start);
        int l = 0;

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string temp = q.front();
                q.pop();
                if (temp == end)
                    return l + 1;  // fix here

                for (char ch : "abcdefghijklmnopqrstuvwxyz") {
                    for (int i = 0; i < temp.size(); i++) {
                        string neighbour = temp;
                        neighbour[i] = ch;

                        if (bankst.find(neighbour) != bankst.end() &&
                            visited.find(neighbour) == visited.end()) {
                            visited.insert(neighbour);
                            q.push(neighbour);
                        }
                    }
                }
            }
            l++;
        }

        return 0;
    }
};
