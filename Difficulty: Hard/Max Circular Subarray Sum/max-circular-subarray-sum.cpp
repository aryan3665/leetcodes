class Solution {
    void build(int x, int lx, int rx, vector<int> &prefix, vector<int> &seg) {
        if(rx - lx == 1) {
            if(lx < prefix.size()) seg[x] = prefix[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m, prefix, seg);
        build(2 * x + 2, m, rx, prefix, seg);
        
        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
    }
    int query(int x, int lx, int rx, int l, int r, vector<int> &seg) {
        if(rx <= l || lx >= r) return INT_MIN;
        if(lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        int a = query(2 * x + 1, lx, m, l, r, seg);
        int b = query(2 * x + 2, m, rx, l, r, seg);
        return max(a, b);
    }
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n = arr.size(), s = 1, ans = INT_MIN;
        vector<int> prefix(2 * n, 0);
        for(int i = 0, s = 0; i < 2 * n; i++) {
            s += arr[i % n];
            prefix[i] = s;
        }
        for(; s < 2 * n; s *= 2) {}
        vector<int> seg(2 * s, INT_MIN);
        build(0, 0, s, prefix, seg);
        for(int i = 0; i < n; i++) {
            ans = max(ans, query(0, 0, s, i, i + n, seg) - ((i - 1 >= 0) ? prefix[i - 1] : 0));
        }
        return ans;
    }
};