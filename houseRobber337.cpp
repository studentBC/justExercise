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
        vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        queue<int> l;
        int c_l {0};
        int actual_l {0};
        vector<vector<int>> result;
        TreeNode* c;

        vector<int>* level {new vector<int>};

        if (root == NULL) return result;

        q.push(root);
        l.push(c_l);

        while (q.size() > 0){
            c = q.front();
            q.pop();
            c_l = l.front();
            l.pop();
            if (c_l == actual_l){
                level->push_back(c->val);
            }
            else{
                result.push_back(*level);
                level = new vector<int>;
                level->push_back(c->val);
                actual_l++;
            }

            if (c->left != NULL) {
                q.push(c->left);
                l.push(c_l+1);
            }
            if (c->right != NULL){
                q.push(c->right);
                l.push(c_l+1);
            }
            if(q.empty()){
                result.push_back(*level);
            }
        }
        return result;
    }

    int rob(TreeNode* root) {
        vector<vector<int>>nodes = levelOrder(root);
		vector<int>temp;
        int sum = 0;
        for (int i = 0; i < nodes.size(); i++) {
			sum = 0;
        	for (int j = 0; j < nodes[i].size(); j++) {
            	sum+=nodes[i][j];
            }
			temp.push_back(sum);
        }
		if (temp.size() == 1) {
			return temp[0];
		} else if (temp.size() == 2) {
			if (temp[0] > temp[1]) {
				return temp[0];
			} else {
				return temp[1];
			}
		} else if (temp.size() == 0) {
			return 0;
		}
		int money[temp.size()];
		money[0] = temp[0];
		money[1] = temp[1];
		int max = INT_MIN;
       	for (int i = 2; i < temp.size(); i++) {
			max = INT_MIN;
			for (int j = i-2; j > -1; j--) {
				if (max < money[j]) max = money[j];
			}
			money[i] = max+temp[i];
		}
		int ans = INT_MIN;
		for (int j = 0; j < temp.size(); j++) {
			if (ans < money[j]) ans = money[j];
		}
		return ans;
    }
};
//others method
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
    int tryRob(TreeNode* root, int& l, int& r) {
        if (!root)
            return 0;
            
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);
        
        return max(root->val + ll + lr + rl + rr, l + r);
    }

    int rob(TreeNode* root) {
        int l, r;
        return tryRob(root, l, r);
    }
};
