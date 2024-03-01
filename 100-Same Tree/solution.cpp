/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
*/

#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool f(TreeNode* temp, TreeNode* temp2){
        if(temp == NULL && temp2 == NULL) return true;
        if(temp == NULL || temp2 == NULL) return false;
        if(temp->val != temp2->val) return false;
        return f(temp->left, temp2->left) && f(temp->right, temp2->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return f(p, q);
    }
};

// Test function
int main() {
    // Example usage
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution sol;
    bool result = sol.isSameTree(p, q);
    if(result)
        cout << "The trees are the same." << endl;
    else
        cout << "The trees are not the same." << endl;

    // Free memory
    delete p->left;
    delete p->right;
    delete p;
    delete q->left;
    delete q->right;
    delete q;

    return 0;
}
