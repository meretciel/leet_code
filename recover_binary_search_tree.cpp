/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <limits>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
 The basic idea is if we iterate the tree with in-order search, then the output 
 should be a vector of increasing numbers.
 
 Given that there are only two wrong nodes, there are at most two pairs of disorder elements 
 in the final array.
 
*/



class Solution {
public:
    
    
    vector<TreeNode*> vec;          // store the pointers of potential wrong nodes
    
    
    int last_val = numeric_limits<int>::min(); // keep track of value of nodes
    
    
    TreeNode *last_node = NULL;         // keep track of the last node
    
    bool has_been_solved = false;       // indicates if we have found the wrong nodes
    
    
    
    void recoverTree(TreeNode* root) {
        _recoverTree(root);
        
        // process the vector
        if (vec.size() == 2) {
            swap(vec[0]->val, vec[1]->val);
        } else if(vec.size() == 4) {
            swap(vec[0]->val, vec[3]->val);
        }
        
        return ;
    }
    
    void _recoverTree(TreeNode* root) {
        if (!root) { return; }
        
        int val = root->val;
        
        _recoverTree(root->left);
        
        if (last_node && val < last_node->val) {
            // add to the vector
            vec.push_back(last_node);
            vec.push_back(root);
        }
        
        last_node = root;
        
        _recoverTree(root->right);
        
        
    }  
};