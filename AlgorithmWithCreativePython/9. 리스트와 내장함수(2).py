'''
����Ʈ�� �����Լ�(2)
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

b=(1,2,3,4,5) # Ʃ��
print(b[0])
#b[0]=7 # Ʃ�ð��� ������ �Ұ����ϴ�.

for x in enumerate(a): # �ε����� ����Ʈ�� ������� �����ϱ� ���ؼ�
    print(x[0], x[1])

for index, value in enumerate(a):
    print(index, value, end=' ')

if any(60<x for x in a):
    print("YES")
else:
    print("NO")



