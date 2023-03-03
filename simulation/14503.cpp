#include <iostream>

int floor_[51][51];
int cleared[51][51];
int r, c, d;

struct direction {
	int r, c;
};
direction direction_left[4] = { {0,-1},{-1,0},{0,1},{1,0} };
direction direction_back[4] = { {1,0},{0,-1},{-1,0},{0,1} };
int check_left() {
	direction  direct = direction_left[d];
	if (cleared[r + direct.r][c + direct.c] == 0) {
		return 1;
	}
	else {
		return 2;
	}
}
void rotate_left() {
	d--;
	if (d == -1)
		d = 3;
}

int main() {


	int N, M;
	scanf("%d %d", &N, &M);
	
	scanf("%d %d %d", &r, &c, &d);
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			int tmp;
			scanf("%d", &tmp);
			floor_[n][m] = tmp;
			cleared[n][m] = tmp;
		}
	}

	int cnt = 0;
	int one = 1;
	int cant = 0;
	while (1) {
		if (one == 1) {
			if (cleared[r][c] == 0) {
				cnt++;
				cleared[r][c] = cnt;
				//printf("(%d, %d) / %d\n", r, c, cnt);
			}
			one = 0;			
		}
		if (check_left()==1) {
			cant = 0;
			r = r + direction_left[d].r;
			c = c + direction_left[d].c;
			rotate_left();			
			one = 1;
		}
		else if (check_left() == 2) {
			cant++;			
			rotate_left();
			if (cant == 4) {
				if (floor_[r + direction_back[d].r][c + direction_back[d].c] == 0) { //3
					r = r + direction_back[d].r;
					c = c + direction_back[d].c;
					cant = 0;			
				}
				else { // 4
					break;					
				}
			}				
		}
	}
	printf("%d", cnt);


}
