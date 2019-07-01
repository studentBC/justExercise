class Solution {
public:
    bool parseBoolExpr(string expression) {
        vector<char>op;
        vector<bool>bo;
        bool exp;
        for (char c: expression) {
            if ( c == ')') {
                while (op.back() != '(') {
                    if (op.back() == 't') {
                        bo.emplace_back(true);
                    } else if (op.back() == 'f') {
                        bo.emplace_back(false);
                    }
                    op.pop_back();
                }
                op.pop_back();
                exp = bo[0];
                if (op.back() == '&') { 
                    for (int i = 1; i < bo.size(); i++) {
                        exp = exp & bo[i];
                    }
                } else if (op.back() == '|') {
                    for (int i = 1; i < bo.size(); i++) {
                        exp= exp | bo[i];
                    }
                } else if (op.back() == '!') {
                    exp = !exp;
                }
                op.pop_back();bo.clear();
                if (exp) {
                    op.emplace_back('t');
                } else {
                    op.emplace_back('f');
                }
            } else if ( c == ',') {
                continue;
            } else {
                op.emplace_back(c);
            }
        }
        //cout << op.back();
        return op.back() == 't';
    }
};

