def solution(n):
    answer = 0
    temp = ""
    while n:
        temp = str(n % 2) + temp
        n //= 2
    n = temp
    found_one = False
    ind0 = 0
    one_num = 0
    for i in range(len(n) - 1, -1, -1):
        if n[i] == "1":
            one_num += 1
        if not found_one and n[i] == "1":
            found_one = True
        elif found_one and n[i] == "0":
            ind0 = i
            n = n[0:ind0] + "1" + "0" * (len(n) - ind0 - one_num) + "1" * (one_num - 1)
            break
        elif i == 0:
            n = "1" + "0" * (len(n) - one_num + 1) + "1" * (one_num - 1)
    for i in n:
        answer += int(i)
        answer *= 2
    return answer // 2