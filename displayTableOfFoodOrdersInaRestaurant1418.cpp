class Solution {
public:
    bool static compare (string& a, string& b) {
        if (a.size() == b.size()) {
            return a < b;
        } else {
            return a.size() < b.size();
        }
    }
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_set<string>dish, tn;
        unordered_map<string, unordered_map<string,int>>table;
        for (auto& it: orders) {
            dish.insert(it[2]);
            tn.insert(it[1]);
            table[it[1]][it[2]]++;
        }
        vector<string>dishes(dish.begin(), dish.end());
        vector<string>tablenumber(tn.begin(), tn.end());
        sort(dishes.begin(), dishes.end());
        sort(tablenumber.begin(), tablenumber.end(), compare);
        vector<vector<string>>ans;
        vector<string>temp;
        temp.push_back("Table");
        for (string s: dishes) temp.push_back(s);
        ans.push_back(temp);
        for (string& t: tablenumber) {
            vector<string>tmp;
            tmp.push_back(t);
            for (string& d: dishes) {
                tmp.push_back(to_string(table[t][d]));
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
//the fatest solution
[[maybe_unused]] static auto const fast = []{return ios_base::sync_with_stdio(false);}();

inline namespace zm
{
 template <typename K,
           typename T,
           typename Hash      = std::hash<K>,
           typename KeyEqual  = std::equal_to<K>,
           typename Allocator = std::allocator<std::pair<const K,T>>>
 struct hashmap : std::unordered_map<K,T,Hash,KeyEqual,Allocator>
 {
  using std::unordered_map<K,T,Hash,KeyEqual,Allocator>::unordered_map;
  bool has (K const& key) const
  {
   return this->find(key) != this->end();
  }
  bool contains (K const& key) const
  {
   return this->has(key);
  }
 };
}

struct a_solution
{
 hashmap<string_view,hashmap<string_view,int>> tables;

 a_solution (vector<vector<string>>const& orders)
 {
  for (auto&& order : orders)
  {
   auto&& [table,food] = tie(order[1],order[2]);
   ++tables[table][food];
  }
 }

 vector<vector<string>> solve () const
 {
  auto const less = [&](auto&&x,auto&&y){return atoi(x.data())<atoi(y.data());};
  set<string_view,decltype(less)> tables(less);
  for (auto&& [table,_] : this->tables)
  {
   tables.emplace(table);
  }

  set<string_view> foods;
  for (auto&& [_,values] : this->tables)
  {
   for (auto&& [food,_] : values)
   {
    foods.emplace(food);
   }
  }

  vector<string> header{"Table"};
  for (auto&& food : foods)
  {
   header.emplace_back(food);
  }

  hashmap<string_view,int> foodids;
  for (auto&& food : foods)
  {
   auto const index = foodids.size()+1;
   foodids[food] = index;
  }

  vector<vector<string>> display{move(header)};
  for (auto&& table : tables)
  {
   display.push_back(vector<string>(foods.size()+1,"0"));
   display.back()[0] = table;
   for (auto&& [food,count] : this->tables.at(table))
   {
    display.back()[foodids[food]] = to_string(count);
   }
  }

  return display;
 }
};

struct Solution
{
 vector<vector<string>> displayTable (vector<vector<string>>const& orders)
 {
  return a_solution{orders}.solve();
 }
};
