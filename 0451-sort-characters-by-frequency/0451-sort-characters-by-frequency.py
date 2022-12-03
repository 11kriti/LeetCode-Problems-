class Solution:
    def frequencySort(self, s: str) -> str:
        return "".join(c * ch for c, ch in Counter(s).most_common())