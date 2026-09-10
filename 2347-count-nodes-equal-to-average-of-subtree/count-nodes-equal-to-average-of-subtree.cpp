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
int ans=0;
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
    pair<int,int> solve(TreeNode* root ){
        if(!root)  return {0, 0};
        auto[leftSum, leftCount] = solve(root->left);
        auto [rightSum, rightCount] = solve(root->right);
        int sum = leftSum + rightSum + root->val;
        int cnt = leftCount + rightCount + 1;
        if(sum/cnt == root->val)  ans++;
        return {sum,cnt};
    }
};