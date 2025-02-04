class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            int childcount = 0;
            bool sameparentcount = false;
            
            // Iterate through the nodes at the current level
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Check left child
                if (node->left) {
                    if (node->left->val == x || node->left->val == y) {
                        childcount++;
                        if (node->left->val == x && node->right && node->right->val == y || 
                            node->left->val == y && node->right && node->right->val == x) {
                            sameparentcount = true;
                        }
                    }
                    q.push(node->left);
                }
                
                // Check right child
                if (node->right) {
                    if (node->right->val == x || node->right->val == y) {
                        childcount++;
                        if (node->left && node->left->val == x && node->right->val == y ||
                            node->left && node->left->val == y && node->right->val == x) {
                            sameparentcount = true;
                        }
                    }
                    q.push(node->right);
                }
                
                // If we find both nodes at the same level, return false if they're siblings
                if (sameparentcount) return false;
            }
            
            // If both nodes are found at the current level, return true
            if (childcount == 2) {
                return true;
            }
            
            // If only one of them is found, return false
            if (childcount == 1) {
                return false;
            }
        }
        
        return false;  // If we reach here, x and y are not cousins
    }
};
