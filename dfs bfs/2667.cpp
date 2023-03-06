#include <iostream>
#include <queue>

using namespace std;
struct point {
	int x;
	int y;
};
queue<point> que;
priority_queue< int, vector<int>, greater<int> > answer;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int town[26][26];
int not_visited[26][26];
int N, M;

void bfs() {
	int cnt = 0;
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		que.pop();
		if (!not_visited[x][y]) continue;
		cnt++;
		not_visited[x][y] = 0;
		for (int k = 0; k < 4; k++) {
			int dir_x = x + dx[k];
			int dir_y = y + dy[k];
			if (not_visited[dir_x][dir_y])
				que.push({ dir_x, dir_y });
		}
	}
	answer.push(cnt);
}

int main() {

	scanf("%d", &N);
	getchar();
	for (int k = 1; k <= N; k++) {
		for (int t = 1; t <= N; t++) {
			char tmp;
			scanf("%c", &tmp);
			town[k][t] = tmp - '0';
			if (tmp == '1')
				not_visited[k][t] = 1;
		}
		getchar();
	}
	int cnt = 0;
	for (int k = 1; k <= N; k++) {
		for (int t = 1; t <= N; t++) {
			if (not_visited[k][t]) {
				que.push({ k, t });
				bfs();
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	while (!answer.empty()) {
		printf("%d\n", answer.top());
		answer.pop();
	}

}