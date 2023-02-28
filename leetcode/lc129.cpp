#include <bits/stdc++.h>

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
     	TreeNode() : val(0), left(nullptr), right(nullptr) {}
 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode* node, int currSum, int totalSum){
    if (!node) return totalSum;
    currSum *= 10;
    currSum += node->val;
    if (!node->left && !node->right){
        totalSum += currSum;
    }
    totalSum = dfs(node->left, currSum, totalSum);
    totalSum = dfs(node->right, currSum, totalSum);
    return totalSum;
}
int sumNumbers(TreeNode* root) {
    return dfs(root, 0, 0);
}

int main(){
    TreeNode t2 = new TreeNode(2);
    TreeNode t3 = new TreeNode(3);
    TreeNode t1 = new TreeNode(1, t2, t3);
    cout << sumNumber(t1) << endl;
    return 0;
}
