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

    void travinOrd(TreeNode* node, vector<int>& array){

        if(node == nullptr){
            return;
        }

        if(node->left != nullptr){
            travinOrd(node->left, array);
        }
        array.push_back(node->val);

        if(node->right != nullptr){
            travinOrd(node->right, array);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> travOutput;

        travinOrd(root, travOutput);



        return travOutput;

    }
};
