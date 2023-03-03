#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
	
	
	int N;
	scanf("%d", &N);
	//priority_queue<int> pq;
	priority_queue< int, vector<int>, greater<int> > pq;
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
		else
			pq.push(tmp);
	}


}