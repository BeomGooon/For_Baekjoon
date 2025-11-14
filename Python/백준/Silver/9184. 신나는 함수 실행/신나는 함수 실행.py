db = [[[0 for _ in range(21)] for _ in range(21)] for _ in range(21)]

def check(x, y, z):
    if (x < 1 or y < 1 or z < 1):
        return 1
    elif (x > 20 or y > 20 or z > 20):
        return check(20,20,20)
    elif db[x][y][z] != 0:
        return db[x][y][z]
    elif (x < y and y < z):
        db[x][y][z] = check(x,y,z-1) + check(x,y-1,z-1) - check(x,y-1,z)
        return db[x][y][z]
    else:
        db[x][y][z] = check(x-1,y,z) + check(x-1,y,z-1) + check(x-1,y-1,z) - check(x-1,y-1,z-1)
        return db[x][y][z]

flag = True
while (flag):
    [a, b, c] = map(int, input().split())
    if ([a,b,c] == [-1,-1,-1]):
        flag = False
    else:
        result = check(a,b,c)
        print('w(%d, %d, %d) = %d' %(a, b, c, result))
