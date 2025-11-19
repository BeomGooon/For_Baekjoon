from itertools import combinations

def summations(lis, data):
    res = 0
    for [i,j] in lis:
        if (i < j):
            res += data[i][j]
        else:
            res += data[j][i]
    return res

db = [[0 for _ in range(20)] for _ in range(20)]

# Input N
N = int(input())

selections = list(range(N))

all_combinations = list(combinations(selections, int(N/2)))

# Input list and add Sij and Sji for easier calculation
for i in range(N):
    db[i] = list(map(int, input().split()))
    for j in range(i):
        db[j][i] += db[i][j]

result = 10000

for i in range(len(all_combinations)):
    temp = list(set(range(N)).difference(set(all_combinations[i])))
    X_combinations = list(combinations(all_combinations[i], 2))
    Y_combinations = list(combinations(temp, 2))
    X = summations(X_combinations, db)
    Y = summations(Y_combinations, db)
    tm = abs(X - Y)
    if (tm < result): 
        result = tm
        #print("tm = %d, combination is (%d, %d)" %(tm, all_combinations[i][0], all_combinations[i][1]))

print(result)