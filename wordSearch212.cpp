class Solution {
public:
    void find (int i , int j , int k, string words, bool& found,  vector<vector<char>>& board, vector<pair<int,int>>&visited) {
        if (!found && i < board.size() && j < board[0].size() && i>=0 && j>=0 &&  board[i][j] == words[k] && k<words.size()) {
            //cout << words[k];
            pair<int,int> temp = make_pair(i,j);
            for (int i = 0; i < visited.size(); i++) {
                if (visited[i].first == temp.first && visited[i].second == temp.second) {
                    //cout <<"erase: " << temp.first << " , " << temp.second << endl;
                    //visited.erase(visited.begin()+i);
                    return;
                }  
            }
            visited.push_back(temp);
            if (k == words.size()-1 ) {
                //cout << "yes we found: " << words << endl;
                found = true;
            }
        } else {
            return;
        }
        //cout <<" location is:" << i<<" , "<< j  << " go find " << k+1 << endl;
        find (i+1,j,k+1,words,found,board,visited);
        //cout <<" location is:" << i<<" , "<< j  << " go find " << k+1 << endl;
        find (i,j+1,k+1,words,found,board,visited);
        //cout <<" location is:" << i<<" , "<< j  << " go find " << k+1 << endl;
        find (i-1,j,k+1,words,found,board,visited);
        //cout <<" location is:" << i<<" , "<< j  << " go find " << k+1 << endl;
        find (i,j-1,k+1,words,found,board,visited);
        //cout <<" location is:" << i<<" , "<< j  << " go find " << k+1 << endl;
        /*
        if (k+1 <= words.size() && !found) {
        cout <<" location is:" << i<<" , "<< j  << " cant find " << k+1 << endl;
            surrounded = true;
        }*/
        visited.pop_back();
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>ans;
        unordered_set<string>input;
        vector<pair<int,int>>visited;
        for (int i = 0; i < words.size(); i++) input.insert(words[i]);
        bool found;
        for (const string& k : input) {
            found = false;
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) {
                    if (k[0] == board[i][j]) {
                        visited.clear();
                        find (i,j,0,k,found,board,visited);
                        if (found) {
                            ans.push_back(k);
                            break;
                        }
                    }
                }
                if (found)break;
            }
        }
        return ans;
    }
};
//the fatest method
static int __________ = []()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); return 0;
}();

template<typename T>
struct AlignedStore {
    using Data = typename std::aligned_storage<sizeof(T), alignof(T)>::type;
    Data mem[1024*512];
    T* get(int index){ return reinterpret_cast<T*>(&mem[index]); }
};

class Solution {
    
    struct Node {
        Node* children[26] = {};
        char value  = {};
        bool isLast = false;
    };
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(!board.size()) return {};
        std::vector<std::string> ans; ans.reserve(1024);
        auto trie = getTrie(words);
        std::string stx; stx.reserve(1024);
        for(int row = 0; row < board.size(); row++)
            for(int col = 0; col < board[row].size(); col++)
                recurse(board, ans, trie, stx, row, col);
        return std::vector<std::string>(ans.begin(), ans.end());
    }
    
    void recurse(vector<vector<char>>& board, std::vector<string>& rslt, const Node* root, std::string& stx, int row, int col){
        const int R = board.size();
        const int C = board[0].size();
        if(!root || row >= R || row < 0 || col < 0 || col >= C) return;
        const char val                    = board[row][col];
        if(val == 0) return;
        const Node* node = root->children[val - 'a'];
        if(!node) return;
        
        board[row][col] = 0;
        stx.push_back(val);
        
        //Top
        recurse(board, rslt, node, stx,  row-1, col);
        recurse(board, rslt, node, stx, row, col-1);
        recurse(board, rslt, node, stx, row, col+1);
        recurse(board, rslt, node, stx, row+1, col);
        
        if(node->isLast) { if (std::find(rslt.begin(), rslt.end(), stx) == rslt.end()) rslt.push_back(stx); }
        stx.pop_back();
        board[row][col] = val;
    }
    
    Node* getTrie(const vector<string>& words){
        auto idx = 0;
        auto store = new AlignedStore<Node>;
        auto root = new(store->get(idx++)) Node{{}, '0', false};
        for(auto word : words){
            auto child = root;
            for(auto ch : word){
                if(!child->children[ch - 'a']){
                    child->children[ch - 'a'] = new(store->get(idx++)) Node{{}, ch, false};
                }
                child = child->children[ch - 'a'];
            }
            child->isLast = true;
        }
        return root;
    }
};
