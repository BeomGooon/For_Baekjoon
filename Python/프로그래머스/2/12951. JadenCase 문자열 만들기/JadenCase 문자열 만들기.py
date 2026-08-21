def solution(s):
    lis = s.split(' ')
    answer = ''
    for word in lis:
        answer += word.capitalize() + " "
    answer = answer[:-1]
    return answer