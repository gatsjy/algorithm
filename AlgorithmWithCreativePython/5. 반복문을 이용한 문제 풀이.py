'''
�ݺ����� �̿��� ���� Ǯ��
    1) 1���� N���� Ȧ������ϱ�
    2) 1���� N������ �� ���ϱ�
    3) N�� �������ϱ�
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
