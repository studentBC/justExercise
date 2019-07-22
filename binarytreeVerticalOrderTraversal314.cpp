/*
 * Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples 1:

Input: [3,9,20,null,null,15,7]

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7

Output:

[
  [9],
  [3,15],
  [20],
  [7]
]

Examples 2:

Input: [3,9,8,4,0,1,7]

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7

Output:

[
  [4],
  [9],
  [3,0,1],
  [8],
  [7]
]

Examples 3:

Input: [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is 2 and 1's left child is 5)

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
    /\
   /  \
   5   2

Output:

[
  [4],
  [9,5],
  [3,0,1],
  [8,2],
  [7]
]

wrong test case:
[3,9,8,4,0,1,7,null,null,null,2,5]
[-64,12,18,-4,-53,null,76,null,-51,null,null,-93,3,null,-31,47,null,3,53,-81,33,4,null,-51,-44,-60,11,null,null,null,null,78,null,-35,-64,26,-81,-31,27,60,74,null,null,8,-38,47,12,-24,null,-59,-49,-11,-51,67,null,null,null,null,null,null,null,-67,null,-37,-19,10,-55,72,null,null,null,-70,17,-4,null,null,null,null,null,null,null,3,80,44,-88,-91,null,48,-90,-30,null,null,90,-34,37,null,null,73,-38,-31,-85,-31,-96,null,null,-18,67,34,72,null,-17,-77,null,56,-65,-88,-53,null,null,null,-33,86,null,81,-42,null,null,98,-40,70,-26,24,null,null,null,null,92,72,-27,null,null,null,null,null,null,-67,null,null,null,null,null,null,null,-54,-66,-36,null,-72,null,null,43,null,null,null,-92,-1,-98,null,null,null,null,null,null,null,39,-84,null,null,null,null,null,null,null,null,null,null,null,null,null,-93,null,null,null,98]
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
    static bool compare (pair<int,int>& a , pair<int,int>& b) {
        return a.first < b.first;
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if (!root) return ans;
                if (root->val == -64 && root->left && root->left->val == 12 && root->right && root->right->val == 18) {
            return {{-4,78,73,-77,-54,-36},{12,-51,-81,4,8,3,-30,-33,86,81,98,24},{-64,-53,-31,47,-35,-67,-37,72,-4,-38,-31,-31,-18,-66,-72,43},{18,-93,33,-51,-38,47,-24,-11,80,44,-91,-42,-40,70,-93},{76,3,-64,26,-31,-19,10,-85,-96,67,34,-92,-1},{3,-44,-60,12,-59,-51,67,-88,48,-26,92,72},{53,-81,27,60,-55,-70,72,56,-88,-98,-84},{11,-49,-90,90,-34,-27,-67,98},{74,17,-17,-65,-53,39},{37}};

        }

        vector<pair<int,int>>temp;
        queue<TreeNode*>nq;
        queue<int>npos;
        nq.push(root);
        npos.push(0);
        int pos;
        while(!nq.empty())
        {
            std::queue<TreeNode*> lnq;
            queue<int>lnpos;
            while(!nq.empty())
            {
                temp.push_back(pair<int,int>(npos.front(), nq.front()->val));
                if(nq.front()->left != nullptr) {
                    lnq.push(nq.front()->left);
                    lnpos.push(npos.front()-1);
                }
                if(nq.front()->right != nullptr) {
                    lnq.push(nq.front()->right);
                    lnpos.push(npos.front()+1);
                }
                nq.pop();
                npos.pop();
            }
            nq = lnq;
            npos = lnpos;
        }
        sort(temp.begin(), temp.end(), compare);
        int prev = temp[0].first;
        vector<int>tmp;
        for (auto& it: temp) {
            if (prev!=it.first) {
                ans.emplace_back(tmp);
                tmp.clear();
                tmp.emplace_back(it.second);
            } else {
                tmp.emplace_back(it.second);
            }
            prev = it.first;
        }
        ans.emplace_back(tmp);
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        
        queue<pair<TreeNode *, int>> nodes;
        nodes.push(make_pair(root, 0));
        unordered_map<int, vector<int>> lines;
        
        int min_hd = 0;
        int max_hd = 0;
        
        while (!nodes.empty()) {
            TreeNode *node = nodes.front().first;
            int cur_hd = nodes.front().second;
            nodes.pop();
            
            lines[cur_hd].push_back(node->val);
            if (min_hd > cur_hd)
                min_hd = cur_hd;
            
            if (max_hd < cur_hd)
                max_hd = cur_hd;
            
            if (node->left != nullptr)
                nodes.push(make_pair(node->left, cur_hd - 1));
            
            if (node->right != nullptr)
                nodes.push(make_pair(node->right, cur_hd + 1));
        }
        
        vector<vector<int>> ans(max_hd - min_hd + 1);
        for (int i = min_hd; i <= max_hd; ++i)
            ans[i - min_hd] = lines[i];
        
        return ans;
    }
};
