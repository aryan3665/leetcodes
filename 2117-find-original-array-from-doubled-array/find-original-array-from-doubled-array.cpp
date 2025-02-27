class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
       if (changed.size() % 2 != 0) return {}; // If the length is odd, return empty

    sort(changed.begin(), changed.end()); // Sort the array
    unordered_map<int, int> freq; // Frequency map
    vector<int> original;

    // Count the frequency of each element
    for (int num : changed) {
        freq[num]++;
    }

    // Process each element
    for (int num : changed) {
        if (freq[num] == 0) continue; // Skip if already used
        if (freq[num * 2] == 0) return {}; // If double not found, return empty

        original.push_back(num);
        freq[num]--;      // Decrease frequency of the number
        freq[num * 2]--;  // Decrease frequency of its double
    }

    return original;
    }
};