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
    int postOrder(TreeNode* root, unordered_map<int,int> &mp, int &maxFre){
        if(root == nullptr) return 0;
        int currSum = root->val + postOrder(root->left, mp, maxFre) +
                      postOrder(root->right, mp, maxFre);
        mp[currSum]++;
        maxFre = max(maxFre, mp[currSum]);
        return currSum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        //if(root == nullptr) return 0;
        unordered_map<int, int>mp;
        int maxFre = 0;
        postOrder(root, mp, maxFre);
        vector<int>ans;
        //cout<<maxFre<<endl;
        for(auto &pairs : mp){
            if(pairs.second == maxFre) ans.push_back(pairs.first);
        }
        return ans;
    }
};