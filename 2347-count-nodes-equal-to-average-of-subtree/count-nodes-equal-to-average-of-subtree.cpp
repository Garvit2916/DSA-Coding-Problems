class Solution {
public:
    int ans = 0;

    // returns {sum of subtree, number of nodes}
    pair<int, int> dfs(TreeNode* root) {
        
        if (root == NULL) {
            return {0, 0};
        }

        // Get information from left subtree
        auto left = dfs(root->left);

        // Get information from right subtree
        auto right = dfs(root->right);

        // Calculate current subtree sum
        int sum = left.first + right.first + root->val;

        // Calculate number of nodes in current subtree
        int count = left.second + right.second + 1;

        // Check condition
        if (sum / count == root->val) {
            ans++;
        }

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};