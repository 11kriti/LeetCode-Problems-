class Solution:
     def maximumBags(self, cap, rocks, addRocks):
        return bisect_right(list(accumulate(sorted(starmap(sub,zip(cap,rocks))))),addRocks)
        