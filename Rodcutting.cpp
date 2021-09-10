//2019055078_Ω≈√§øµ
#include<stdio.h>
#include<iostream>
using namespace std;

int p[100];
int r[100];
int s[100];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		p[i] = num;
	}
	r[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		int q = -999999;
		for (int j = 1; j <= i; j++)
		{
			if (q < p[j] + r[i - j]) {
				q = p[j] + r[i - j];
				s[i] = j;
			}
			r[i] = q;
		}
	}
	int n = N;
	cout << r[n] << endl;
	while (n > 0) {
		cout << s[n]<< " ";
		n = n - s[n];
	}
}