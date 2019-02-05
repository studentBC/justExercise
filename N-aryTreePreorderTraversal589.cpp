/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void go (Node* node, vector<int>& ans) {
        if (!node)return;
        ans.push_back(node->val);
        for (int i = 0; i < node->children.size(); i++) {
            go (node->children[i],ans);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int>ans;
        go (root,ans);
        return ans;
    }
};
//the fatest method
class Solution
{
    //解法一：AC
    void RecursivePre(Node *node)
    {
        if(node == nullptr)
            return;
        res.push_back(node->val);
        for(auto n : node->children)
        {
            RecursivePre(n);
        }
    }
    //解法二：
    void iterativelyPro(Node *node)
    {
        if(node == nullptr)
            return;
        stk.push(node);
        while(!stk.empty())
        {
            tmp = stk.top();
            res.push_back(tmp->val);
            stk.pop();
            for(auto rbeg = tmp->children.rbegin(); rbeg != tmp->children.rend(); ++rbeg)
            {
                stk.push(*rbeg);
            }
        }
    }
  public:
    vector<int> preorder(Node *root)
    {
        if(root == nullptr)
            return res;
        //RecursivePre(root);
        iterativelyPro(root);
        return res;
    }

  private:
    vector<int> res;
    stack<Node *> stk;
    Node *tmp = nullptr;
};
