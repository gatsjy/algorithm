def solution(s):
    answer = len(s)
    size = len(s)//2+1
    for i in range(1,size):
        tmp =""
        # 체크해줄 스트링 값 만들기
        checker = s[0:i]
        cnt = 1
        # 한땀 한땀 체크
        for j in range(i,len(s),i):
            # 값을 체크해서 같으면 cnt을 ++ 해주고, 틀리다면 체크를 갱신해준다.
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