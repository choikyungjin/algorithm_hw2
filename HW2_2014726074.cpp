/* 2014726074 컴퓨터 소프트웨어학과 최경진 */

#include <iostream>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

using namespace std;

void FindMax(int** arr, int n) {
	// 모든 값을 초기화 해준 후 시작
	int sub_sum = 0, total_sum = 0;
	int tmp, start = 0, end = 0;
	int _top = 0, _left = 0, _bottom = 0, _right = 0;
	int current_start = 0;

	// 진행 순서는 왼쪽첫번째 0번째 인덱스(첫번째 열)부터 값을 더하는데
	// 0 ~ n-1, 1 ~ n-1, 2 ~ n-1, ... n-2 ~ n-1, n-1 ~ n-1 순으로 작동
	// 우측 열의 기준은 좌측열이 시작하는 곳부터
	for (int left = 0; left < n; left++)
	{
		// 열 단위로 더하면서 부분합의 최댓값을 찾음
		int* col_sum = new int[n] {0, };
		for (int right = left; right < n; right++)
		{
			sub_sum = 0;
			tmp = 0;
			for (int k = 0; k < n; k++)
			{
				// 열들의 부분합
				col_sum[k] += arr[k][right];
				tmp += col_sum[k];
				// 부분합들의 합(tmp)을 이전에 저장해놓은 합들과 비교하여
				// tmp가 더크면 부분합을 더 큰 값으로 갱신
				// 이 때 인덱스값들도 새롭게 갱신
				if (tmp > sub_sum) {
					sub_sum = tmp;
					start = current_start;
					end = k;
				}
				// 부분합들의 합들이 0보다 작으면 비교할 필요가 없으므로
				// tmp를 0으로 할당한 후 그때의 인덱스 값을 새롭게 갱신
				if (tmp < 0) {
					tmp = 0;
					current_start = k + 1;
				}
			}
			// 부분합이 지금까지 합보다 크면 최댓값을 갱신
			// 이 때 시작점과 끝점 인덱스 값도 갱신
			if (sub_sum > total_sum) {
				_top = start;
				_bottom = end;
				total_sum = sub_sum;
				_left = left;
				_right = right;
			}
		}
	}
	// 값 출력
	cout << "SubArray Maximum Value : " << total_sum << endl;
	cout << "(" << _top << "," << _left << "), (" << _bottom << "," << _right << ")\n";
}
void FindMin(int** arr, int n) {
	int sub_sum = 0, total_sum = 0;
	int tmp, start = 0, end = 0;
	int _top = 0, _left = 0, _bottom = 0, _right = 0;
	int current_start = 0;

	// 최댓값 계산 방법과 진행순서는 동일
	for (int left = 0; left < n; left++)
	{
		int* col_sum = new int[n] {0, };
		for (int right = left; right < n; right++)
		{
			sub_sum = 0;
			tmp = 0;
			// 열들의 부분합 계산 및 비교 (최댓값 계산과 반대로 작동)
			for (int k = 0; k < n; k++)
			{
				col_sum[k] += arr[k][right];
				tmp += col_sum[k];
				if (tmp < sub_sum) {
					sub_sum = tmp;
					start = current_start;
					end = k;
				}

				if (tmp > 0) {
					tmp = 0;
					current_start = k + 1;
				}
			}
			// 최솟값 갱신
			if (sub_sum < total_sum) {
				total_sum = sub_sum;
				_top = start;
				_bottom = end;
				_left = left;
				_right = right;
			}
		}
	}
	// 값출력
	cout << "SubArray Minimum Value : " << total_sum << endl;
	cout << "(" << _top << "," << _left << "), (" << _bottom << "," << _right << ")\n";
}

void main() {
	int n;
	cin >> n;

	int** twoD = new int*[n];
	for (int i = 0; i < n; i++)
		twoD[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> twoD[i][j];

	FindMax(twoD, n);
	FindMin(twoD, n);

}