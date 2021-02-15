'''
4. 두 리스트 합치기
'''
import sys
#sys.stdin=open("input.txt","rt")
    
a = int(input())
aa = list(map(int,input().split()))
b = int(input())
bb = list(map(int,input().split()))

aidx = 0
bidx = 0

cc = list()
while aidx<a and bidx<b:
    if aa[aidx]<=bb[bidx]:
        cc.append(aa[aidx])
        aidx +=1
    else:
        cc.append(bb[bidx])
        bidx +=1

while aidx<a:
    cc.append(aa[aidx])
    aidx +=1

while bidx<b:
    cc.append(bb[bidx])
    bidx +=1

for n in cc:
    print(n, end=' ')
