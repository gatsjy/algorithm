'''
스토쿠
'''
import sys
#sys.stdin=open("input.txt","rt")

a = [list(map(int,input().split())) for _ in range(9)]

res = True

# 어떻게 모든 숫자가 있는걸 알아차리지?
for i in range(0,7,3):
    for j in range(0,7,3):
        ch = [0]*11
        for k in range(i,i+3):
            for h in range(j,j+3):
                ch[a[k][h]]+=1
                if ch[a[k][h]] > 1:
                    res = False

for i in range(9):
    ch = [0]*11
    for j in range(9):
        ch[a[i][j]]+=1
        if ch[a[i][j]] >1:
            res = False
    ch2 = [0]*11
    for j in range(9):
        ch2[a[j][i]]+=1
        if ch2[a[j][i]] >1:
            res = False


if res :
    print("YES")
else:
    print("NO")

