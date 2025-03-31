class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
        treedepth(root, dia);
        return dia;
    }
    int treedepth(TreeNode* root, int& dia){
        if(root==NULL) return 0;
        int countL = treedepth(root->left, dia);
        int countR = treedepth(root->right, dia);
        dia = max(dia, countL+countR);
        return max(countL, countR) + 1;
    }
};