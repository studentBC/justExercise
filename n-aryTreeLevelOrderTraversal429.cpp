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
    vector<vector<int>> levelOrder(Node* root) {
    	vector<vector<int>>ans;
		queue<Node*>nodes;
		nodes.push(root);
		Node* head;
		while (!nodes.empty()) {
			queue<Node*>nq;
			vector<int>temp;
			while (!nodes.empty()) {
				head = nodes.front();
				for (Node* ptr:head->children) {
					nq.push(ptr);
				}
				temp.emplace_back(head->val);
				nodes.pop();
			}
			nodes = nq;
			ans.emplace_back(temp);
		}
		return ans;
    }
};
//136 ms method
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
            return {};
        queue<Node*> q;
        q.push(root);
        
        vector<vector<int>> result;
        while (!q.empty()) {
            size_t size = q.size();
            result.push_back({});
            while (size > 0) {
                Node* n = q.front();
                q.pop();
                result.back().push_back(n->val);
                size--;
                for (Node* child: n->children) {
                    if (child)
                        q.push(child);
                }
            }
        }
        return result;
    }
};
