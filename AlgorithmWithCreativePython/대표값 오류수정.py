'''
대표값 문제 오류 수정
round는 round_half_even 방식을 택한다.
'''

a = 66.5
a= a+0.5
a=int(a)
print(a)