#include <iostream>
#include <queue>

int F, S, G, U, D;
int building[1000002];
int visited[1000002];
int visit;
using namespace std;
struct pos {
	int floor;
	int cnt;
};
queue<pos> que;

void bfs() {
	while (!que.empty()) {
		int current_floor = que.front().floor;
		int cnt = que.front().cnt;

		if (current_floor == G) {
			printf("%d", cnt);
			return;
		}
		if (current_floor + U <= F)
			if (!visited[current_floor + U]) {
				que.push({ current_floor + U, cnt + 1 });
				visited[current_floor + U] = 1;
			}
		if (current_floor - D >= 1)
			if (!visited[current_floor - D]) {
				que.push({ current_floor - D, cnt + 1 });
				visited[current_floor - D] = 1;
			}
		que.pop();
	}
	printf("use the stairs");
}

int main() {
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	que.push({ S, 0 });
	visited[S] = 1;
	bfs();
}
