#define ll long long
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return get<0>(solve(root));
    }
private:
    // tuple = { isBST, subtreeMin, subtreeMax }
    tuple<bool, ll, ll> solve(TreeNode* root){
        if(!root) return {true, LLONG_MAX, LLONG_MIN};

        auto leftSubtree = solve(root->left);
        auto rightSubtree = solve(root->right);

        bool isValidLeftSubtree = get<0>(leftSubtree);
        bool isValidRightSubtree = get<0>(rightSubtree);

        if(!isValidLeftSubtree or !isValidRightSubtree) return {false, 0, 0};

        int curr = root->val;
        ll leftMaxValue = get<2>(leftSubtree);
        ll rightMinValue = get<1>(rightSubtree);

        if( !(leftMaxValue < curr and curr < rightMinValue) ) return {false, 0, 0};

        ll subTreeMin = min(curr,  get<1>(leftSubtree));
        ll subTreeMax = max(curr, get<2>(rightSubtree));
        return {true, subTreeMin, subTreeMax};
    }
    ll min(ll a, ll b) {
        return a < b ? a : b;
    }
    ll max(ll a, ll b) {
        return a < b ? b : a;
    }
};