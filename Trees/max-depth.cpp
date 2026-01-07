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

int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + min(height(root->left), height(root->right));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

///height functio
    return 0;
}