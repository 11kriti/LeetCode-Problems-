class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        
        costs.sort()
        res = 0
        for price in costs:
            if price<=coins:
                res += 1
                coins -= price
            else:
                break
        return res