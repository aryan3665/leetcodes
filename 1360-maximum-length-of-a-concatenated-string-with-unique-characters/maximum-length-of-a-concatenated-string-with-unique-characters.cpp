class Solution {
public:
    bool hasMatch(const string &a, const string &b) {
        vector<int> freq(26, 0);
        for (char c : b) {
            if (freq[c - 'a']++) return true; // duplicate in b
        }
        for (char c : b) {
            if (a.find(c) != string::npos) return true; // common char with a
        }
        return false;
    }

    int solve(vector<string>& arr, int i, string temp) {
        if (i == arr.size()) {
            return temp.size();
        }

        int exclude = solve(arr, i + 1, temp);

        int include = 0;
        if (!hasMatch(temp, arr[i])) {
            include = solve(arr, i + 1, temp + arr[i]);
        }

        return max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        return solve(arr, 0, "");
    }
};
