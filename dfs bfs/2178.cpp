#include <iostream>
#include <queue>

int maze[101][101];
int visited[101][101];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int N, M;

using namespace std;
struct point {
	int x;
	int y;
	int cnt;
};
queue<point> que;

void bfs() {
	while (!que.empty()) {
		int cnt = que.front().cnt;
		int x = que.front().x;
		int y = que.front().y;
		que.pop();
		maze[x][y] = cnt;
		if (x == N && y == M) {
			printf("%d", cnt);
			break;
		}
		if (visited[x][y]) continue;
		visited[x][y] = 1;
		for (int k = 0; k < 4; k++) {
			int dir_x = dx[k] + x;
			int dir_y = dy[k] + y;

			if (visited[dir_x][dir_y] == 0 && maze[dir_x][dir_y] == 1) {
				que.push({ dir_x, dir_y, cnt+1 });
			}
		}
		
	}

}

int main() {
	scanf("%d %d", &N, &M);
	getchar();
	for (int k = 1; k <= N; k++) {
		for (int t = 1; t <= M; t++) {
			char tmp;
			scanf("%c", &tmp);
			maze[k][t] = tmp - '0';
		}
		getchar();
	}

	que.push({ 1,1,1 });
	bfs();
}