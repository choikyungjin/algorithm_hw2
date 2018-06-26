/* 2014726074 ��ǻ�� ����Ʈ�����а� �ְ��� */

#include <iostream>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

using namespace std;

void FindMax(int** arr, int n) {
	// ��� ���� �ʱ�ȭ ���� �� ����
	int sub_sum = 0, total_sum = 0;
	int tmp, start = 0, end = 0;
	int _top = 0, _left = 0, _bottom = 0, _right = 0;
	int current_start = 0;

	// ���� ������ ����ù��° 0��° �ε���(ù��° ��)���� ���� ���ϴµ�
	// 0 ~ n-1, 1 ~ n-1, 2 ~ n-1, ... n-2 ~ n-1, n-1 ~ n-1 ������ �۵�
	// ���� ���� ������ �������� �����ϴ� ������
	for (int left = 0; left < n; left++)
	{
		// �� ������ ���ϸ鼭 �κ����� �ִ��� ã��
		int* col_sum = new int[n] {0, };
		for (int right = left; right < n; right++)
		{
			sub_sum = 0;
			tmp = 0;
			for (int k = 0; k < n; k++)
			{
				// ������ �κ���
				col_sum[k] += arr[k][right];
				tmp += col_sum[k];
				// �κ��յ��� ��(tmp)�� ������ �����س��� �յ�� ���Ͽ�
				// tmp�� ��ũ�� �κ����� �� ū ������ ����
				// �� �� �ε������鵵 ���Ӱ� ����
				if (tmp > sub_sum) {
					sub_sum = tmp;
					start = current_start;
					end = k;
				}
				// �κ��յ��� �յ��� 0���� ������ ���� �ʿ䰡 �����Ƿ�
				// tmp�� 0���� �Ҵ��� �� �׶��� �ε��� ���� ���Ӱ� ����
				if (tmp < 0) {
					tmp = 0;
					current_start = k + 1;
				}
			}
			// �κ����� ���ݱ��� �պ��� ũ�� �ִ��� ����
			// �� �� �������� ���� �ε��� ���� ����
			if (sub_sum > total_sum) {
				_top = start;
				_bottom = end;
				total_sum = sub_sum;
				_left = left;
				_right = right;
			}
		}
	}
	// �� ���
	cout << "SubArray Maximum Value : " << total_sum << endl;
	cout << "(" << _top << "," << _left << "), (" << _bottom << "," << _right << ")\n";
}
void FindMin(int** arr, int n) {
	int sub_sum = 0, total_sum = 0;
	int tmp, start = 0, end = 0;
	int _top = 0, _left = 0, _bottom = 0, _right = 0;
	int current_start = 0;

	// �ִ� ��� ����� ��������� ����
	for (int left = 0; left < n; left++)
	{
		int* col_sum = new int[n] {0, };
		for (int right = left; right < n; right++)
		{
			sub_sum = 0;
			tmp = 0;
			// ������ �κ��� ��� �� �� (�ִ� ���� �ݴ�� �۵�)
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
			// �ּڰ� ����
			if (sub_sum < total_sum) {
				total_sum = sub_sum;
				_top = start;
				_bottom = end;
				_left = left;
				_right = right;
			}
		}
	}
	// �����
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