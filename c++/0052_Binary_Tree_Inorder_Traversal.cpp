/* Given the root of a binary tree, return the inorder traversal of its nodes' values.*/

// Solution :-

class Solution {
private:
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        inorder(root->left, result);   // Visit Left Subtree
        result.push_back(root->val);  // Visit Node
        inorder(root->right, result);  // Visit Right Subtree
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};