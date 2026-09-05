def solution(numbers, hand):
    answer = ''
    left = 9
    right = 11
    for item in numbers:
        if item % 3 == 1:
            answer += "L"
            left = item - 1
        elif item % 3 == 0 and item != 0:
            answer += "R"
            right = item - 1
        else:
            if item == 0:
                item = 11
            item -= 1
            ldir = abs((item // 3) - (left // 3)) + abs((item % 3) - (left % 3))
            rdir = abs((item // 3) - (right // 3)) + abs((item % 3) - (right % 3))
            if ldir > rdir or (ldir == rdir and hand == "right"):
                answer += "R"
                right = item
            else:
                answer += "L"
                left = item
    return answer