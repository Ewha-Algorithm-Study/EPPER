// e-Queen

// 코드 효율성은 좀 더 필요..

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int check[14], d[27], d2[27];
int N, count;
int xy[14][14];

void nqueen(int lev) {
	int i;

	if (lev == N) {	//마지막 row 도달. 경우의 수 1개 찾음
		count++;
		return;
	}

	for (i = 0; i < N; i++) {		//각 row의 column들 하나씩 탐색
		if (xy[lev][i]) continue;			//주어진 놓을 수 없는 점들 skip
		//앞에 나온 위치와 column혹은 대각선이 같은 좌표들은 skip
		if (check[i] == 1) continue;			//column
		if (d[i + lev] == 1) continue;			//오른쪽위 방향 대각선
		if (d2[lev - i + 13] == 1) continue;	//오른쪽아래 방향 대각선

		//새로운 위치 선택. column과 대각선 기록
		check[i] = 1;
		d[i + lev] = 1;
		d2[lev - i + 13] = 1;

		nqueen(lev + 1);		//동일한 작업을 아래의 row들에서 반복

		//한바퀴 다 돌음. 현재 row이하에서 기록한 column과 대각선 값 초기화
		check[i] = 0;
		d[i + lev] = 0;
		d2[lev - i + 13] = 0;
	}
}

int solution2(int n, int k, int X[], size_t X_len, int Y[], size_t Y_len) {
	int answer = 0;
	int i, j;
	N = n;
	for (i = 0; i < k; i++)		//주어진 불가능한 위치정보들 초기화
		xy[X[i] - 1][Y[i] - 1] = 1;
	nqueen(0);
	answer = count;
	return answer;
}

int n, res;
int map[15];

bool isPromising(int r, int c) {
	for (int i = 1; i < r; i++) {
		if (map[i] == c)
			return false;
		if (abs(r - i) == abs(map[i] - c))
			return false;
	}
	return true;
}

void dfs(int r, int c) {
	map[r] = c;
	if (r == n) {
		res++;
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (isPromising(r + 1, i)) {
				dfs(r + 1, i);
			}
		}
	}
	map[r] = 0;
}

int solution(int n, int k, int X[], size_t X_len, int Y[], size_t Y_len) {
	
}

int main(void) {
	int n = 4;
	int k = 2;
	int X[] = { 1, 1 };
	int Y[] = { 2, 3 };
	
	printf("\n%d", solution(n, k, X, k, Y, k));
}