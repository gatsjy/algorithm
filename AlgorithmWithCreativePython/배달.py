#https://programmers.co.kr/learn/courses/30/lessons/12978

def solution(s):
    answer = 0
    size = len(s)//2
    for i in range(1,size+1):
        idx = 0
        tmp = s[idx:i]
        cnt = 1
        tmps=""
        for j in range(idx+1,len(s),i):
            if tmp == s[j:j+i]:
                cnt+=1s
            else:
                idx=j
                tmps+=str(cnt)+tmp
                tmp = s[idx:i]
                cnt=1
        print(tmps)      
    return answer