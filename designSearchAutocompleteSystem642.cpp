/*
Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#'). For each character they type except '#', you need to return the top 3 historical hot sentences that have prefix the same as the part of sentence already typed. Here are the specific rules:

    The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
    The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same degree of hot, you need to use ASCII-code order (smaller one appears first).
    If less than 3 hot sentences exist, then just return as many as you can.
    When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.

Your job is to implement the following functions:

The constructor function:

AutocompleteSystem(String[] sentences, int[] times): This is the constructor. The input is historical data. Sentences is a string array consists of previously typed sentences. Times is the corresponding times a sentence has been typed. Your system should record these historical data.

Now, the user wants to input a new sentence. The following function will provide the next character the user types:

List<String> input(char c): The input c is the next character typed by the user. The character will only be lower-case letters ('a' to 'z'), blank space (' ') or a special character ('#'). Also, the previously typed sentence should be recorded in your system. The output will be the top 3 historical hot sentences that have prefix the same as the part of sentence already typed.
 

Example:
Operation: AutocompleteSystem(["i love you", "island","ironman", "i love leetcode"], [5,3,2,2])
The system have already tracked down the following sentences and their corresponding times:
"i love you" : 5 times
"island" : 3 times
"ironman" : 2 times
"i love leetcode" : 2 times
Now, the user begins another search:

Operation: input('i')
Output: ["i love you", "island","i love leetcode"]
Explanation:
There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored.

Operation: input(' ')
Output: ["i love you","i love leetcode"]
Explanation:
There are only two sentences that have prefix "i ".

Operation: input('a')
Output: []
Explanation:
There are no sentences that have prefix "i a".

Operation: input('#')
Output: []
Explanation:
The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search.
 

Note:

    The input sentence will always start with a letter and end with '#', and only one blank space will exist between two words.
    The number of complete sentences that to be searched won't exceed 100. The length of each sentence including those in the historical data won't exceed 100.
    Please use double-quote instead of single-quote when you write test cases even for a character input.
    Please remember to RESET your class variables declared in class AutocompleteSystem, as static/class variables are persisted across multiple test cases. Please see here for more details.

wrong test case:
["AutocompleteSystem","input","input","input","input","input","input","input","input","input","input","input","input","input","input"]
[[["abc","abbc","a"],[3,3,3]],["b"],["c"],["#"],["b"],["c"],["#"],["a"],["b"],["c"],["#"],["a"],["b"],["c"],["#"]]


*/
class AutocompleteSystem {
public:
    static bool compare (pair<string,int>& a, pair<string,int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        } else {
            return a.second > b.second;
        }
    }
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        hotdegree.clear();
        temp="";
        for (int i = 0; i < sentences.size(); i++) {
            hotdegree.emplace_back(pair<string,int>(sentences[i],times[i]));
        }
        sort(hotdegree.begin(),hotdegree.end(),compare);
    }
    vector<string> input(char c) {
        response.clear();
        if (c != '#')temp+=c;
        //cout <<"search  word: "<<temp<<endl;
        bool match;int count = 0;
        /*for (int i = 0; i < hotdegree.size(); i++) {
            cout <<hotdegree[i].first<<" , ";
        }*/
        //cout << endl;
        for (int i = 0; i < hotdegree.size(); i++) {
            if (hotdegree[i].first.size() >= temp.size()) {
                match = true;
                for (int j = 0; j < temp.size(); j++) {
                    if (hotdegree[i].first[j] != temp[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    //cout <<"found: "<< hotdegree[i].first<<" , "<< endl;
                    response.emplace_back(hotdegree[i].first);
                    count++;
                    if (count == 3) {
                        break;
                    }
                }
            }
        }
        if (c == '#') {
            match = false;
            for (int i = 0; i < hotdegree.size(); i++) {
                if (hotdegree[i].first == temp) {
                    hotdegree[i].second++;
                    match = true;
                    break;
                }
            }
            if (!match) {
                //cout<< endl <<"insert: "<< temp << endl;
                hotdegree.emplace_back(pair<string,int>(temp,1));
            }
            sort(hotdegree.begin(),hotdegree.end(),compare);
            temp="";
            return {};
        }
        return response;
    }
private:
    vector<pair<string,int>>hotdegree;
    string temp = "";
    vector<string>response;
};


/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
//the fatest method
class AutocompleteSystem {
    // Brute-force method. Use a hash map to keep the mapping of word and times, Space complexity O(N)
    unordered_map<string, int> counters;
    string curInput;
    // Hold the candidates. Need to rank these words in reverse order to let pop() filter out the uncommon ones
    struct Comp {
        bool operator()(const pair<string, int>& left, const pair<string, int>& right) {
            return left.second > right.second || ((left.second == right.second) && (left.first < right.first));
        }
    } comp;
    vector<pair<string, int>> current; // Hold the results so far

public:
    // Consctruct the hash map. Time complexity would be O(N*L). L is the length of words
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (size_t idx = 0; idx < sentences.size(); ++idx) counters[sentences[idx]] += times[idx];
    }
    
    // Give the search suggestion. Time complexity would be O(N+NlogN). O(N) is used to collect and compare to the candidates
    // O(NlogN) is used to sort the results in vector
    vector<string> input(char c) {
        if ('#' == c)  { // User inputs a complete word Insert into hash map and clear the cached input
            ++counters[curInput];
            curInput.clear();
            current.clear();
            return vector<string>{};
        }
        curInput += c; // Traverse the hash map to construct the list of candidates at first char
        if (curInput.size() == 1) {
            for (auto& word : counters)
                if (word.first[0] == curInput[0]) current.emplace_back(word);
            std::sort(current.begin(), current.end(), comp);
        }
        else { // Use a temp vector to keep the candidates filtered by new input
            vector<pair<string, int>> temp;
            for (auto& word : current)
                if (word.first.find(curInput) == 0) temp.emplace_back(word.first, word.second);
            current.swap(temp); // Refresh the cached candidates
        }
        vector<string> result;// Fill in the result
        for (size_t idx = 0; idx < current.size() && idx < 3; ++idx)
            result.emplace_back(current[idx].first);
        return result;
    }
};
