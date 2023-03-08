#include <iostream>

using namespace std;
struct point {
	int x;
	int y;
	int height;
};


int ground[102][102];
int N;
int visited[102][102];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void reset() {
	for (int k = 1; k <= 100; k++) {
		for (int t = 1; t <= 100; t++) {
			visited[k][t] = 0;
		}
	}
}

void dfs(int x, int y, int rain) {
	visited[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		int dir_x = x + dx[k];
		int dir_y = y + dy[k];
		if (ground[dir_x][dir_y]>0 && ground[dir_x][dir_y] > rain && visited[dir_x][dir_y] != 1)
			dfs(dir_x, dir_y, rain);
	}
}

int main() {
	scanf("%d", &N);
	int maxheight = 0;
	for (int k = 1; k <= N; k++) {
		for (int t = 1; t <= N; t++) {
			scanf("%d", &ground[k][t]);
			if (maxheight < ground[k][t])
				maxheight = ground[k][t];
		}
	}
	int max_cnt = 0;
	for (int rain = 0; rain < maxheight; rain++) {
		reset();
		int cnt = 0;
		for (int k = 1; k <= N; k++) {
			for (int t = 1; t <= N; t++) {
				if (ground[k][t] > rain && visited[k][t] != 1) {
					dfs(k, t, rain);
					cnt++;
				}
			}
		}

		if (max_cnt < cnt)
			max_cnt = cnt;
	}
	printf("%d", max_cnt);
}