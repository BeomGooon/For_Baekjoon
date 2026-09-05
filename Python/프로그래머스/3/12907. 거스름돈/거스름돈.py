from functools import cache

def solution(n, money):
    answer = 0
    
    money.sort()
    
    @cache
    def dp(left, ind):
        div = money[ind]
        if ind == 0:
            if left % div != 0:
                return 0
            else:
                return 1
        else:
            result = 0
            next = left
            while next >= 0:
                result += dp(next, ind - 1)
                next -= div
            return result
                
    tem = len(money) - 1
    answer = dp(n, tem)
    
    return answer