import sys
import heapq

input = sys.stdin.readline

N = int(input().strip())


heap = []

str = ""

for _ in range(N):

    n = int(input().strip())

    if n == 0:
    
        if not heap:
            str += "0\n"
        else:
            str += f"{-heapq.heappop(heap)}\n"

    else:

        heapq.heappush(heap, -n)


print(str)
            
        
        

    
