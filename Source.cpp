// Лабораторна робота № 5.4
// Колмикова Катерина
//варіант 12
#include <iostream>
#include <cmath>
using namespace std;
double S0( const int N, const int K)
{
	double s = 0;
	for (int i = N; i <= K; i++)
		s += sqrt(i * i + N * N) / i;
	return s;
}
double S1( const int N, const int K, const int i)
{
	if (i > K)
		return 0;
	else
		return sqrt(i * i + N * N) / i + S1(N, K, i + 1);
}
double S2( const int N, const int K, const int i)
{
	if (i < N)
		return 0;
	else
		return sqrt(i * i + N * N)/i + S2(N, K, i - 1);
}
double S3( const int N, const int K, const int i, double t)
{
	t = t + sqrt(i * i + N * N)/i;
	if (i >= K)
		return t;
	else
		return S3( N, K, i + 1, t);
}
double S4( const int N, const int K, const int i, double t)
{
	t = t + sqrt(i * i + N * N) / i;
	if (i <= N)
		return t;
	else
		return S4( N, K, i - 1, t);
}
int main()
{
	int  N;
	int K = 22;
	cout << "N = "; cin >> N;
	cout << "(iter) S0 = " << S0( N, K) << endl;
	cout << "(rec up ++) S1 = " << S1( N,K,N) << endl;
	cout << "(rec up --) S2 = " << S2( N,K,K) << endl;
	cout << "(rec down ++) S3 = " << S3( N, K, N, 0) << endl;
	cout << "(rec down --) S4 = " << S4( N, K, K, 0) << endl;
	return 0;
}