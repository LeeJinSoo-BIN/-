#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;

int bisect(int n) {
	int front = 0;
	int end = arr.size();

	while (front < end) {
		int mid = front + end / 2;
		int val = arr[mid];
		if (val == n) {
			return 1;
		}
		else if (val < n) {
			front = mid;
		}
		else {
			end = mid;
		}

	}
	return 0;
}
int main() {


	int N;
	scanf("%d", &N);

	for (int k = 0; k < N; k++) {
		int tmp;
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}

	int M;
	scanf("%d", &M);
	sort(arr.begin(), arr.end(), N);
	for (int k = 0; k < M; k++) {
		int a;
		scanf("%d", &a);
		printf("%d\n", bisect(a));
	}


}