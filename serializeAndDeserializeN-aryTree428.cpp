/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following 3-ary tree



as [1 [3[5 6] 2 4]]. Note that this is just an example, you do not necessarily need to follow this format.

Or you can follow LeetCode's level order traversal serialization format, where each group of children is separated by the null value.



For example, the above tree may be serialized as [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14].

You do not necessarily need to follow the above suggested formats, there are many more different formats that work so please be creative and come up with different approaches yourself.

[1,null,3,2,4,null,5,6] 

Constraints:

The height of the n-ary tree is less than or equal to 1000
The total number of nodes is between [0, 10^4]
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:
    void go (Node* node, string& ans) {
        ans+=to_string(node->val);
        ans+=" ";
        if (node->children.size() == 0) return;
        for (int i = 0; i < node->children.size(); i++) {
            if (i == 0) ans+="[ ";
            go (node->children[i], ans);
        }
        ans+="] ";
    }
	//[ , 3 , [ , 5 , 6 , ] , 2 , 4 , ] 
    void construct (vector<string>& data, int& i, Node*& parent) {
        if (data[i] == "[") i++;
        Node* node = NULL;
        while (data[i]!="]" && data[i]!="[") {
            //cout << data[i] <<" , ";
            node = new Node(stoi(data[i]));
            parent->children.push_back(node);
            i++;
        }
        if (data[i] == "[") {
            construct(data, i, node); //5 
        }
        cout << data[i] <<" , ";
        while (data[i]!="]" && data[i]!="[") {
            //cout << data[i] <<" , ";
            Node* node = new Node(stoi(data[i]));
            parent->children.push_back(node);
            i++;
        }
        if (data[i] == "]") {
            i++;
            cout <<"shift to " << i << endl;
        }
    }

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        //string ans = "[ ";
        string ans;
        go (root, ans);
        //cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream ss(data);
		string temp;
		vector<string>dat;
		while (ss >> temp) {
			dat.push_back(temp);
			//cout << temp <<" , ";
		}
        int i = 1;
		Node* root = new Node(stoi(dat[0]));
		construct(dat, i, root);
        return root;
    }
};

class Codec {
public:
	void go (Node* node, string& ans) {
		if (!node) return;
		ans+=" "+to_string(node->val)+" "+to_string(node->children.size());
		for (auto& n: node->children) go (n, ans);
	}
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string ans;
		go (root, ans);
		return ans;
    }
	Node* construct (stringstream& ss) {
		if (ss.peek() == EOF) return nullptr;
		Node* root = new Node();
		int total;
		ss >> root->val >> total;
		for (int i = 0; i < total; i++) root->children.push_back(construct(ss));
		return root;
	}
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
		return construct(ss);
    }
};

//the fatest solution
class Codec {
public:
    void serHelper(ostringstream& out, Node* node)
    {
        if (node == nullptr)
        {
            out << "#" << " ";
            return;
        }
        
        out << to_string(node->val) << " ";
        int len = node->children.size();
        out << to_string(len) << " ";
        
        for (auto neigh : node->children)
        {
            serHelper(out, neigh);
        }
        
    }
    
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        ostringstream out;
        serHelper(out, root);
        
        return out.str();
    }

    
    Node* deserHelper(istringstream& in)
    {
        string str;
        in >> str;
        
        if (str == "#")
            return nullptr;
        
        string len;
        in >> len;
        Node* root = new Node(stoi(str));
        for (int i = 0; i < stoi(len); ++i)
        {
            root->children.push_back(deserHelper(in));
        }
        
        return root;
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream in(data);
        
        return deserHelper(in);
    }
};
