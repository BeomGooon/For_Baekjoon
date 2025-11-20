from itertools import combinations

# Function for Horizontal check
def check(lis, l):
    ind = 1
    n = len(lis)
    last = lis[0]
    used = -1
    while (ind < n):
        if last == lis[ind]: # Flat and keep going
            ind += 1
        elif last + 1 == lis[ind]: # meet 1-up floor
            for i in range(1, 1 + l):
                if ind < i or used >= ind - i or last != lis[ind - i]: # Finding if space behind is available
                    return False
            # move up to next step
            last = lis[ind]
            ind += 1
        elif last - 1 == lis[ind]: # meet 1-down floor
            last = lis[ind]
            for i in range(1, l):
                if ind + i >= n or last != lis[ind + i]:
                    return False
            # move up to next step
            used = ind + l - 1
            ind += l
        else: # You met the floor which is two-time higher or lower than last one. quit with false
            return False
    return True

# Function for Transpose
def transpose(lis):
    n = len(lis)
    result = [[0] * n for i in range(n)]
    for i in range(n):
        for j in range(n):
            result[i][j] = lis[j][i]
    return result

# Input N, L, maps
[N, L] = map(int, input().split())
maps = [[0] * N for i in range(N)]
for i in range(N):
    maps[i] = list(map(int, input().split()))

# find the cases
cases = 0
for i in range(N):
    if check(maps[i], L):
        #print("y: %d" %i)
        cases += 1

# transpose maps
maps = transpose(maps)

# find the cases
for i in range(N):
    if check(maps[i], L):
        #print("y: %d" %i)
        cases += 1

# print the result
print(cases)