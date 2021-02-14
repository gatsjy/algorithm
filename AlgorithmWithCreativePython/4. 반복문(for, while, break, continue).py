'''
반복문(for, while)
a=range(1, 11)

print(list(a))

i=10
while i>=1:
    print(i)
    i=i-1

i=1
while i<=10:
    print(i)
    i=i+1

i=1
while True:
    print(i)
    if i==5:
        break
    i+=1

for i in range(1,11):
    if i%2==0:
        continue
    print("홀수!")
'''

for i in range(1,11):
    if i == 5:
        continue
    print(i)
else: # 정상적으로 종료되었을 시에 else가 돌아간다
    print(11)