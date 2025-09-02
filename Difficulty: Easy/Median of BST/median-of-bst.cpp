void inorder(Node* root, vector<int> &arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

float findMedian(Node *root) {
    vector<int> arr;
    inorder(root, arr);
    int n = arr.size();

    if (n % 2 == 1) {
        return arr[n/2];  // odd length
    } else {
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;  // even length
    }
}
