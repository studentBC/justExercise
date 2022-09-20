/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */
class NumNode: public Node {
    public:
        NumNode(int val): value(val){}
        int evaluate() const;
    private:
        int value;
};
int NumNode::evaluate() const {
    return value;
}

class OpNode: public Node {
    public:
        OpNode(Node* left, Node* right): l(left), r(right){}
        ~OpNode();
    protected:
        Node* const l;
        Node* const r;
};
OpNode::~OpNode() {
    delete l;
    delete r;
}
class AddOpNode: public OpNode {
    public:
    AddOpNode(Node* left, Node* right): OpNode(left, right){}
    int evaluate() const;
};
int AddOpNode::evaluate() const {
    return l->evaluate()+r->evaluate();
};
class SubOpNode: public OpNode {
    public:
        SubOpNode(Node* left, Node* right): OpNode(left, right){}
        int evaluate() const;
};
int SubOpNode::evaluate() const {
    return l->evaluate()-r->evaluate();
};
class MultiplyOpNode: public OpNode {
    public:
        MultiplyOpNode(Node* left, Node* right): OpNode(left, right){}
        int evaluate() const;
};
int MultiplyOpNode::evaluate() const {
    return l->evaluate()*r->evaluate();
};
class DivideOpNode: public OpNode {
    public:
        DivideOpNode(Node* left, Node* right): OpNode(left, right){}
        int evaluate() const;
};
int DivideOpNode::evaluate() const {
    return l->evaluate()/r->evaluate();
};
class TreeBuilder {
public:
    Node* nodeCreate (string op, Node* left, Node* right) {
        if (op[0] == '+') {
            return new AddOpNode(left, right);
        } else if (op[0] == '-') {
            return new SubOpNode(left, right);
        } else if (op[0] == '*') {
            return new MultiplyOpNode(left, right);
        } else {
            return new DivideOpNode(left, right);
        }
    }
    int num (string& s) {
        int ans = 0;
        for (char c : s) {
            ans*=10;
            ans+=(c-'0');
        }
        return ans;
    }
    Node* buildTree(vector<string>& postfix) {
        vector<Node*>stack;
        Node* r, *l;
        for (string& s : postfix) {
            if (isdigit(s[0])) stack.push_back(new NumNode(num(s)));
            else {
                r = stack.back();
                stack.pop_back();
                l = stack.back();
                stack.pop_back();
                stack.push_back(nodeCreate(s, l, r));
            }
        }
        return stack.back();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
