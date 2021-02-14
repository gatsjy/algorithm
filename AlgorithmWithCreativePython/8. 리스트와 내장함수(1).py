'''
리스트와 내장함수(1)
'''
import random as r

# 빈 리스트 만들기
a=[]
#print(a)
b=list()
#print(b)

a=[1,2,3,4,5]
#print(a)
#print(a[0])

# range로 리스트 초기화 시키기
b=list(range(1,11))
#print(b)

c = a+b # 리스트를 더하면 두 리스트를 합친다.
#print(c)

a.append(6) # push_back 같은 느낌
#print(a)

a.insert(3,7)
a.pop()
a.pop(3)

a.remove(4) # 리스트에서 4라는 값을 찾아서 제거해라
print(a.index(5)) # 5라는 값을 찾아서 인덱스 번호를 가져와라

a=list(range(1,11))
print(a)
print(sum(a)) # 리스트안에 있는 모든 값을 더해준다.
print(max(a)) # 리스트에서 가장 큰 값을 출력한다.
print(min(a)) # 리스트에서 가장 작은 값을 출력해준다.
print(min(7,5,3)) # 7하고 5중에 최소값을 찾아라
print(a)
r.shuffle(a)
print(a)
a.sort() # 오름차순으로 소팅
print(a)
a.sort(reverse=True) # 내림차순으로 소팅
print(a) 
a.clear() # 리스트에 있는 값을 클리어 한다.