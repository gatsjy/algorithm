'''
����Ʈ�� �����Լ�(1)
'''
import random as r

# �� ����Ʈ �����
a=[]
#print(a)
b=list()
#print(b)

a=[1,2,3,4,5]
#print(a)
#print(a[0])

# range�� ����Ʈ �ʱ�ȭ ��Ű��
b=list(range(1,11))
#print(b)

c = a+b # ����Ʈ�� ���ϸ� �� ����Ʈ�� ��ģ��.
#print(c)

a.append(6) # push_back ���� ����
#print(a)

a.insert(3,7)
a.pop()
a.pop(3)

a.remove(4) # ����Ʈ���� 4��� ���� ã�Ƽ� �����ض�
print(a.index(5)) # 5��� ���� ã�Ƽ� �ε��� ��ȣ�� �����Ͷ�

a=list(range(1,11))
print(a)
print(sum(a)) # ����Ʈ�ȿ� �ִ� ��� ���� �����ش�.
print(max(a)) # ����Ʈ���� ���� ū ���� ����Ѵ�.
print(min(a)) # ����Ʈ���� ���� ���� ���� ������ش�.
print(min(7,5,3)) # 7�ϰ� 5�߿� �ּҰ��� ã�ƶ�
print(a)
r.shuffle(a)
print(a)
a.sort() # ������������ ����
print(a)
a.sort(reverse=True) # ������������ ����
print(a) 
a.clear() # ����Ʈ�� �ִ� ���� Ŭ���� �Ѵ�.