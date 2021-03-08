def solution(tickets):
    answer = []
    used_ticket=[]
    tickets.sort()
    def dfs(used_ticket,tickets,start):
        for i in range(len(tickets)):
            if start==tickets[i][0] and i not in used_ticket:
                used_ticket.append(i)
                dfs(used_ticket,tickets,tickets[i][1])
                if len(used_ticket) == len(tickets):
                    return
                else:
                    used_ticket.pop()
    
    dfs(used_ticket,tickets,"ICN")
    answer.append("ICN")
    for i in range(len(used_ticket)):
        answer.append(tickets[used_ticket[i]][1])
    return answer