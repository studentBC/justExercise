/*
Given a rows x cols screen and a sentence represented as a list of strings, return the number of times the given sentence can be fitted on the screen.

The order of words in the sentence must remain unchanged, and a word cannot be split into two lines. A single space must separate two consecutive words in a line.

 

Example 1:

Input: sentence = ["hello","world"], rows = 2, cols = 8
Output: 1
Explanation:
hello---
world---
The character '-' signifies an empty space on the screen.
Example 2:

Input: sentence = ["a", "bcd", "e"], rows = 3, cols = 6
Output: 2
Explanation:
a-bcd- 
e-a---
bcd-e-
The character '-' signifies an empty space on the screen.
Example 3:

Input: sentence = ["i","had","apple","pie"], rows = 4, cols = 5
Output: 1
Explanation:
i-had
apple
pie-i
had--
The character '-' signifies an empty space on the screen.
 

Constraints:

1 <= sentence.length <= 100
1 <= sentence[i].length <= 10
sentence[i] consists of lowercase English letters.
1 <= rows, cols <= 2 * 104



Imagine an infinite sentence that are concatenated by words from the given sentence, infiStr. We want to cut the infiStr properly and put a piece at each row of the screen.
We maintain a pointer ptr. The ptr points to a position at infiStr, where next row will start. Cutting the infiStr and putting a piece at a row can be simulated as advancing the pointer by cols positions.
After advancing the pointer, if ptr points to a space, it means the piece can fit in row perfectly. If ptr points to the middle of a word, we must retreat the pointer to the beginning of the word, because a word cannot be split into two lines.


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
*/
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string line;
        for (string& s : sentence) {
            line+=s;
            line+=" ";
        }
        int start = 0, len = line.size();
        for (int i = 0; i < rows; i++) {
            start+=cols;
            if (line[start%len] == ' ') start++;
            else {
                while (start > 0 && line[(start-1)%len] != ' ') start--;
            }
        }
        return start/len;
    }
};
