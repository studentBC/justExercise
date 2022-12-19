/*
 * A set of real numbers can be represented as the union of several disjoint intervals, where each interval is in the form [a, b). A real number x is in the set if one of its intervals [a, b) contains x (i.e. a <= x < b).

You are given a sorted list of disjoint intervals intervals representing a set of real numbers as described above, where intervals[i] = [ai, bi] represents the interval [ai, bi). You are also given another interval toBeRemoved.

Return the set of real numbers with the interval toBeRemoved removed from intervals. In other words, return the set of real numbers such that every x in the set is in intervals but not in toBeRemoved. Your answer should be a sorted list of disjoint intervals as described above.

Input: intervals = [[0,2],[3,4],[5,7]], toBeRemoved = [1,6]
Output: [[0,1],[6,7]]

Input: intervals = [[0,5]], toBeRemoved = [2,3]
Output: [[0,2],[3,5]]

Input: intervals = [[-5,-4],[-3,-2],[1,2],[3,5],[8,9]], toBeRemoved = [-1,4]
Output: [[-5,-4],[-3,-2],[4,5],[8,9]]
 */

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>>ans;
        int start, end, ps = -1, pe = -1;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] > toBeRemoved[1] || intervals[i][1] < toBeRemoved[0]) ans.push_back(intervals[i]);
            else {
                if (intervals[i][0] < toBeRemoved[0]) {
                    start = intervals[i][0];
                    end = toBeRemoved[0];
                    if (ps != start && pe != end) {
                        ans.push_back({start, end});
                        ps = start; pe = end;
                    }
                }
                
                if (intervals[i][1] > toBeRemoved[1]) {
                    start = toBeRemoved[1];
                    end = intervals[i][1];
                    if (ps != start && pe != end) {
                        ans.push_back({start, end});
                        ps = start; pe = end;
                    }
                }
                
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        //cout << intervals.size() <<" " << toBeRemoved[0] <<" , " << toBeRemoved[1] << endl;
        vector<vector<int>>ans;
        for (int j = 0; j < intervals.size(); j++) {
            if (intervals[j][0] >= toBeRemoved[0] && toBeRemoved[1] >= intervals[j][1]) {
                continue;
            } else if (intervals[j][0] < toBeRemoved[0] && toBeRemoved[1] <= intervals[j][1]) {
                vector<int>temp{intervals[j][0], toBeRemoved[0]};
                ans.push_back(temp);
                vector<int>tmp{toBeRemoved[1], intervals[j][1]};
                ans.push_back(tmp);
            } else if (intervals[j][1] > toBeRemoved[0] && toBeRemoved[0] > intervals[j][0]) {
                intervals[j][1] = toBeRemoved[0];
                ans.push_back(intervals[j]);
            } else if (toBeRemoved[1] > intervals[j][0] && toBeRemoved[1] < intervals[j][1]) {
                intervals[j][0] = toBeRemoved[1];
                ans.push_back(intervals[j]);
            } else {
                ans.push_back(intervals[j]);
            }   
        }
        return ans;
    }
};
//the fatest solution
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF              (int)1000000007
#define EPS              1e-9
#define pb               push_back
#define mp               make_pair
#define all(c)           c.begin(), c.end()
#define forall(i,a,b)    for(int i=a;i<(b);++i)
#define trav(a,x)        for(auto & a: x)
#define in(a,b)          ((b).find(a) != (b).end())
#define sz(c)            (int)(c).size()
#define input(a)         for(auto & x : a) cin >> x;

using namespace std;

typedef vector<int>      vi;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<ii>       vii;
typedef long long        ll;

#ifdef DEBUG
#define trace(...)       __f(#__VA_ARGS__, __VA_ARGS__)
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define trace(...)       
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " | ";
    __f(comma + 1, args...);
}

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& u) {
      vvi ans;
      for(auto & v : intervals){
        print_(v);
        print_(u);
        if( v[1] <  u[0] or u[1] < v[0] ){
          debug("1");
          ans.pb(v);
        }else if( v[0] >= u[0] and v[1] <= u[1] ){
          debug("2");
          continue; 
        }else if( v[0] < u[0] and v[1] > u[1] ){
          debug(" here ");
          int a = u[0];
          int b = u[1];
          trace(a,b,v[0], v[1]);
          if( v[0] < a ) ans.pb({v[0], a});
          if( b < v[1] ) ans.pb({b, v[1]});
        }else if( v[0] < u[0] ){
          int a = u[0];
          if( v[0] < a ) ans.pb({v[0], a});
        }else if( v[1] > u[1] ){
          int b = u[1];
          if( b < v[1] ) ans.pb({b, v[1]});
        }
      }
      return ans;
    }
};
