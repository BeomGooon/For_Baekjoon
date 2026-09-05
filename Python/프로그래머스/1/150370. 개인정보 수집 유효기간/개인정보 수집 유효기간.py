def solution(today, terms, privacies):
    answer = []
    today_int = list(map(int, today.split('.')))
    today_int = today_int[0] * 336 + today_int[1] * 28 + today_int[2]
    term_dict = dict()
    for item in terms:
        item = item.split()
        term_dict[item[0]] = int(item[1])
    
    privacies = list(map(lambda x: x.split(' '), privacies))
    

    print(term_dict)
    for ind, item in enumerate(privacies):
        date = item[0]
        term = item[1]
        date_int = list(map(int, date.split('.')))
        date_int = date_int[0] * 336 + (date_int[1] + term_dict[term]) * 28 + date_int[2]
        # print(f"date: {date}, date_int: {date_int}, today_int: {today_int}")
        if date_int <= today_int:
            answer.append(ind + 1)
    
    return answer