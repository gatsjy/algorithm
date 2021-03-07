from collections import defaultdict
def solution(clothes):
    answer = 1
    a = defaultdict(list)
    for clothe in clothes:
        a[clothe[1]].append(clothe[0])
    for key,value in a.items():
        answer *= len(value)+1
    return answer-1