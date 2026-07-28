/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private:
        int height( TreeNode *root){ 
            // base case
            if ( root == NULL) return 0;
            int ans =0;
            int left = height( root -> left);  // left subtree
            int right = height( root -> right);  // right subtree
            ans = max( left, right)+1; // +1 for root node
            return ans;
        }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        //base case
        if ( root== NULL) return 0;
        int ans =0;

        //recursive relations
         int op1 = diameterOfBinaryTree( root -> left); //left subtree when right is null
         int op2 = diameterOfBinaryTree( root ->right); //right subtree when left is null
         int op3 = height(root->left) + height( root -> right); // or both
         ans = max( op1, max( op2,op3));
         return ans;

        
    }
};