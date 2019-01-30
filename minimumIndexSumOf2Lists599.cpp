class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<int>order(list1.size(),-1);
        for (int i = 0; i < list1.size(); i++) {
            for (int j = 0; j < list2.size(); j++) {
                if (list1[i].compare(list2[j]) == 0) {
                    order[i] = j+i;
                    break;
                }  
            }   
        }
        vector<string>ans;
        int min = INT_MAX;
        for (int i = 0; i < order.size(); i++) {
            if (order[i] > -1 && min > order[i]) min = order[i];
        }
        for (int i = 0; i < order.size(); i++) {
            if (min == order[i]) ans.push_back(list1[i]);
        }
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
    {
        map<string,int> restIndex1 {};
        for(auto i = 0; i < list1.size(); ++i)
        {
            restIndex1[list1[i]] = i;
        }
        vector<pair<string,int>> likedRestaurants {};
        for(auto i = 0; i < list2.size(); ++i)
        {
            auto ret = restIndex1.find(list2[i]);
            if(ret != restIndex1.end())
            {
                likedRestaurants.push_back({ret->first,i+ret->second});
            }
        }
        sort(begin(likedRestaurants), end(likedRestaurants), [](auto A, auto B){return A.second < B.second;});
        vector<string> ans {};
        auto it = begin(likedRestaurants);
        auto rank = likedRestaurants.front().second;
        while(it < end(likedRestaurants) and it->second == rank)
            ans.push_back((it++)->first);
 
        return ans;
    }
};
