'''
문자열과 내장함수
msg = "It is Time"
print(msg.upper()) # 대문자화 시키기
print(msg.lower()) # 소문자화 시키기
print(tmp.find('T')) # 'T'를 찾기 
print(tmp.count('T')) # 해당 문자 몇개인지 세기
print(tmp[:4]) # 처음부터 4까지 출력
'''

msg = "It is Time"
tmp = msg.upper()

print(msg[3:5])
print(len(msg))
for i in range(len(msg)):
    print(tmp[i], end=' ')
print()

for x in msg: # 전체 문자열 출력해보기!!
    print(x, end=' ')
print()

# 대문자만 뽑아서 출력한 것!
for x in msg:
    if x.isupper():
        print(x, end='')

for x in msg:
    if x.islower():
        print(x, end=' ')
print()

tmp='AZ'
# 아스키 넘버 출력하기!
for x in tmp:
    print(ord(x))

# 아스키 넘버에 해당하는 문자 출력하기
tmp=65
print(chr(tmp))

## 문자열 거꾸로 바꾸기 print(s[::-1])