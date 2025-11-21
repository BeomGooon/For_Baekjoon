from itertools import product

# define function which erases the place on cctv
def erase(maps_t, dir: tuple, loc: tuple):
    y = loc[0]
    x = loc[1]
    ind = 1
    if 0 in dir:
        while (y >= ind):
            if maps_t[y-ind][x] == 0:
                maps_t[y-ind][x] = -1
            elif maps_t[y-ind][x] == 6:
                break
            ind += 1
    ind = -1
    if 2 in dir:
        while (y - ind < len(maps_t)):
            if maps_t[y-ind][x] == 0:
                maps_t[y-ind][x] = -1
            elif maps_t[y-ind][x] == 6:
                break
            ind -= 1
    ind = -1
    if 1 in dir:
        while (x - ind < len(maps_t[y])):
            if maps_t[y][x - ind] == 0:
                maps_t[y][x - ind] = -1
            elif maps_t[y][x - ind] == 6:
                break
            ind -= 1
    ind = 1
    if 3 in dir:
        while (x >= ind):
            if maps_t[y][x - ind] == 0:
                maps_t[y][x - ind] = -1
            elif maps_t[y][x - ind] == 6:
                break
            ind += 1
    return maps_t


# up is 0 and others are ranged with clockwise
cases = []
cases.append([])
cases.append([(0,), (1,), (2,), (3,)])
cases.append([(0, 2), (1,3)])
cases.append([(0,1), (1,2), (2,3), (0,3)])
cases.append([(0,1,2), (1,2,3), (0,2,3), (0,1,3)])
cases.append([(0,1,2,3)])

# input
[N,M] = map(int, input().split())
maps = [[0]*M for i in range(N)]
for i in range(N):
    maps[i] = list(map(int, input().split()))

# define list for locations of cctv and number
locations = []
directions = []

# check the cctvs
for i in range(N):
    for j in range(M):
        temp = maps[i][j]
        if temp < 6 and temp > 0:
            locations.append([i, j])
            directions.append(cases[temp])

# define list for combination(cases)
all_list = list(product(*directions))
# print(all_list)

# calculate
min_val = N * M
for i in range(len(all_list)):
    temp_map = [row[:] for row in maps]
    for j in range(len(locations)):
        # print(all_list[i][j])
        temp_map = erase(temp_map, all_list[i][j], locations[j])
    result = 0
    for j in range(N):
        for k in range(M):
            if temp_map[j][k] == 0:
                result += 1
    if min_val > result:
        min_val = result

# print
print(min_val)