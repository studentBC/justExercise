/*
There are n people in a social group labeled from 0 to n - 1. You are given an array logs where logs[i] = [timestampi, xi, yi] indicates that xi and yi will be friends at the time timestampi.

Friendship is symmetric. That means if a is friends with b, then b is friends with a. Also, person a is acquainted with a person b if a is friends with b, or a is a friend of someone acquainted with b.

Return the earliest time for which every person became acquainted with every other person. If there is no such earliest time, return -1.

 

Example 1:

Input: logs = [[20190101,0,1],[20190104,3,4],[20190107,2,3],[20190211,1,5],[20190224,2,4],[20190301,0,3],[20190312,1,2],[20190322,4,5]], n = 6
Output: 20190301
Explanation: 
The first event occurs at timestamp = 20190101 and after 0 and 1 become friends we have the following friendship groups [0,1], [2], [3], [4], [5].
The second event occurs at timestamp = 20190104 and after 3 and 4 become friends we have the following friendship groups [0,1], [2], [3,4], [5].
The third event occurs at timestamp = 20190107 and after 2 and 3 become friends we have the following friendship groups [0,1], [2,3,4], [5].
The fourth event occurs at timestamp = 20190211 and after 1 and 5 become friends we have the following friendship groups [0,1,5], [2,3,4].
The fifth event occurs at timestamp = 20190224 and as 2 and 4 are already friends anything happens.
The sixth event occurs at timestamp = 20190301 and after 0 and 3 become friends we have that all become friends.
Example 2:

Input: logs = [[0,2,0],[1,0,1],[3,0,3],[4,1,2],[7,3,1]], n = 4
Output: 3
 

Constraints:

2 <= n <= 100
1 <= logs.length <= 104
logs[i].length == 3
0 <= timestampi <= 109
0 <= xi, yi <= n - 1
xi != yi
All the values timestampi are unique.
All the pairs (xi, yi) occur at most one time in the input.
*/

class Solution {
public:
    class UnionFind {

        public:
            vector<int>id;
            UnionFind(int n): id(n) {
                iota(begin(id), end(id), 0);
            }
            void connect (int a, int b) {
                id[find(b)] = find(a);
            }
            int find(int i) {
                return id[i] == i? i : (id[i] = find(id[i]));
            }
            bool connected (int a, int b) {
                return find(a) == find(b);
            }
            void reset(int i) {
                id[i] = i;
            }
	};
    int earliestAcq(vector<vector<int>>& logs, int n) {
        UnionFind uf(n);
        unordered_set<int>uniq;
        int critical = n/2+2;
        sort(logs.begin(), logs.end());
        for (int i = 0; i < logs.size(); i++) {
            //cout << logs[i][0] << endl;
            uf.connect(logs[i][1], logs[i][2]);
            uniq.clear();
            for (int i : uf.id) {
                uniq.insert(i);
                //cout << i <<", ";
            }
            //cout << endl;
            if (uniq.size() == 1){
                return logs[i][0];
            } else if (uniq.size() < critical) {
                vector<int>tmp;
                //cout <<"inside tmp " << endl;
                for (int i : uniq) {
                    //cout << i <<", ";
                    tmp.push_back(i);
                }
                bool valid = true;
                for (int j = tmp.size()-1; j > 0; j--) {
                    if (!uf.connected(tmp[j], tmp[j-1])) {
                        valid = false;
                        break;
                    }
                }
                if (valid)return logs[i][0];
            }
            //return logs[i][0];
        }
        return -1;
    }
};
//19 ms solution
class Solution {
public:
     static bool tsCmp(vector<int> &v1, vector<int> &v2) {
        return v1[0] < v2[0];
    }
    int find(int a,vector<int>&pa)
    {
        if(pa[a]==-1)
        {
            return a;
        }
        return pa[a]=find(pa[a],pa);
    }
    int dunion(int a,int b,vector<int>&pa,vector<int>&o)
    {
       int s1=find(a,pa);
        int s2=find(b,pa);
        if(s1!=s2)
        {
            if(o[s1]<o[s2])
            {
                pa[s1]=s2;
                o[s2]+=o[s1];
            }
            else
            {
                pa[s2]=s1;
                o[s1]+=o[s2];
            }
        }
        return max(o[s1],o[s2]);
    }
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end(),tsCmp);
        vector<int>parent(n);
         for (int i = 0; i < n; i++) {
            parent[i] = -1;
        }
        vector<int>order(n,1);
        for (vector<int> &eachLog : logs) {
            if (dunion(eachLog[1], eachLog[2], parent, order) == n)               {
                return eachLog[0];
            }
        }
        return -1;
    }
};
/*
To visualize the final relationships, we draw the following graph, where each node represents an individual and the link between nodes represents the friendship relationship between two individuals. In addition, the label on top of the link indicates the moment when two individuals become friends.

graph

As one can see, at the timestamp 4, eventually everyone gets to know each other. Note that, the connections of 3 and 5 do not contribute to the overall connections among the friends. They are redundant connections, as we discussed before. To highlight them, we mark the connections with a dashed line.

Now, given the above example, we show step by step how our Union-Find algorithm works.

Initially, we have four groups, where each individual is a group itself. We use a directed link to point to the group that an individual belongs to. We show them in the following graph.
graph

Starting from the first event (1, A, B), we merge the groups of A and B together with the union(A, B) function. By merging, we assign the group of either A or B to the other one. As a result, the merged group (A, B) contains two elements. The total number of groups is now reduced to three.
graph

With the event (2, B, C), we then merge the group of (A, B) with the group of (C) together. To optimize the merging operations, we merge a smaller group (i.e. the one with smaller rank value) into a larger group. Therefore, we merge the group of (C) into the group of (A, B). The total number of groups is now reduced to two. Note: The keen observer will notice that C should actually point to A because of the effects of union by rank, but the main point here is that C has now joined the group with A and B. For simplicity, we will point C to B.
graph

With the event (3, A, C), as it turns out, the individuals A and C already belong to the same group. Therefore, no merging operation is needed. The landscape of groups remains the same.
graph

Finally with the event (4, C, D), we merge the group of (D) into the group of (A, B, C). The total number of groups is reduced to one. And this is the earliest moment when everyone becomes friends.
graph

Complexity Analysis

Since we applied the Union-Find data structure in our algorithm, we would like to start with a statement on the time complexity of the data structure, as follows:

Statement: If MM operations, either Union or Find, are applied to NN elements, the total run time is O(M \cdot \alpha(N))O(M⋅α(N)), where \alpha (N)α(N) is the Inverse Ackermann Function.

One can refer to this article on Union-Find complexity for more details.

In our case, the number of elements in the Union-Find data structure is equal to the number of people, and the number of operations on the Union-Find data structure is up to the number of logs.

Let NN be the number of people and MM be the number of logs.

Time Complexity: O(N + M \log M + M \alpha (N))O(N+MlogM+Mα(N))

First of all, we sort the logs in the order of timestamp. The time complexity of (quick) sorting is O(M \log M)O(MlogM).

Then we created a Union-Find data structure, which takes O(N)O(N) time to initialize the array of group IDs.

We then iterate through the sorted logs. At each iteration, we invoke the union(a, b) function. According to the statement we made above, the amortized time complexity of the entire process is O(M \alpha (N))O(Mα(N)).

To sum up, the overall time complexity of our algorithm is O(N+MlogM+Mα(N)).

Space Complexity: O(N + M)O(N+M) or O(N + \log M)O(N+logM)

The space complexity of our Union-Find data structure is O(N)O(N), because we keep track of the group ID for each individual.

The space complexity of the sorting algorithm depends on the implementation of each program language.

For instance, the list.sort() function in Python is implemented with the Timsort algorithm whose space complexity is O(M)O(M). While in Java, the Arrays.sort() is implemented as a variant of quicksort algorithm whose space complexity is O(\log{M})O(logM).

To sum up, the overall space complexity of the algorithm is O(N+M) for Python and O(N+logM) for Java.
*/ 

// official solution
class Solution {
    public int earliestAcq(int[][] logs, int n) {

        // First, we need to sort the events in chronological order.
        Arrays.sort(logs, new Comparator<int[]>() {
            @Override
            public int compare(int[] log1, int[] log2) {
                Integer tsp1 = new Integer(log1[0]);
                Integer tsp2 = new Integer(log2[0]);
                return tsp1.compareTo(tsp2);
            }
        });

        // Initially, we treat each individual as a separate group.
        int groupCount = n;
        UnionFind uf = new UnionFind(n);

        for (int[] log : logs) {
            int timestamp = log[0], friendA = log[1], friendB = log[2];

            // We merge the groups along the way.
            if (uf.union(friendA, friendB)) {
                groupCount -= 1;
            }

            // The moment when all individuals are connected to each other.
            if (groupCount == 1) {
                return timestamp;
            }
        }

        // There are still more than one groups left,
        //  i.e. not everyone is connected.
        return -1;
    }
}
class UnionFind {
    private int[] group;
    private int[] rank;//rank here means the number of people in this group

    public UnionFind(int size) {
        this.group = new int[size];
        this.rank = new int[size];
        for (int person = 0; person < size; ++person) {
            this.group[person] = person;
            this.rank[person] = 0;
        }
    }

    /** Return the id of group that the person belongs to. */
    public int find(int person) {
        if (this.group[person] != person)
            this.group[person] = this.find(this.group[person]);
        return this.group[person];
    }

    /**
     * If it is necessary to merge the two groups that x, y belong to.
     * @return true: if the groups are merged.
     */
    public boolean union(int a, int b) {
        int groupA = this.find(a);
        int groupB = this.find(b);
        boolean isMerged = false;

        // The two people share the same group.
        if (groupA == groupB)
            return isMerged;

        // Otherwise, merge the two groups.
        isMerged = true;
        // Merge the lower-rank group into the higher-rank group.
        if (this.rank[groupA] > this.rank[groupB]) {
            this.group[groupB] = groupA;
        } else if (this.rank[groupA] < this.rank[groupB]) {
            this.group[groupA] = groupB;
        } else {
            this.group[groupA] = groupB;
            this.rank[groupB] += 1;
        }

        return isMerged;
    }
}
