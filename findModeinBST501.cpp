//fatest method
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();


class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        mc = 0;
        lc = 0;
        vector<int> ret;
        last = LONG_MIN;
        
        helper(root, ret);
        
        return ret;
    }
private:
    void helper(TreeNode* root, vector<int>& v)
    {
        if(root == NULL)
            return;
        
        helper(root->left, v);
        
        if(last == root->val)
            lc++;
        else
            lc = 1;
        
        if(lc == mc)
            v.push_back(root->val);
        else if (lc > mc){
            mc = lc;
            v.clear();
            v.push_back(root->val);
        }
        last = root->val;
            
        helper(root->right, v);
    }
    
    int mc;
    int lc;
    long last;
};
//my method
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
    void go(TreeNode* node, vector<int>&map) {
        if (!node)return;
        map.push_back(node->val);
        go(node->left,map);
        go(node->right,map);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>map;
        go(root,map);
        sort(map.begin(),map.end());
        int prev = INT_MAX, count = 0 , max = INT_MIN;
        vector<int>ans;
        
        if (map.size() == 1) {
            ans.push_back(map[0]);
            return ans;
        } else if (map.size() == 0) {
            return ans;
        }
        ans.push_back(INT_MIN);
        for (int i = 0; i < map.size(); i++) {
            //cout << map[i] << endl;
            if (prev!=map[i]) {
                prev = map[i];
                //cout <<"start at " << i <<" ,  "<< prev <<" enter!" << endl;
                count = 0;
                for (int j = i; j < map.size(); j++) {
                    if (prev == map[j]) { 
                        count++;
                        if (max < count) {
                            ans.clear();
                            ans.push_back(map[i]);
                            max = count;
                        } else if (max == count) {
                            ans.push_back(map[i]);
                        }
                    } else {
                        /*
                        if (max < count) {
                            ans.clear();
                            ans.push_back(map[i]);
                            max = count;
                        } else if (max == count) {
                            ans.push_back(map[i]);
                        }*/
                        if (j>0)i = j-1;
                        
                        break;
                    }
                }
            }
            //cout <<"i: " << i << " temp: " << map[i] << " prev: " << prev << endl; 
        }

        return ans;
    }
};
