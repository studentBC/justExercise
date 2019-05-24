class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        for (int ast:asteroids) {
            if (!ans.empty()) {
                while (1) {
                    if (ans.size() > 0 && ans.back() > 0 && ast < 0) {
                        if (ans.back() > -ast) {
                            ast = 0;
                        } else if (ans.back() < -ast) {
                            ans.pop_back();
                        } else {
                            ans.pop_back();
                            ast = 0;
                            break;
                        }
                    } else {
                        if (ast != 0) {
                            ans.push_back(ast);
                        }
                        break;
                    }
                }
            } else {
                ans.emplace_back(ast);
            }
        }
        return ans;
    }
};
//8 ms solution
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      int n = asteroids.size();
      stack<int> stk;
      
      for (int i = 0; i < n; i++) {
        int a = asteroids[i];
        if (a > 0) stk.push(a);
        else {
          bool exploded = false;
          while (!stk.empty()) {
            if (stk.top() < 0) break;
            if (stk.top() + a >= 0) {
              exploded = true;
              if (stk.top() + a == 0) stk.pop();
              break;
            } else stk.pop();
          }
          if (!exploded) stk.push(a);          
        }
      }
      vector<int> ret(stk.size(), 0);
      int idx = ret.size() - 1;
      while (!stk.empty()) {
        ret[idx--] = stk.top();
        stk.pop();
      }
      return ret;
    }
};
