#include <iostream>
#include <cstring>

int visited[302][302];
int sea[302][302];
int meltyear[302][302];
int N, M;

int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int year = 0;



void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		int dir_x = x + dx[k];
		int dir_y = y + dy[k];

		if (sea[dir_x][dir_y] != 0 && visited[dir_x][dir_y] == 0) {
			dfs(dir_x, dir_y);
		}
	}
}


int count() {
	int cnt = 0;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			if (sea[n][m] != 0 && visited[n][m] == 0) {
				dfs(n, m);
				cnt++;
				if (cnt > 1)
					return cnt;
			}
		}
	}
	return cnt;
}

void melt() {
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			int cnt = 0;
			if (sea[n][m] == 0)
				continue;
			for (int k = 0; k < 4; k++) {
				int dir_x = n + dx[k];
				int dir_y = m + dy[k];
				if (sea[dir_x][dir_y] == 0 && meltyear[dir_x][dir_y] != year)
					cnt++;
			}
			if (sea[n][m] == 0)
				continue;
			sea[n][m] -= cnt;
			if (sea[n][m] < 0)
				sea[n][m] = 0;
			meltyear[n][m] = year;
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			scanf("%d", &sea[n][m]);
		}
	}
	
	while (1) {		
		int cnt = 0;
		memset(visited, 0, sizeof(visited));
		cnt = count();

		if (cnt == 0) {
			printf("0");
			break;
		}
		else if (cnt > 1) {
			printf("%d", year);
			break;
		}
		year++;
		melt();
		
	}
}