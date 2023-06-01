""""
As we can see from the definition, for a word square with equal-sized row and column, the resulting letter matrix should be symmetrical across its diagonal.

In other words, if we know the upper-right part of the word square, we could infer its lower-left part, and vice versa. This symmetric property of the word square could also be interpreted as the constraint of the problem (as in the constraint programming), which could help us to narrow down the valid combinations.

Let us start with the word ball as the first word in the word square, i.e. the word that we would put in the first row.

We then move on to the second row. Given the symmetric property of the word square, we now know the letters that we should fill on the first column of the second row. In other words, we know that the word in the second row should start with the prefix a.

Among the list of words, there are two words with prefix a (i.e. able, area). Both of them could be the candidates to fill the second row of the square. We then should try both of them in the next step.

In the next step (1), let us fill the second row with the word able. Then we could move on to the third row. Again, due to the symmetric property, we know that the word in the third row should start with the prefix ll. Unfortunately, we do not find any word start with ll. As a result, we could no longer move forwards. We then abandon this path, and backtrack to the previous state (with the first row filled).

As an alternative next step (1), we could try with the word area in the second row. Once we fill the second row, we would know that in the next row, the word to be filled should start with the prefix le. And this time, we find the candidate (i.e. lead).

As a result, in the next step (2), we fill the third row with the word lead. So on and so forth.

At the end, if one repeats the above steps with each word as the starting word, one would exhaust all the possibilities to construct a valid word square.
"""

class Solution:
    def getPrefix(self, prefix):
        if prefix in self.prefixHashTable:
            return self.prefixHashTable[prefix]
        else:
            return set([])
    def go(self, step, wordSquare, ans):
        if step == self.n:
            ans.append(wordSquare[:])
            return
        prefix = ''.join([w[step] for w in wordSquare])
        for w in self.getPrefix(prefix):
            wordSquare.append(w)
            self.go(step+1, wordSquare, ans)
            wordSquare.pop()
    def build(self, word):
        self.prefixHashTable = {}
        for w in word:
            for prefix in (w[:i] for i in range(1, len(w))):
                self.prefixHashTable.setdefault(prefix, set()).add(w)
    def wordSquares(self, words: List[str]) -> List[List[str]]:
        self.words = words
        self.n = len(words[0])
        self.build(self.words)
        ans = []
        for w in words:
            wordSquare = [w]
            self.go(1, wordSquare, ans)
        return ans
