'''
���� �Լ�
# �͸��� �Լ�

print(plus_one(1))

plus_two=lambda x: x+2 # �������̴�..
print(plus_two(1))
'''
def plus_one(x):
    return x+1

a=[1,2,3]
print(list(map(plus_one,a))) # �Լ��� �̿��ؼ� ����Ʈȭ ���Ѽ� ����Ѵ�.

# �Ȱ��� ���� ���ٷ� ǥ��
print(list(map(lambda x:x+2,a)))

# �����Ҷ� ���ٸ� ���� ����Ѵ�.