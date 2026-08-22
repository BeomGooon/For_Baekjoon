def solution(info, n, m):
    ilen = len(info)
    dp = [set() for _ in range(ilen + 1)]
    dp[0].add((0, 0))
    for i in range(ilen):
        for item in dp[i]:
            if item[0] + info[i][0] < n:
                dp[i+1].add((item[0] + info[i][0], item[1]))
            if item[1] + info[i][1] < m:
                dp[i+1].add((item[0], item[1] + info[i][1]))
    if dp[ilen]:
        return min([item[0] for item in dp[ilen]])
    else:
        return -1