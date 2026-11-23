class Solution {
public:
    void fun(TreeNode* root, int level, vector<int>& ans) {

        if (root == nullptr) {
            return;
        }

        // First node encountered at each level
        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        fun(root->right, level + 1, ans);
        fun(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        fun(root, 0, ans);

        return ans;
    }
};