import sys
import heapq
from collections import defaultdict

input = sys.stdin.readline
INF = float('inf')

V, E = map(int, input().strip().split())
K = int(input().strip())

graph = defaultdict(list)
for _ in range(E):
    u, v, w = map(int, input().strip().split())
    graph[u].append((v, w))

def dijkstra(start):
    distances = [INF] * (V + 1)
    distances[start] = 0
    priority_queue = [(0, start)]  # (거리, 노드)

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

distances = dijkstra(K)

for i in range(1, V + 1):
    if distances[i] == INF:
        print("INF")
    else:
        print(distances[i])
