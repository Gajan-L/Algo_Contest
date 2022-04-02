// Q3: Create Binary Tree From Descriptions
// very intuitive, use a hash table to record created node
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, pair<TreeNode*, bool>> mp;
        for(int i = 0; i < n; i++){
            int pval = descriptions[i][0];
            int cval = descriptions[i][1];
            int isLeft = descriptions[i][2];
            if(mp.count(pval)){
                TreeNode* parent = mp[pval].first;
                if(mp.count(cval)){
                    mp[cval].second = false;
                    TreeNode* child = mp[cval].first;
                    if(isLeft)
                        parent->left = child;
                    else
                        parent->right = child;
                }
                else{
                    TreeNode* child = new TreeNode(cval);
                    if(isLeft)
                        parent->left = child;
                    else
                        parent->right = child;
                    mp[cval] = {child, false};
                }
            }
            else{
                TreeNode* parent = new TreeNode(pval);
                if(mp.count(cval)){
                    mp[cval].second = false;
                    TreeNode* child = mp[cval].first;
                    if(isLeft)
                        parent->left = child;
                    else
                        parent->right = child;
                }
                else{
                    TreeNode* child = new TreeNode(cval);
                    if(isLeft)
                        parent->left = child;
                    else
                        parent->right = child;
                    mp[cval] = {child, false};
                }
                mp[pval] = {parent, true};
            }
        }
        TreeNode* root;
        for(auto it: mp){
            if(it.second.second){
                root = it.second.first;
            }
        }
        return root;
    }
};
