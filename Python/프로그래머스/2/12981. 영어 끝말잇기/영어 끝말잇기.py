def solution(n, words):
    answer = []
    prev_word = ""
    result = 0
    words_set = set()
    for ind, word in enumerate(words):
        if ind > 0:
            if prev_word[-1] != word[0] or word in words_set:
                result = ind + 1
                break
            else:
                words_set.add(word)
                prev_word = word
        else:
            words_set.add(word)
            prev_word = word        
    if result != 0:
        answer.append((result - 1) % n + 1)
        answer.append((result - 1) // n + 1)
    else:
        answer.append(0)
        answer.append(0)
    return answer