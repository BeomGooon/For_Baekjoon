def biggest_bi(num):
    if num <= 1:
        return num
    else:
        temp = 1
        while temp <= num:
            temp *= 2
        temp //= 2
        return temp

def solution(n):
    ans = 0
    
    while n > 0:
        n -= biggest_bi(n)
        ans += 1

    return ans