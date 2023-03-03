#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compare {
	bool operator()(int n1, int n2) {
		if (abs(n1) == abs(n2)) {
			return n1 > n2;
		}
		else {
			return (abs(n1) > abs(n2));
		}
	}
};



int main() {
	
	
	int N;
	scanf("%d", &N);
	//priority_queue<int> pq;
	priority_queue<int, vector<int>, compare> pq;
	for (int k = 1; k <= N; k++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0) {
			if (pq.size() == 0)
				printf("0\n");
			else {
				printf("%d\n", pq.top());
				pq.pop();				
			}
		}
		else {						
			pq.push(tmp);
		}
	}


}