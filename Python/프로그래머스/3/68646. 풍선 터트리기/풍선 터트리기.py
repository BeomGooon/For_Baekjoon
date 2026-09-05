def solution(a):
    answer = 0
    
    n = len(a)
    
    minto = [0] * n
    minfrom = [0] * n
    
    minnum = float('INF')
    for i in range(n):
        temp = a[i]
        if minnum > temp:
            minnum = temp
        minto[i] = minnum
    
    minnum = float('INF')
    for i in range(n-1, -1, -1):
        temp = a[i]
        if minnum > temp:
            minnum = temp
        minfrom[i] = minnum
    
    #print(f"minto: {minto}")
    #print(f"minfrom: {minfrom}")
    
    ansset = set()
    for i in range(n-1):
        temp = minto[i] if minto[i] > minfrom[i + 1] else minfrom[i + 1]
        ansset.add(temp)
    
    answer = len(ansset) + 1
    
    return answer