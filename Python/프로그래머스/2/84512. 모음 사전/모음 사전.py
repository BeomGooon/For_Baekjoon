def solution(word):
    answer = 0
    vowels = ['A', 'E', 'I', 'O', 'U']
    found = False
    
    def dfs(cur):
        nonlocal answer, vowels, found, word
        
        if cur == word:
            found = True
            return
        
        if len(cur) == 5:
            return
        
        for ch in vowels:
            if not found:
                answer += 1
                dfs(cur + ch)
    
    dfs('')
    
    return answer