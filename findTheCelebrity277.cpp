/*
Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n). There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.*/ 
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<vector<int>>graph(n, vector<int>(n,1));
        vector<int>candidate;
        bool know;
        for (int i = 0; i < n; i++) {
            know = false;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (knows(i,j)) {
                        graph[i][j] = 1;
                        know = true;
                    } else {
                        graph[i][j] = 0;
                    }
                }
            }
            if (!know) {
                candidate.emplace_back(i);
            }
        }
        for (int i = 0; i < candidate.size(); i++) {
            know = true;
            for (int j = 0; j < n; j++) {
                if (!graph[j][candidate[i]]) {
                    know = false;
                    break;
                }
            }
            if (know) {
                return candidate[i];
            }
        }
        return -1;
    }
};
//the fatest method
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(candidate, i)) candidate = i;
        }

        for (int i = 0; i < n; ++i) {
            if (i == candidate) continue;
            if (!knows(i, candidate) or knows(candidate, i)) return -1;
        }
        return candidate;
    }
    
    /*int findCelebrity(int n) {
        unordered_set<int> people;
        unordered_set<int> celebrity;
        vector<unordered_set<int>> knownByOthers(n, unordered_set<int>());
        vector<bool> visited(n, false);
        
        int cur = 0;
        while((people.size() + celebrity.size()) < n) {
            bool not_found = false;
            for(int i = 0; i < n; ++i) {
                visited[cur] = true;
                if(i != cur) {
                    if(knows(cur, i)) {
                        knownByOthers[i].insert(cur);
                        people.insert(cur);
                        cur = i;
                        not_found = true;
                        break;
                    }
                    else{
                        visited[i] = true;
                        people.insert(i);
                    }
                }
            }
            if(!not_found)
                celebrity.insert(cur);
            if(visited[cur]) {
                for(int i = 0; i < n; ++i)
                    if(!visited[i])
                        cur = i;
            }
        }
        
        if(celebrity.size() > 1 || celebrity.size() == 0)
            return -1;
        
        int res = *celebrity.begin();
        for(int i = 0; i < n; ++i) {
            if(i != res && knownByOthers[res].count(i) == 0)
                if(!knows(i, res))
                    return -1;
        }
        
        return res;
    }*/
};
