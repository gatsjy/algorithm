'''
반복문을 이용한 문제 풀이
    1) 1부터 N까지 홀수출력하기
    2) 1부터 N까지의 합 구하기
    3) N의 약수출력하기
'''

# 1.
a = int(input())
for i in range(1,a+1):
    if i%2==0:
        print(i)

# 2.
a = int(input())
sum = 0

for i in range(1,a+1):
    sum += i
    
print(sum)

# 3.
a = int(input())

for i in range(1,a+1):
    if a%i==0:
        print(i)
