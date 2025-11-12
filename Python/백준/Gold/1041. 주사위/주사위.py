import sys

# Code for Baekjoon, 1041 Problem

# input variables
n = int(input())
dice = list(map(int, input().split()))

# Find minimum number of Dice
one = min(dice)

# Define the oppisite Faces in Dice
oppo = [[0, 5], [5, 0], [1, 4], [4, 1], [2, 3], [3, 2]]
oppo_sliced = [[0, 3], [3, 0], [1, 2], [2, 1]]

# Calculate minimum number showed from dice whose three surface is out
two = 101
for i in range(6):
    for j in range(1, 6-i):
        if [i, i+j] not in oppo:
            temp0 = dice[i] + dice[i+j]
            if (temp0 < two): two = temp0

# Calculate minimum number showed from dice whose three surface is out
temp1 = dice[2:4]
temp2 = dice[0:2] + dice[4:6]
three = 101
for i in range(4):
    for j in range(1, 4-i):
        if [i, i+j] not in oppo_sliced:
            temp3 = temp2[i] + temp2[i+j]
            if (temp3 < three): three = temp3
three += min(temp1)

# Calculate the Result
if (n == 1):
    result = sum(dice) - max(dice)
    print(result)
else:
    one_num = (5 * n - 16) * n + 12
    two_num = 8 * n - 12
    three_num = 4
    result = one * one_num + two * two_num + three * three_num
    print(result)