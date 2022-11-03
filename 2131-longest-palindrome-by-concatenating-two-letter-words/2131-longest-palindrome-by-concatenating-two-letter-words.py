class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
         
        freq = Counter(words)                 # obtain frequencies
        pp, p = 0, 0
        for w, f in freq.items():
            if w[0] == w[1]: 
                p = max(p, f % 2)             # odd-count symmetric word detector
                pp += f//2 * 2                # count paired symmetric words
            else:
                pp += min(f, freq[w[::-1]])   # count paired asymmetric words
        return (pp + p) * 2