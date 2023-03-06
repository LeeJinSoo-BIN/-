#include <iostream>
#include <vector>
using namespace std;

struct fam {
	int num;
	int ischild;
};
vector<vector<fam>> family;
int visited[101];
int n;
int hum1, hum2;
int m;

int dfs(int num, int chon) {
	visited[num] = 1;
	if (num == hum2) {
		printf("%d", chon);
		return 1;
	}
	for (int k = 0; k < family[num].size(); k++) {
		if (!visited[family[num][k].num])
			if (dfs(family[num][k].num, chon + 1))
				return 1;
	}
	return 0;
}


int main() {
	
	scanf("%d", &n);
	family.resize(n + 1);
	scanf("%d %d", &hum1, &hum2);
	scanf("%d", &m);
	for (int k = 0; k < m; k++) {
		int x, y;
		scanf("%d %d", &x, &y);
		family[x].push_back({ y,1 });
		family[y].push_back({ x,0 });
	}
	if (!dfs(hum1, 0))
		printf("-1");
}