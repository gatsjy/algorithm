# ������ �̾Ƴ��� �Լ�
def pickdolls(board, move, size, dolls) :
    for i in range(size) :
        if board[i][move - 1] != 0 :
            dolls.append(board[i][move - 1])
            board[i][move - 1] = 0
            break

            # ���� �������� �ߺ��� �����ϰ� �� ���� �������ִ� �Լ�
            def checkBoom(dolls) :
            res = 0
            flag = True
            while flag :
                flag = False
                for i in range(1, len(dolls)) :
                    if dolls[i - 1] == dolls[i] : 
                        flag = True
                        dolls.pop(i - 1)
                        dolls.pop(i - 1)
                        res += 2
                        break
                        return res

                        def solution(board, moves) :
                        answer = 0
                        size = len(board)
                        dolls = []
                        for move in moves :
pickdolls(board, move, size, dolls)
answer += checkBoom(dolls)

return answer