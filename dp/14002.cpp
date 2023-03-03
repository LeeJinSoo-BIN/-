#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

	vector<int> LIS;
	vector<int> ANS;
	LIS.push_back(-1000000001);
	int n;
	scanf("%d", &n);
	//int ans = 0;
	//int maxlen = 0;
	for (int k = 0; k < n; k++) {
		int num;
		scanf("%d", &num);
		if (LIS.back() > num) {
			LIS.push_back(num);
			/*ans++;
			if (ans > maxlen) {
				ANS.resize(ans + 1);
				copy(LIS.begin(), LIS.end(), ANS.begin());
			}*/
		}
		else {
			auto it = lower_bound(LIS.begin(), LIS.end(), num, greater<int>());
			*it = num;
		}
	}
	printf("%d", LIS.size());
	/*for (int k = 1; k <= ans; k++) {
		printf("%d ", ANS[k]);
	}*/

}