class Solution {
public:
    long long tree[500]; 
    void update(int n, int l, int r, long long val, int idx){
        if(l==r){
            if(idx == l) tree[n] = val; 
        }
        else{
            int m = (l+r)/2; 
            
            if (idx <= m) update(2*n, l, m, val, idx); 
            else update(2*n+1, m+1, r, val, idx); 

            tree[n] = min(tree[2*n], tree[2*n+1]); 
        }
    }

    pair<int, long long> find(int n, int l, int r, int val){
        if(l == r) return {l, tree[n]}; 
        else{
            int m =(l+r)/2; 
            if(tree[n] > val){
                // have to wait, return earlist available 
                if(tree[2*n] <= tree[2*n+1]) return find(2*n, l, m, val); 
                else return find(2*n+1, m+1, r, val); 
            }
            if(tree[2*n] <= val) return find(2*n, l, m, val); 
            else return find(2*n+1, m+1, r, val); 
        }
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> use_count(n+1); 
        memset(tree, 0, sizeof(tree)); 

        sort(meetings.begin(), meetings.end()); 

        for(int i=0 ; i<meetings.size() ; i++){
            auto [idx, free_time] = find(1, 0, n-1, meetings[i][0]); 
            // cout << idx <<" "<< free_time << endl; 
            if(free_time <= meetings[i][0]){
                update(1, 0, n-1, meetings[i][1], idx); 
            }
            else{
                long long duration = meetings[i][1] - meetings[i][0]; 
                update(1, 0, n-1, duration + free_time, idx); 
            }

            use_count[idx]++; 
        }

        int ans = 0; 
        for(int i=0 ; i<n ; i++){
            if(use_count[ans] < use_count[i]) ans = i; 
        }
        return ans; 
    }
};