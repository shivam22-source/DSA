#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

void preorder(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
}

void postorder(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}

 vector<vector<int>> levelOrder(TreeNode* root) {
vector<vector<int>> ans;
if (!root) return ans;

queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {
    int size = q.size();
    vector<int> level;

    for (int i = 0; i < size; i++) {
        TreeNode* node = q.front();
        q.pop();

        level.push_back(node->val);

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }

    ans.push_back(level);
}

return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> res;
    // all function return

    return 0;
}