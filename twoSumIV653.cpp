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
	void go (TreeNode* node, vector<int>& value) {
		if (!node)return;
		value.push_back(node->val);
		go (node->left,value);
		go (node->right,value);
		return;
	}
    bool findTarget(TreeNode* root, int k) {
		vector<int>value;
		go (root, value);
		unordered_set<int>sum;
		for (int i = 0; i < value.size(); i++) {
			for (int j = 0; j < value.size(); j++) {
				if (i!=j) sum.insert(value[i]+value[j]);
			}
		}
		return sum.find(k)!=sum.end();
    }
};
//the fatest method
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
    bool findTarget(TreeNode* root, int k) {
        // 截取数据<=target
        queue<TreeNode*>Tree;
        vector<int>val;
        if(root==NULL)
            return false;
        else{
            Tree.push(root);
            // 非空
            while(!Tree.empty())
            {
                TreeNode* tmp=Tree.front();
                //if(tmp->val<k)
                val.push_back(tmp->val);
                if(tmp->left !=NULL)
                    Tree.push(tmp->left);
                if(tmp->right != NULL)
                    Tree.push(tmp->right);
                Tree.pop();
            }
            for(int i=0;i<val.size();i++){
                for(int j=i+1;j<val.size();j++)
                {
                    if(val[i]+val[j]==k)
                        return true;
                }
                }
                
        }
        return false;
    }
};
static const auto speedup = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
