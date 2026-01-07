#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

int diameter = 0;

int dfs(TreeNode* root) {
    if (!root) return 0;

    int lh = dfs(root->left);
    int rh = dfs(root->right);

    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

///height function
    return 0;
}