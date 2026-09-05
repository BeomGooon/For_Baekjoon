def solution(s):
    answer = 0

    start = 0
    n = len(s)
    for ind, ch in enumerate(s):
        start = ind
        end = ind
        while start > 0 and end < n - 1:
            if s[start-1] == s[end+1]:
                start -= 1
                end += 1
            else:
                break
        if answer < end - start + 1:
            answer = end - start + 1
            
        if ind < n - 1 and s[ind + 1] == s[ind]:
            start = ind
            end = ind + 1
            while start > 0 and end < n - 1:
                if s[start-1] == s[end+1]:
                    start -= 1
                    end += 1
                else:
                    break
            if answer < end - start + 1:
                answer = end - start + 1
    return answer