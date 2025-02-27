class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
       if (changed.size() % 2 != 0) return {}; // If odd length, return empty

    sort(changed.begin(), changed.end()); // Step 1: Sort the array
    queue<int> q; // Queue to track elements needing a pair
    vector<int> original;

    for (int num : changed) {
        if (!q.empty() && q.front() * 2 == num) {
            q.pop(); // Found a pair, remove from queue
        } else {
            q.push(num); // Push element needing a pair
            original.push_back(num);
        }
    }

    return q.empty() ? original : vector<int>{}; // If pairs are complete, return original
}
};