'''
�ݺ���(for, while)
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
    print("Ȧ��!")
'''

for i in range(1,11):
    if i == 5:
        continue
    print(i)
else: # ���������� ����Ǿ��� �ÿ� else�� ���ư���
    print(11)