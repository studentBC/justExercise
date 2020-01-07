Define 2 DP matrix, left and right. The DP definition is left[color][index] represents the minimum distance of the color color to the left of the index index. Similarly, right[color][index] represents the minimum distance of the color color to the right of the index index. Note that we also include the current element in the DP definition.

For each of the 3 colours, we can fill both the dp matrix in linear time. Let us fix any color, say 1, and fix a dp matrix, say left. Now, the minimum distance of red from the i-th index to the left will be zero if the i-th index is of red color. If the i-th color is not zero, we can look at the minimum distance of the i-1 th index. If the index is -1, it means that no red exists in left half. Hence, the current distance would be -1. If not, the current distance would be oldDistance + 1. A similar argument can be made for right.

At the end, for each index, we can find the minimum distance to the left and right and return the minimum of both of them.

Getting the Result from the pre-computed values
For any query, we are given the value of the color and the index. We find out the minimum distance of that color in the left as well as right part. If either of them is -1, the answer is the other one. If none of them is -1, then the answer is the minimum of the two.

Time Complexity
O(n);

class Solution
{
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries);
};

vector<int> Solution :: shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries)
{
    int n = colors.size();
    
    vector<vector<int>> left (4, vector<int>(n,-1));
    vector<vector<int>> right(4, vector<int>(n,-1));
    
    for(int shade = 1; shade <= 3; shade++)
    {
        if(colors[0] == shade)
            left[shade][0] = 0;
        for(int i = 1; i < n; i++)
        {
            if(left[shade][i-1] != -1)
                left[shade][i] = left[shade][i-1] + 1;
            
            if(colors[i] == shade)
                left[shade][i] = 0;
        }
    }
    
    for(int shade = 1; shade <= 3; shade++)
    {
        if(colors[n-1] == shade)
            right[shade][n-1] = 0;
        
        for(int i = n-2; i >= 0; i--)
        {
           if(right[shade][i+1] != -1)
                right[shade][i] = right[shade][i+1] + 1;
            
            if(colors[i] == shade)
                right[shade][i] = 0;
        }
    }
    
    
    vector<int> result;
    
    for(auto query : queries)
    {
        int index = query[0];
        int req_color = query[1];
        
        int x = left[req_color][index];
        int y = right[req_color][index];
        
        int ans;
        if(x==-1 or y == -1)
            ans = max(x,y);
        else
            ans = min(x,y);
        
        result.push_back(ans);
    }
    
    
    return result;
}


class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
		vector<vector<int>>left(4, vector<int>(colors.size(), -1)), right(4, vector<int>(colors.size(), -1));
		for (int color = 1; color < 4; color++) {
			if (colors[0] == color) left[color][0] = 0;
			for (int i = 1; i < colors.size(); i++) {
				if (left[color][i-1] > -1) left[color][i] = left[color][i-1]+1;
				if (colors[i] == color) left[color][i] = 0;
			}
		}
		for (int color = 1; color < 4; color++) {
			if (colors.back() == color) right[color].back() = 0;
			for (int i = colors.size()-2; i > -1; i--) {
				if (right[color][i+1] > -1) right[color][i] = right[color][i+1]+1;
				if (colors[i] == color) right[color][i] = 0;
			}
		}
		vector<int>ans;
		int lhs, rhs;
		for (auto& it: queries) {
			lhs = left[it[1]][it[0]];
			rhs = right[it[1]][it[0]];
			if (lhs < 0 || rhs < 0)ans.push_back(max(lhs, rhs));
			if (lhs >= 0 && rhs >= 0)ans.push_back(min(lhs, rhs));
		}
		return ans;
    }
};
//the fatest solution
static auto const fast = []{return ios_base::sync_with_stdio(false);}();

#define PRINT(...)

struct a_solution
{
 vector<int>const& colors;
 int const N;
 vector<vector<int>>const& queries;

 vector<array<int,4>> prev;
 vector<array<int,4>> next;

 a_solution (vector<int>const& colors, vector<vector<int>>const& queries)
 : colors(colors)
 , N(size(colors))
 , queries(queries)
 , prev(N)
 , next(N)
 {
  int prev [4] {-1,-1,-1,-1};
  for (auto i = 0; i < N; ++i)
  {
   for (auto const& color : {1,2,3})
   {
    this->prev[i][color] = prev[color];
   }
   prev[colors[i]] = i;
   this->prev[i][colors[i]] = i;
  }
  PRINT(this->prev);
  int next [4] {-1,-1,-1,-1};
  for (auto i = N-1; i >= 0; --i)
  {
   for (auto const& color : {1,2,3})
   {
    this->next[i][color] = next[color];
   }
   next[colors[i]] = i;
   this->next[i][colors[i]] = i;
  }
  PRINT(this->next);
 }

 vector<int> solve () const
 {
  auto const M = queries.size();
  vector<int> answers(M);
  for (auto i = 0; i < M; ++i)
  {
   auto const [index,color] = tie(queries[i][0],queries[i][1]);
   auto const [p,n] = tie(prev[index][color],next[index][color]);
   auto const dp = p == -1 ? numeric_limits<int>::max() : index-p;
   auto const dn = n == -1 ? numeric_limits<int>::max() : n-index;
   answers[i] = min(dp,dn);
   if (answers[i] == numeric_limits<int>::max())
   {
    answers[i] = -1;
   };
  }
  return answers;
 }
}; // solution

struct Solution
{
 vector<int> shortestDistanceColor (vector<int>const& colors, vector<vector<int>>const& queries)
 {
  return a_solution{colors,queries}.solve();
 }
};
