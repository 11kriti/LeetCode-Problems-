class StockSpanner:

    def __init__(self):
        ### initialize the stack with inf as its price and 0 as its date
        self.stack = [[inf,0]]

    def next(self, price: int) -> int:
        ### note that stack will not be empty at any time,
        ### yesterday's date always stored in stack. 
        curDay = self.stack[-1][1]+1

        ### as long as price is >= the last price in stack, pop it.
        while price>=self.stack[-1][0]:
            self.stack.pop(-1)

        ### calculate the result using today's date and the day which price is higher than today's price
        span = curDay-self.stack[-1][1]

        ### aways append today's price and date to stack
        self.stack.append([price,curDay])

        return span


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)