#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> computer;
int visited[101];
int cnt = 0;
void dfs(int com) {
	if (visited[com]) return;
	visited[com] = 1;
	cnt++;
	for (int k = 0; k < computer[com].size(); k++) {
		dfs(computer[com][k]);
	}
}
int main() {
	
	int n;
	scanf("%d", &n);
	computer.resize(n + 1);
	int m;
	scanf("%d", &m);
	for (int k = 0; k < m; k++) {
		int com1, com2;
		scanf("%d %d", &com1, &com2);
		computer[com1].push_back(com2);
		computer[com2].push_back(com1);
	}
	dfs(1);
	printf("%d", cnt-1);

}