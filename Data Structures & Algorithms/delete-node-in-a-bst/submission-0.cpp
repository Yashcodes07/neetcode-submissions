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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        // Base case: key not found
        if (root == nullptr) {
            return nullptr;
        }

        // Step 1: Search for the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // Step 2: Node found
        else {

            // Case 1: No left child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2: No right child
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two children
            else {
                // Find inorder successor
                TreeNode* temp = root->right;

                while (temp->left != nullptr) {
                    temp = temp->left;
                }

                // Copy successor value
                root->val = temp->val;

                // Delete successor from right subtree
                root->right = deleteNode(root->right, temp->val);
            }
        }

        return root;
    }
};