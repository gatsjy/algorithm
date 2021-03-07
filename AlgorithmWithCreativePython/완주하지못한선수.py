from collections import defaultdict
def solution(participant, completion):
    answer = ''
    a = defaultdict(int)
    for p in participant:
        a[p] += 1
    
    for c in completion:
        a[c] -= 1
    
    for key,value in a.items():
        if value == 1:
            answer = key
            break
    return answer