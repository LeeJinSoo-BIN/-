#include <iostream>
#include <algorithm>
int day[16];
int money[16];
int dp[16];
using namespace std;
int main() {

	int N;
	scanf("%d", &N);
	for (int k = 1; k <= N; k++) {
		scanf("%d %d", &day[k], &money[k]);
	}
	int max_ = 0;
	for (int k = 1; k <= N+1; k++) {
		dp[k] = max(dp[k], dp[k - 1]);
		if (day[k] + k <= N + 1) {
			dp[day[k] + k] = max(dp[day[k] + k], dp[k] + money[k]);
		}
		if (max_ < dp[k])
			max_ = dp[k];		
	}
	printf("%d", max_);
}