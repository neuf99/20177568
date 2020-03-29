#include <iostream>

using namespace std;

int P[9][9];
bool flag = false;

// 处理输入 
void input() {
	char t;
	cout << "输入棋盘，空用 0 表示\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> t;
			P[i][j] = t - '0';
		}
	}
}

// 处理输出 
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

// 判断即将放入的 是否符合条件 
bool check(int n, int num) {

	// 行 
	for (int i = 0; i < 9; i++) {
		if (P[n / 9][i] == num) {
			return false;
		}
	}

	// 列 
	for (int i = 0; i < 9; i++) {
		if (P[i][n % 9] == num) {
			return false;
		}
	}

	// 宫
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

	// 成功 
	if (n > 80) {
		flag = true;
		return;
	}

	int x = n / 9, y = n % 9;
	// 有值 跳过 
	if (P[x][y]) {
		dfs(n + 1);
		return;
	}
	// 遍历 
	for (int i = 1; i <= 9; i++) {
		// 判断 
		if (check(n, i)) {
			// 判断成功 赋值 
			P[x][y] = i;
			dfs(n + 1);
			// 退出时判断是否完成  完成时退出 
			if (flag) {
				return;
			}
			// 未完成 重置棋盘 
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