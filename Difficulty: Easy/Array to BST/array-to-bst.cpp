class Solution {
  public:
  Node* create(vector<int>& nums, int start, int end) {
      // base case
      if(start > end) return NULL;

      int mid = start + (end - start) / 2;
      Node* root = new Node(nums[mid]);

      root->left = create(nums, start, mid - 1);
      root->right = create(nums, mid + 1, end);

      return root;
  }

  Node* sortedArrayToBST(vector<int>& nums) {
      int n = nums.size();
      return create(nums, 0, n - 1);
  }
};
