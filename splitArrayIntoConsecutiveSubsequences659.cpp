/*
Intuition

From the above discussion, it is clear that first of all, we need to consider ways to store the subsequences created so far. We can use a list of lists to store each subsequence. But wait, do we need to store the entire subsequence? Give it a thought.

Well, we need only the metadata of each subsequence. We know the subsequence consists of consecutive increasing numbers. So isn't it enough to know the first and the last element in the subsequence? We can also find the length of the subsequence from this information: last - first + 1. We can store this information in an array of size 2.

Now that we have found out a possible way to store each subsequence, the next question is the order. As discussed earlier, at ithi ^ {th}i 
th
  index, nums[i] has two options - to be a part of any existing subsequence or to start a new subsequence. If we choose the first option, it will be a part of a subsequence whose last element value is nums[i] - 1. How can we find such a subsequence easily? By sorting subsequences in increasing order of their last element. Have doubt in believing this? Please refer to the intuition part again.

Now the next question is, what if the last element is the same for two or more subsequences? (Yes, it is possible, consider {0, 1, 1, 2, 2, 3}). In this case, at 5th5 ^ {th}5 
th
  index, 3 has two subsequences that it can be a part of: {0, 1, 2}, {1, 2}. But if it becomes a part of the first subsequence, the second subsequence will become invalid and we will return false. However, the answer should be true. How? By appending 3 to the second subsequence, we will get two valid subsequences: {0, 1, 2} and {1, 2, 3}. So what can we keep in mind from this example? Yes, we got the answer to the previously asked question, i.e., if the last element is the same for two or more subsequences, sort the subsequences based on the increasing order of their size.

Now when it comes to storing arrays in a sorted manner, what's the first thing that comes to your mind? Heaps. So can we use a heap in this use case? Let's try to use one. The heap will store 1D arrays of size 2 comprising of the first and the last element of each subsequence. The arrays in the heap will be stored based on two conditions:

Increasing order of their last element.
When the subsequences' last elements are equal, then the two subsequences will be placed in increasing order of length.
For each element (nums[i]) we compare the element with the last element (last = subsequences.peek()[1]) of the existing subsequences in the heap one by one. There can be only 3 conditions:

nums[i] > last + 1: nums[i] cannot be a part of this subsequence. So we remove this subsequence from the heap and compare nums[i] with the next subsequence in the heap.
nums[i] == last (or the heap is empty): nums[i] cannot be a part of this subsequence either. As the subsequences are stored in increasing order of their last element in the heap, there will be no other subsequences in the heap to append nums[i]. So the only way here is to start a new subsequence with nums[i] as the only element.
nums[i] == last + 1: we add nums[i] to this subsequence. As the subsequences with equal last elements are stored in increasing order of their length, this current subsequence will be the shortest subsequence ending with nums[i] - 1.



Algorithm

Create a heap to store 1D arrays with the required conditions. Each array is of size 2 and represents a subsequence. We store the first and the last element of each subsequence in the array.

Iterate over the nums array.

Compare the last element of each existing subsequence in the heap with the current element num. If the last element is smaller than num - 1, we cannot add num or any future element to that subsequence. So we remove it from the heap. While removing, check if its length is greater than or equal to 3. If not, return false.

If the heap is empty or the last element of the first subsequence in the heap is equal to num, create a new subsequence with num as the only element and add it to the heap.

If there exists a valid subsequence of which num can be a part of, add num to it. If there are multiple valid subsequences, choose the subsequence with the smallest length possible.

Check the length of all the subsequences present in the heap. If any of them is of length less than 3, return false. Otherwise, return true.
*/
class Solution {
public:
    struct compare {
        bool operator() (array<int, 2> a1, array<int, 2>a2) {
            if (a1[1] == a2[1]) return (a1[1]-a1[0]) > (a2[1]-a2[0]);
            return a1[1] > a2[1];
        }
    };
    bool isPossible(vector<int>& nums) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, compare>pq;
        int len;
        for (int n : nums) {
            while(!pq.empty() && pq.top()[1] + 1 < n) {
                array<int, 2> cur = pq.top();
                pq.pop();
                len = cur[1]-cur[0]+1;
                if (len < 3) return false;
            }
            if (pq.empty() || pq.top()[1] == n) pq.push({n, n});
            else {
                array<int, 2> curseq = pq.top();
                pq.pop();
                pq.push({curseq[0], n});
            }
        }
        while (!pq.empty()) {
            array<int, 2> curseq = pq.top();
            pq.pop();
            len = curseq[1] - curseq[0] +1;
            if (len < 3) return false;
        }
        return true;
    }
};
