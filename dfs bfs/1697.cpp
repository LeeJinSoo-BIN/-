#include <iostream>
#include <queue>
int visited[100001];
int position[100001];

struct point {
	int x;
	int time;
};
using namespace std;
queue<point> que;
int N, K;
void bfs() {
	while (!que.empty()) {
		int current_pos = que.front().x;
		int current_pos_time = que.front().time;
		visited[current_pos] = 1;
		if (current_pos == K) {
			printf("%d", current_pos_time);
			return;
		}
		if (current_pos + 1 <= 100000 )
			if (!visited[current_pos + 1])
				que.push({ current_pos + 1, current_pos_time + 1 });
		if (current_pos - 1 >= 0)
			if (!visited[current_pos - 1])
				que.push({ current_pos - 1, current_pos_time + 1 });
		if (current_pos * 2  <= 100000)
			if (!visited[current_pos * 2])
				que.push({ current_pos * 2, current_pos_time + 1 });
		
		que.pop();
	}

}

int main() {	
	scanf("%d %d", &N, &K);
	que.push({ N,0 });
	bfs();
}