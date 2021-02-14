'''
a,b=map(int, input("숫자를 입력하세요 : ").split())
print(a+b) 
print(a-b)
print(a*b)
print(a/b) # 나누기
print(a//b) # 몫
print(a%b) # 나머지 
print(a**b) # 제곱
'''

# 실수 > 정수 이므로 연산 결과는 실수(float)로 나온다.
a = 4.3
b = 5
c = a+b
print(type(c))
