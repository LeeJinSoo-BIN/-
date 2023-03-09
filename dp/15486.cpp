#include <iostream>
#include <algorithm>
int dp[15000001];
int t[15000001];
int p[15000001];
int N;
using namespace std;
int main() {
	scanf("%d", &N);
	for (int k = 1; k <= N; k++) {
		scanf("%d %d", &t[k], &p[k]);
	}
	for (int k = 1; k <= N+1; k++) {
		dp[k] = max(dp[k], dp[k - 1]);
		if (k + t[k] <= N + 1) {
			dp[k + t[k]] = max(dp[k + t[k]], dp[k] + p[k]);
		}		
	}
	printf("%d", dp[N+1]);

}