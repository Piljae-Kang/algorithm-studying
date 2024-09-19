import sys
input = sys.stdin.readline

N = int(input())


meetings = []
for _ in range(N):

    line = input().strip().split(" ")
    meetings.append((int(line[0]), int(line[1])))

    
meetings.sort(key=lambda x: (x[1], x[0]))

# 이미 첫번 째는 확정 왜냐 제일 적으니까~
count = 1
finished_time = meetings[0][1]
for i in range(1, N):

    if finished_time > meetings[i][0]:

        continue
    else:
        count += 1
        finished_time = meetings[i][1]



print(count)
    
                     
