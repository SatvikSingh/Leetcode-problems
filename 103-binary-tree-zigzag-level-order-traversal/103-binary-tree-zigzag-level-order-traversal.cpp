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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode*> q;
        bool flag = false;
        
        if (!root)
            return {};
        
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                temp.push_back(node->val);
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            
            flag = !flag;
            if (!flag)
                reverse(temp.begin(), temp.end());
            // cout << flag << endl;
            ans.push_back(temp);
            temp.clear();
        }
        
        return ans;
    }
};