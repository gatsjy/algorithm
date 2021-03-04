import sys
from collections import deque
sys.stdin=open("input.txt", "rt")

# ����� ������ ������ ������ �Է¹ޱ�
v,e = map(int,input().split())
# ��� ��忡 ���� ���������� 0���� �ʱ�ȭ
indegree=[0]*(v+1)
# �� ��忡 ����� ���� ������ ��� ���� ���� ����Ʈ(�׷���)�ʱ�ȭ
graph =[[] for i in range(v+1)]

# ����׷����� ��� ���� ������ �Է¹ޱ�
for _ in range(e):
    a,b=map(int,input().split())
    graph[a].append(b)
    indegree[b]+=1


# �������� �Լ�
def topology_sort():
    result = [] # �˰��� ���� ����� ���� ����Ʈ
    q = deque() # ť ����� ���� deque ���̺귯�� ���

    # ó�� ������ ���� ���������� 0�� ��带 ť�� ����
    for i in range(1,v+1):
        if indegree[i]==0:
            q.append(i)

    # ť�� �������� �ݺ�
    while q:
        #ť���� ���� ������
        now = q.popleft()
        result.append(now)
        # �ش� ���ҿ� ����� ������ ������������ 1 ����
        for i in graph[now]:
            indegree[i] -=1
            # ���Ӱ� ���������� 0�� �Ǵ� ��带 ť�� ����
            if indegree[i]==0:
                q.append(i)
    
    #���������� ������ ��� ���
    for x in result:
        print(x , end=' ')

topology_sort()