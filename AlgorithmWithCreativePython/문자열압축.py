def solution(s):
    answer = len(s)
    size = len(s)//2+1
    for i in range(1,size):
        tmp =""
        # üũ���� ��Ʈ�� �� �����
        checker = s[0:i]
        cnt = 1
        # �Ѷ� �Ѷ� üũ
        for j in range(i,len(s),i):
            # ���� üũ�ؼ� ������ cnt�� ++ ���ְ�, Ʋ���ٸ� üũ�� �������ش�.
            if checker == s[j:j+i]:
                cnt+=1
            else:
                if cnt >= 2:
                    tmp+=str(cnt)+checker
                else:
                    tmp+=checker
                checker = s[j:j+i]
                cnt=1
                
        if cnt>=2:
            tmp+=str(cnt)+checker
        else:
            tmp+=checker
        answer = min(answer,len(tmp))
    return answer