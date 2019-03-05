class Solution {
private:
     struct TreeNode {
         string val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
public:
    TreeNode* deserialize(queue<char>& node, bool& invalid) {
        if (node.empty()) {
            invalid = true;
            return nullptr;
        }
        char val = node.front();
        node.pop();
        if (val == "#") return nullptr;
        TreeNode *root = new TreeNode(val);
        root->left = deserialize(node,invalid);
        root->right = deserialize(node,invalid);
        return root;
    }

    bool isValidSerialization(string preorder) {
        queue<char>node;
		string temp = ""
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] != ',') {
				temp+=preorder[i];
			} else {
				node.push(temp);
				temp = "";
			}
        }
        bool invalid = false;
        TreeNode* root = deserialize(node,invalid); 
        if (!node.empty() || invalid)return false;
        return true;
    }
};
//the fatest method without building a BT
class Solution {
public:
    bool isValidSerialization(string preorder)
    {
        int count = 1;
        stringstream ss(preorder);
        string s;
        while (count && getline(ss, s, ',')) {
            if (s == "#") --count;
            else ++count;
        }
        return ss.eof() && count == 0;
    }
};
/*
Some used stack. Some used the depth of a stack. Here I use a different perspective. In a binary tree, if we consider null as leaves, then

all non-null node provides 2 outdegree and 1 indegree (2 children and 1 parent), except root
all null node provides 0 outdegree and 1 indegree (0 child and 1 parent).
Suppose we try to build this tree. During building, we record the difference between out degree and in degree diff = outdegree - indegree. When the next node comes, we then decrease diff by 1, because the node provides an in degree. If the node is not null, we increase diff by 2, because it provides two out degrees. If a serialization is correct, diff should never be negative and diff will be zero when finished.
*/
