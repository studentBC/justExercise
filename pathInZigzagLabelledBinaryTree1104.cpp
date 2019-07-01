class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = 0, count = 1, sum = 0, lv = 0, j;
        while (sum < label) {
            sum+=pow(2,lv);
            lv++; 
        }
        vector<vector<int>>tree;
        while (level < lv) {
            vector<int>temp(pow(2,level),0);
            //cout <<endl << temp.size() <<" at level " << level <<endl;
            if (level%2) {
                for (int i = temp.size()-1; i > -1; i--) {
                    temp[i] = count;
                    //cout << count <<" , ";
                    count++;
                }
            } else {
                for (int i = 0; i < temp.size(); ++i) {
                    temp[i] = count;
                    //cout << count <<" , ";
                    count++;
                }
            }
            level++;
            tree.emplace_back(temp);
        }   
        level--;
        for (int i = 0; i < tree[level].size(); ++i) {
            if (tree[level][i] == label) {
                j = i;
                break;
            }
        }
        //cout <<"find at " << level <<" , " << j << endl;
        vector<int>ans;
        ans.emplace_back(label);
        while (level > 0) {
            level--;
            if (j%2) {
                j = (j-1) >> 1;
                ans.emplace_back(tree[level][j]);
            } else { 
                j = j >> 1;
                ans.emplace_back(tree[level][j]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
//the fatest method
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        result.push_back(label); //taking bottom up approach, so the label itself must be included 
        int height=log2(label); //height of label from root
        
        while(height!=0){
            int left=pow(2,height-1); // rank of left limit of the previous level 
            int right=pow(2,height)-1;// rank of right limit of the previous level
            label=left+(right-label/2);// as the previous level is sorted in different order than current one.
                                       //So the new label is adjusted accordingly
            result.push_back(label);  //newly found label is appened to result
            height--;
        }
        
        reverse(result.begin(),result.end()); //required top to down, so the array is reversed. 
        return result;
    }
};
