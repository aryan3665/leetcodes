class Solution {
    // एरे के एक हिस्से को रिवर्स (उल्टा) करने के लिए हेल्पर मेथड
    public void reverse(int[] arr, int start, int end) {
        while (start <= end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    // एरे को k स्टेप्स दाईं ओर (right) रोटेट करने का मुख्य मेथड
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n; // यदि k का मान एरे की लंबाई से बड़ा हो
        
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
}
