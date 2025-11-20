from itertools import combinations

# function for rotate
def rotate(rig, lef, nu, d):
    rig[nu] = (rig[nu] - d) % 8
    lef[nu] = (lef[nu] - d) % 8
    return [rig, lef]

# define function that goes one step
def step(rig, lef, ma, nu, d):
    connected = [0] * 3
    # check if chains are connected
    for i in range(3):
        if ma[i][rig[i]] != ma[i+1][lef[i+1]]:
            connected[i] = 1
    # rotate selected chain
    [rig, lef] = rotate(rig, lef, nu, d)

    # rotate connected chain
    for i in range(1, 4):
        if (i + nu < 4 and connected[i + nu - 1] == 1):
            [rig, lef] = rotate(rig, lef, nu + i, d * ((-1) ** i))
        else:
            break
    for i in range(1, 4):
        if (nu - i >= 0 and connected[nu - i] == 1):
            [rig, lef] = rotate(rig, lef, nu - i, d * ((-1) ** i))
        else:
            break
    return [rig, lef]
    

# N is 0, S is 1

# index lists
rights = [2] * 4
lefts = [6] * 4

# N/S maps
maps = [[0] * 8 for i in range(4)]

# input
for i in range(4):
    inp_str = input()
    for j in range(8):
        maps[i][j] = int(inp_str[j])
K = int(input())
for i in range(K):
    [num, di] = map(int, input().split())
    [rights, lefts] = step(rights, lefts, maps, num - 1, di)
result = 0
for i in range(4):
    twelve = (lefts[i] + 2) % 8
    result += (maps[i][twelve] * (2 ** i))
print(result)