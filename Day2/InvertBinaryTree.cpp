#include <bits/stdc++.h>
using namespace std;

// invertTree(root);
void invertTree(TreeNode* &root) {
    if ( root==nullptr) return;

    invertTree(root->left);
    invertTree(root->right);

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// root = invertTree(root);
TreeNode* invertTree(TreeNode* root) {
    if ( root==nullptr) return;

    invertTree(root->left);
    invertTree(root->right);

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}


int main() {

    string s;
    cin >> s;
    cout << findMaxSizeUniqueSubstr(s) << endl;


}

// 6
// 5 4 1 2 3 6