'''
람다 함수
# 익명의 함수

print(plus_one(1))

plus_two=lambda x: x+2 # 변수명이다..
print(plus_two(1))
'''
def plus_one(x):
    return x+1

a=[1,2,3]
print(list(map(plus_one,a))) # 함수를 이용해서 리스트화 시켜서 출력한다.

# 똑같은 것을 람다로 표현
print(list(map(lambda x:x+2,a)))

# 소팅할때 람다를 많이 사용한다.