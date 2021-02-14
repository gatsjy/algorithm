'''
2차원 리스트 생성과 접근
'''
a=[[0]*3 for _ in range(3)]
print(a) # [[0, 0, 0], [0, 0, 0], [0, 0, 0]]

a[0][0]=1
a[1][1]=5
a[2][2]=9
print(a)

for x in a:
    print(x)

cnt = 1
for x in a:
    for y in x:
        print(y, end=' ')
    print()

for x in a:
    print(x)
