class Solution:
    def evalRPN(self, tokens: List[str]) -> int:

        ops = {"+" : add, "-" : sub, "*" : mul, "/" : truediv}
        stack = []

        for t in tokens:
            if t in ops:
                b, a = stack.pop(), stack.pop()
                t = ops[t](a,b)
            stack.append(int(t))

        return stack[-1]