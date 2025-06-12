class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > size) {
                minHeap.pop();
            }
        }
    }

    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > size) {
            minHeap.pop();
        }
        return minHeap.top(); // kth largest
    }
};