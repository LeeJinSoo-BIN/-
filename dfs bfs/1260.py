import sys
input = sys.stdin.readline

N, M, V = map(int, input().split())

'''
graph = {str(i+1) : [] for i in range(N)}

for _ in range(M):
    a, b = input().split()
    graph[a].append(b)
    graph[b].append(a)

for i in range(N) :
    graph[str(i+1)].sort()
'''


graph=[[] for _ in range(N+1)]

for _ in range(M):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(len(graph)):
    graph[i].sort()


def dfs(graph, visited, current_node):    
    visited[int(current_node)] = True
    print(current_node, end = ' ')
    for node in graph[current_node] :
        if not visited[int(node)] :
            dfs(graph, visited, node)



def bfs(graph, visited, start_node):
    from collections import deque
    q=deque([start_node])
    visited[int(start_node)]=True
    while q:
        current_node=q.popleft()
        print(current_node, end=' ')
        for node in graph[current_node]:
            if not visited[int(node)]:
                q.append(node)
                visited[int(node)]=True
                print(q)

visited = [False]*(N+1)
#dfs(graph, visited, str(V))
dfs(graph, visited, V)
print()
visited = [False]*(N+1)
#bfs(graph, visited, str(V))
bfs(graph, visited, V)