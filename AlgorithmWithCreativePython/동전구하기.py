'''
동전교환
'''
import sys
sys.stdin=open("input.txt", "r")


def dfs(L, sum):
    global res
    if sum > m : return
    if L > res : return
    if sum==m:
        if res > L:
            res=L
    else:  
        for i in range(n):
            dfs(L+1, sum+coin[i])
        
if __name__=="__main__":
    n = int(input())
    coin = list(map(int,input().split()))
    m = int(input())
    res = 2147000000
    coin.sort(reverse=True)
    dfs(0,0)
    print(res)