/*
Given a rows x cols screen and a sentence represented by a list of non-empty words, find how many times the given sentence can be fitted on the screen.

Note:

A word cannot be split into two lines.
The order of words in the sentence must remain unchanged.
Two consecutive words in a line must be separated by a single space.
Total words in the sentence won't exceed 100.
Length of each word is greater than 0 and won't exceed 10.
1 ≤ rows, cols ≤ 20,000.
Example 1:

Input:
rows = 2, cols = 8, sentence = ["hello", "world"]

Output: 
1

Explanation:
hello---
world---

The character '-' signifies an empty space on the screen.
Example 2:

Input:
rows = 3, cols = 6, sentence = ["a", "bcd", "e"]

Output: 
2

Explanation:
a-bcd- 
e-a---
bcd-e-

The character '-' signifies an empty space on the screen.
Example 3:

Input:
rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]

Output: 
1

Explanation:
I-had
apple
pie-I
had--

The character '-' signifies an empty space on the screen.
wrong test case:
["a","b"]
20000
20000

["a","b","c"]
3
1

concept:
Explanation:

Say sentence=["abc", "de", "f], rows=4, and cols=6.
The screen should look like

"abc de"
"f abc "
"de f  "
"abc de"
Consider the following repeating sentence string, with positions of the start character of each row on the screen.

"abc de f abc de f abc de f ..."
 ^      ^     ^    ^      ^
 0      7     13   18     25
Our goal is to find the start position of the row next to the last row on the screen, which is 25 here. Since actually it's the length of everything earlier, we can get the answer by dividing this number by the length of (non-repeated) sentence string. Note that the non-repeated sentence string has a space at the end; it is "abc de f " in this example.

Here is how we find that position. In each iteration, we need to adjust start based on spaces either added or removed.

"abc de f abc de f abc de f ..." // start=0
 012345                          // start=start+cols+adjustment=0+6+1=7 (1 space removed in screen string)
        012345                   // start=7+6+0=13
              012345             // start=13+6-1=18 (1 space added)
                   012345        // start=18+6+1=25 (1 space added)
                          012345
Let me explain a little to help others understand this solution well.

String s = String.join(" ", sentence) + " " ;. This line gives us a formatted sentence to be put to our screen.
start is the counter for how many valid characters from s have been put to our screen.
if (s.charAt(start % l) == ' ') is the situation that we don't need an extra space for current row. The current row could be successfully fitted. So that we need to increase our counter by using start++.
The else is the situation, which the next word can't fit to current row. So that we need to remove extra characters from next word.
start / s.length() is (# of valid characters) / our formatted sentence.
 */
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string target;
        for (string s:sentence) {
            target+=s;
            target+=" ";
        }
        int start = 0, l = target.size();
        for (int i = 0; i < rows; i++) {
            start+= cols;
            if (target[start%l] == ' ') {
                start++;
            } else {
                while (start && target[(start-1)%l] != ' ') start--;
            }
        }
        return start/target.size();
    }
};
//the fatest solution
class Solution {
  int cols;
  //     <endCol, rowInc>
  vector<pair<int, int>> cache;

  // pair<nextCol, rowInc>
  pair<int, int> placeSentence(int c0, const vector<string>& sentence) {
    //cout << "[" << __LINE__ << "] c0=" << c0 << "\n";

    // Memoization
    if (cache[c0].first != -1) 
      return cache[c0];

    int c = c0; 
    int r = 0;
    for (const string& w: sentence) {
      //cout << "[" << __LINE__ << "] c=" << c << " r=" << r << " w=" << w << " cols=" << cols << "\n";

      // Add a space when needed
      if (c > 0) {
        c ++; 
        if (c == cols) {
          r ++; 
          c = 0;
        }   
      }   
      c += w.size();
      if (c == cols) {
        r ++; 
        c = 0;
      } else if (c > cols) {
        r ++; 
        c = w.size();

        if (c == cols) {
          r ++; 
          c = 0;
        } else if (c > cols) {
          c = -1; 
          break;
        }   
      }

      //cout << "[" << __LINE__ << "] c=" << c << " r=" << r << "\n";
    }   

    //cout << "[" << __LINE__ << "] c=" << c << " rInc=" << r << "\n";
    /*  
             01234
    sentence=f p a
    rows=8 cols=7

    0123456
    f p a*
          f
    p a*

    c0=0 c=5 rInc=0
    c0=5 c=5 rInc=1
           * This should be 3.
    */

    cache[c0] = {c, r}; 
    return {c, r}; 
  }

public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    if (0) {
      cout << "[" << __LINE__ << "] sentence=";
      copy(sentence.begin(), sentence.end(), ostream_iterator<string>(cout, " "));
      cout << "\n";
      cout << "[" << __LINE__ << "] rows=" << rows << " cols=" << cols << "\n";
    }   

    this->cols = cols;
    int cnt = 0;
    // Current corsor position
    int c = 0;
    int r = 0;

    cache = vector<pair<int, int>>(cols, {-1, -1});
    
    int sentLen = 0;
    for (const string& w: sentence) {
      if (sentLen > 0)
        sentLen ++;
      sentLen += w.size();
    }

    //hashmap<c, <r, cnt>> rowCache;
    //unordered_map<c, <r, cnt>> rowCache;
    vector<pair<int, int>> rowCache(cols, {-1, -1});

    while (true) {
      // We can do multi-row optimization too
      //   How many rows does it take to get the same c and different r?
      rowCache[c] = {r, cnt};

      // Fit multiple sentences when they can starting from the current cursor position
      while (sentLen <= cols - c) {
        if (c == 0) {
          c += sentLen;
          cnt ++;
        } else {
          int colsAvail = cols - c;
          int numSents = colsAvail / (1 + sentLen);
          if (numSents == 0)
            break;
          c += numSents * (1 + sentLen);
          cnt += numSents;
        }
      }
      if (c == cols) {
        r ++; 
        c = 0;
      }  

      auto r1 = placeSentence(c, sentence);
      c = r1.first;
      if (c == -1)
        return 0;
      int rInc = r1.second;
      r += rInc;
      if (r >= rows)
        break;
      cnt ++;

      if (rowCache[c].first != -1) {
        int rPrev = rowCache[c].first;
        int cntPrev = rowCache[c].second;

        if (r - rPrev > 0 && r + (r - rPrev) <= rows) {
          int rowsAvail = rows - r;
          if (c > 0)
            rowsAvail --;
          if (rowsAvail > 0) {
            int numRowBlocks = rowsAvail / (r - rPrev);
            if (numRowBlocks > 0) {
              cnt += (numRowBlocks * (cnt - cntPrev));
              r += (numRowBlocks * (r - rPrev));
            }
          }
        }
      }
    }
    if (c == 0 && r == rows)
      cnt ++;

    return cnt;
  }
};
