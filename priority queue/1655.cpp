#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main() {
	
	
	int N;
	scanf("%d", &N);
	//priority_queue<int> pq;
	priority_queue<int, vector<int>, less<int>> downpq;
	priority_queue<int, vector<int>, greater<int>> uppq;
	for (int k = 1; k <= N; k++) {
		int tmp;
		scanf("%d", &tmp);	
						
		if (downpq.size() == uppq.size()) {
			downpq.push(tmp);
		}
		else {
			uppq.push(tmp);
		}
		if ((downpq.size() > 0 && uppq.size() > 0) && (downpq.top() > uppq.top())) {
			int dtmp = downpq.top();
			downpq.pop();
			int utmp = uppq.top();
			uppq.pop();
			downpq.push(utmp);
			uppq.push(dtmp);
		}
		printf("%d\n", downpq.top());
	}


}