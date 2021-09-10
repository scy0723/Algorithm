//2019055078_Ω≈√§øµ

#include<stdio.h>
#include<iostream>

using namespace std;

int m[101][101];
int s[101][101];
void printParens(int s[][101], int i, int j);

int main() {
	int N;
	cin >> N;
	int* p = new int(N + 2);
	for (int i = 0; i <= N; i++) {
		int num;
		cin >> num;
		p[i] = num;
	}
	int j = 0 , q = 0;
	for (int i = 1; i <= N; i++)
	{
		m[i][i] = 0;
	}
	for (int l = 2; l <= N; l++)
	{
		for (int i = 1; i <= N - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = 99999999;
			for (int k = i; k <= j-1; k++)
			{
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

	cout << m[1][N] << endl;
	printParens(s, 1, N);
}
void printParens(int s[][101], int i, int j) {
	if (i == j)
		cout << i<<" ";

	else {
		cout << "( ";
		printParens(s, i, s[i][j]);
		printParens(s, s[i][j] + 1, j);
		cout << ") ";
	}
}