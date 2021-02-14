'''
리스트와 내장함수(2)
'''
a=[23,12,36,53,19]
#print(a[:3])
#print(a[1:4])
#print(len(a))

for i in range(len(a)):
    print(a[i], end=' ')
print()

for x in a:
    if x%2==0:
        print(x,end=' ')
print()

for x in enumerate(a):
    print(x)

b=(1,2,3,4,5) # 튜플
print(b[0])
#b[0]=7 # 튜플값은 변경이 불가능하다.

for x in enumerate(a): # 인덱스와 리스트의 밸류값을 접근하기 위해서
    print(x[0], x[1])

for index, value in enumerate(a):
    print(index, value, end=' ')

if any(60<x for x in a):
    print("YES")
else:
    print("NO")



