N, M, x, y, K = map(int, input().split())

Map = [[0 for _ in range(M)] for _ in range(N)]

for n in range(N):
    for m in range(M):
        Map[n][m]