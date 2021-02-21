'''
증가수열 만들기(그리디)
'''
import sys
#sys.stdin=open("input.txt", "r")

n = int(input())
a = list(map(int,input().split()))

res = ""
lt = 0
rt = n-1
min_v = min(a[lt],a[rt])
cnt = 0
while lt <= rt:
    if abs(min_v-a[lt]) <= abs(min_v-a[rt]):
        if a[lt] >= min_v:
            min_v = a[lt]
            lt+=1
            cnt +=1
            res += "L"
        else:
            break
    else:
        if a[rt] >= min_v:
            min_v = a[rt]
            rt-=1
            cnt +=1
            res += "R"
        else:
            break
print(cnt)
print(res)
