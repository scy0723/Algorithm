//2019055078_Ω≈√§øµ
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int s[3][100];
int a[3][100];
int t[3][100];
int l[3][100];

int main() {
	int N, e1, e2, x1, x2;
	int ss, ll;
	cin >> N;
	cin >> e1 >> e2;
	cin >> x1 >> x2;
	for (int i= 1; i <= N; i++)
	{
		int num;
		cin >> num;
		a[1][i] = num;
	}
	for (int i= 1; i <= N; i++)
	{
		int num;
		cin >> num;
		a[2][i]= num;
	}
	for (int i = 1; i < N; i++)
	{
		int num;
		cin >> num;
		t[1][i] = num;
	}
	for (int i = 1; i < N; i++)
	{
		int num;
		cin >> num;
		t[2][i] = num;
	}
	s[1][1] = e1 + a[1][1];
	s[2][1] = e2 + a[2][1];

	for (int i = 2; i <= N; i++)
	{
		if (s[1][i - 1] <= s[2][i - 1] + t[2][i - 1]) {
			s[1][i] = s[1][i - 1] + a[1][i];
			l[1][i] = 1;
		}
		else {
			s[1][i] = s[2][i - 1] + t[2][i - 1] + a[1][i];
			l[1][i] = 2;
		}
		if (s[2][i - 1] <= s[1][i - 1] + t[1][i - 1]) {
			s[2][i] = s[2][i - 1] + a[2][i];
			l[2][i] = 2;
		}
		else {
			s[2][i] = s[1][i - 1] + t[1][i - 1] + a[2][i];
			l[2][i] = 1;
		}
	}
	if (s[1][N] + x1 <= s[2][N] + x2) {
		ss = s[1][N] + x1;
		ll = 1;
	}
	else {
		ss = s[2][N] + x2;
		ll = 2;
	}
	cout << ss << endl;

	vector<int> track;
	track.push_back(0);
	track.push_back(ll);
	int i = ll;
	for (int j = N; j >= 2; j--) {
		i = l[i][j];
		track.push_back(i);
	}

	for (int k = N; k >= 1; k--)
	{
		cout << track[k] << " " << N+1-k << endl;
	}

}