/*
Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.

Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.

Example 1:

Input:
root = [1, 3, 2], k = 1
Diagram of binary tree:
          1
         / \
        3   2

Output: 2 (or 3)

Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.

Example 2:

Input:
root = [1], k = 1
Output: 1

Explanation: The nearest leaf node is the root node itself.

Example 3:

Input:
root = [1,2,3,4,null,null,null,5,null,6], k = 2
Diagram of binary tree:
             1
            / \
           2   3
          /
         4
        /
       5
      /
     6

Output: 3
Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.

Note:

    root represents a binary tree with at least 1 node and at most 1000 nodes.
    Every node has a unique node.val in range [1, 1000].
    There exists some node in the given binary tree for which node.val == k.

	wrong test case:
	[1,2,3,null,null,4,5,6,null,null,7,8,9,10]
	7

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void go (TreeNode* node, TreeNode* prev, TreeNode*& start, int k, map<TreeNode*, TreeNode*>& parent) {
        if (!node) return;
        if (node->val == k) start = node;
        if (parent.find(node) == parent.end()) {
            parent.insert(pair<TreeNode*, TreeNode*>(node, prev));
        }
        go (node->left, node, start, k, parent);
        go (node->right, node, start, k, parent);
    }
    int findClosestLeaf(TreeNode* root, int k) {
        TreeNode* start = new TreeNode(0);
        map<TreeNode*, TreeNode*>parent;
        go (root, nullptr, start, k, parent);
        queue<TreeNode*>q;
        unordered_set<int>visited;
        q.push(start);
        cout << (start)->val << endl;
        visited.insert((start)->val);
        TreeNode* cur;
        while (!q.empty()) {
            cur = q.front();                
            q.pop();
            if(!cur->left && !cur->right) {         
                return cur->val;
            }
            if(cur->left && visited.find(cur->left->val) == visited.end()) {
                visited.insert(cur->left->val);
                q.push(cur->left);
            }   
            if(cur->right && visited.find(cur->right->val) == visited.end()) {
                visited.insert(cur->right->val);
                q.push(cur->right);
            }                                                
            if(parent[cur] && visited.find(parent[cur]->val) == visited.end()) {  // go alone the back edge
                visited.insert(parent[cur]->val);
                q.push(parent[cur]);                           
            }
        }    
        return -1;
    }   
}; 
//the fatest method
class State{
public:
    int dist;
    int val;
    bool found_k;
    int k_height;
};

class Solution {
public:
    
    int findClosestLeaf(TreeNode* root, int k) {
        return dfs(root, k).val;
    }
    
    State dfs(TreeNode * node, int k){
        // (least dist leaf to k or min height leaf, leaf value), (found k?, at what height)
        
        if(node == NULL) return State{INT_MAX, -1, false, -1};
        bool found_k = node -> val == k;
        
        if(node->left == NULL and node -> right == NULL){
            return State{0, node->val, found_k, 0};
        }
        
        auto left = dfs(node->left, k);
        auto right = dfs(node->right, k);
        
        State ans;
        
        // finding k and it's height.
        ans.found_k = found_k or left.found_k or right.found_k;
        if(ans.found_k){
            int ht = INT_MAX;
            if(found_k) ht = 0;
            else if(left.found_k) ht = 1 + left.k_height;
            else ht = 1 + right.k_height;
            ans.k_height = ht;
        } // else k_height doesn't matter.
        
        // distance and value.
        if(ans.found_k) {
            if(found_k){
                // get the lowest leaf.
                if(left.dist < right.dist) {
                    ans.dist = 1 + left.dist;
                    ans.val = left.val;
                } else {
                    ans.dist = 1 + right.dist;
                    ans.val = right.val;
                }
            } else if(left.found_k) {
                if(left.dist - 2 > right.dist){
                    ans.dist = 2 + right.dist;
                    ans.val = right.val;
                } else {
                    ans.dist = left.dist;
                    ans.val = left.val;
                }
            } else {
                // right found k
                if(right.dist - 2 > left.dist){
                    ans.dist = 2 + left.dist;
                    ans.val = left.val;
                } else {
                    ans.dist = right.dist;
                    ans.val = right.val;
                }
            }
        } else {
            // get the lowest leaf.
            if(left.dist < right.dist) {
                ans.dist = 1 + left.dist;
                ans.val = left.val;
            } else {
                ans.dist = 1 + right.dist;
                ans.val = right.val;
            }
        }
        
        
        return ans;
    }
};
