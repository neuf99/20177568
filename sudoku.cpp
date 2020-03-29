#include <iostream>

using namespace std;

int P[9][9];
bool flag = false;

// �������� 
void input() {
	char t;
	cout << "�������̣����� 0 ��ʾ\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> t;
			P[i][j] = t - '0';
		}
	}
}

// ������� 
void output() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			if (P[i][j]) {
				cout << P[i][j];
			}
			else {
				cout << " ";
			}

			if (j % 3 == 2) cout << "  ";
		}
		if (i % 3 == 2) cout << endl;
		cout << endl;
	}

}

// �жϼ�������� �Ƿ�������� 
bool check(int n, int num) {

	// �� 
	for (int i = 0; i < 9; i++) {
		if (P[n / 9][i] == num) {
			return false;
		}
	}

	// �� 
	for (int i = 0; i < 9; i++) {
		if (P[i][n % 9] == num) {
			return false;
		}
	}

	// ��
	int x = n / 9 / 3 * 3;
	int y = n % 9 / 3 * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (P[x + i][y + j] == num) {
				return false;
			}
		}
	}

	return true;
}

// [n/9][n%9]
void dfs(int n) {

	// �ɹ� 
	if (n > 80) {
		flag = true;
		return;
	}

	int x = n / 9, y = n % 9;
	// ��ֵ ���� 
	if (P[x][y]) {
		dfs(n + 1);
		return;
	}
	// ���� 
	for (int i = 1; i <= 9; i++) {
		// �ж� 
		if (check(n, i)) {
			// �жϳɹ� ��ֵ 
			P[x][y] = i;
			dfs(n + 1);
			// �˳�ʱ�ж��Ƿ����  ���ʱ�˳� 
			if (flag) {
				return;
			}
			// δ��� �������� 
			P[x][y] = 0;
		}
	}
}

int main() {
	input();
	cout << endl << endl;
	dfs(0);
	output();
	return 0;
}