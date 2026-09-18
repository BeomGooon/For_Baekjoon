import numpy as np

def dac(inp):
    n = len(inp)
    if n > 1:
        mid = n // 2
        fir = dac(inp[0:mid, 0:mid])
        sec = dac(inp[0:mid, mid:n])
        thi = dac(inp[mid:n, 0:mid])
        fou = dac(inp[mid:n, mid:n])
        if (fir[0] and sec[0] and thi[0] and fou[0]) and (fir[1] == sec[1] and thi[1] == fou[1] and fir[1] == thi[1]):
            ret = (True, 1, 0) if fir[1] == 1 else (True, 0, 1)
            return ret
        else:
            return (False, fir[1] + sec[1] + thi[1] + fou[1], fir[2] + sec[2] + thi[2] + fou[2])
    else:
        ret = (True, 1, 0) if inp[0][0] == 0 else (True, 0, 1)
        return ret
    

def solution(arr):
    answer = []
    arr = np.array(arr)
    answer = dac(arr)[1:]
    return answer