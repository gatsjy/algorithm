'''
���ڿ��� �����Լ�
msg = "It is Time"
print(msg.upper()) # �빮��ȭ ��Ű��
print(msg.lower()) # �ҹ���ȭ ��Ű��
print(tmp.find('T')) # 'T'�� ã�� 
print(tmp.count('T')) # �ش� ���� ����� ����
print(tmp[:4]) # ó������ 4���� ���
'''

msg = "It is Time"
tmp = msg.upper()

print(msg[3:5])
print(len(msg))
for i in range(len(msg)):
    print(tmp[i], end=' ')
print()

for x in msg: # ��ü ���ڿ� ����غ���!!
    print(x, end=' ')
print()

# �빮�ڸ� �̾Ƽ� ����� ��!
for x in msg:
    if x.isupper():
        print(x, end='')

for x in msg:
    if x.islower():
        print(x, end=' ')
print()

tmp='AZ'
# �ƽ�Ű �ѹ� ����ϱ�!
for x in tmp:
    print(ord(x))

# �ƽ�Ű �ѹ��� �ش��ϴ� ���� ����ϱ�
tmp=65
print(chr(tmp))

## ���ڿ� �Ųٷ� �ٲٱ� print(s[::-1])