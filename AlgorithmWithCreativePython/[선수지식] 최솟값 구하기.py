'''
�ּڰ� ���ϱ�
'''
import sys
#sys.stdin=open("input.txt","rt")

arr = [5,3,7,9,2,5,2,6]
arrMin = float('inf')
for i in arr:
    if arrMin > i:
        arrMin = i
print(arrMin)