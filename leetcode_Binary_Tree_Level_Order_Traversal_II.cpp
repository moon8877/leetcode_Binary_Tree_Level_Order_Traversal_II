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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        return bfs(root);
    }
private:
    vector<vector<int>> bfs(TreeNode* root){
        vector<TreeNode*> currNode;
        vector<TreeNode*> nextNode;
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        currNode.push_back(root);
        while(currNode.size() != 0){
            ans.push_back({});
            for(int i=0;i<currNode.size();i++){
                if(currNode[i]->left){nextNode.push_back(currNode[i]->left);}
                if(currNode[i]->right){nextNode.push_back(currNode[i]->right);}
                ans.back().push_back(currNode[i]->val);
            }
            currNode.swap(nextNode);
            nextNode.clear();
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
