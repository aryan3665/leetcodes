class Solution {
	public:
	const int MOD = 1e9 + 7;
	
	int maxAmount(vector<int>& arr, int k) {
		priority_queue<int> pq;
		for (int x : arr)
			pq.push(x);
		
		long long ans = 0;
		
		while (k-- && !pq.empty() && pq.top() > 0) {
			int x = pq.top();
			pq.pop();
			
			ans = (ans + x) % MOD;
			
			pq.push(x - 1);
		}
		
		return ans;
	}
};
