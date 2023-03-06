#include <iostream>
#include <queue>
using namespace std;

struct box {
	int n;
	int m;
	int h;
	int cnt;
};
queue<box> que;
int tomato[101][101][101] = { -1, };
int M, N, H;

int dn[6] = { -1,0,1,0,0,0 };
int dm[6] = { 0,1,0,-1,0,0 };
int dh[6] = { 0,0,0,0,-1,1 };
int total = 0;
int total_cnt = 0;
void bfs() {
	int cnt;
	while (!que.empty()) {
		
		cnt = que.front().cnt;
		for (int k = 0; k < 6; k++) {

			int dir_n = que.front().n + dn[k];
			int dir_m = que.front().m + dm[k];
			int dir_h = que.front().h + dh[k];
			
			if (dir_n < 1 || N < dir_n || dir_m < 1 || M < dir_m || dir_h < 1 || H < dir_h)
				continue;
			if (tomato[dir_h][dir_n][dir_m] == 0) {
				tomato[dir_h][dir_n][dir_m] = cnt + 1;
				total_cnt++;
				que.push({ dir_n, dir_m, dir_h, cnt + 1 });
			}
		}
		que.pop();
	}
	if (total == total_cnt)
		printf("%d", cnt);
	else
		printf("-1");
}

int main() {
	scanf("%d %d %d", &M, &N, &H);	
	for (int h = 1; h <= H; h++) {
		for (int k = 1; k <= N; k++) {
			for (int t = 1; t <= M; t++) {
				int tmp;
				scanf("%d", &tmp);
				if (tmp != -1)
					total++;				
				tomato[h][k][t] = tmp;
				if (tmp == 1) {
					total_cnt++;
					que.push({ k,t,h,0 });
				}
			}
		}
	}
	bfs();
	
}