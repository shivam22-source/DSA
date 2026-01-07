// vertical line ke hisaab se node store karo
// agar same vertical pe baad me koi node aaye,
// to purani value replace kar do

class Solution {
public:
    vector<int> bottomView(TreeNode* root) {
        if (!root) return {};

        map<int, int> mp;  // vertical -> node value
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int vertical = temp.second;

            // overwrite allowed (bottom view logic)
            mp[vertical] = node->val;

            if (node->left)
                q.push({node->left, vertical - 1});
            if (node->right)
                q.push({node->right, vertical + 1});
        }

        vector<int> ans;
        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
