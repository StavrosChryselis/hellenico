/*
****************************************************************
****************************************************************
-> Coded by Stavros Chryselis				   
-> Visit my github for more solved problems over multiple sites 
-> https://github.com/StavrosChryselis			  
-> Feel free to email me at stavrikios@gmail.com	
****************************************************************
****************************************************************
*/

#include <iostream>  
#include <stdio.h>
#include <vector>    
#include <math.h>
#include <climits>

#define MAXN 1007
#define INF 3000000000
using namespace std;

vector< pair< pair<int, int>, double> > E;
int N, M;
double d[MAXN][MAXN];

inline double calc_val(int perc)
{
	double p = (double)perc / 100.0;

	p = 0.5 + 1.5 * p;

	return p;
}

void Read()
{
	int i, a, b, d;

	cin >> N >> M;

	E.clear();

	for (i = 1; i <= M; ++i)
	{
		cin >> a >> b >> d;
		E.push_back(make_pair(make_pair(a, b), -log10(calc_val(d))));
	}
}

inline bool Negative_Weight_Cycle()
{
	int i, j, k;

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			d[i][j] = INF;

	for (i = 1; i <= N; i++)
		d[i][i] = 0;

	for (i = 0; i < E.size(); i++)
		d[E[i].first.first][E[i].first.second] = E[i].second;

	for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j];

	for (i = 1; i <= N; i++)
		if (d[i][i] < 0)
			return 1;

	return 0;
}

inline bool solve()
{
	int i;

	if (Negative_Weight_Cycle())
		return 1;

	return 0;
}

int main()
{
	int i;

	ios::sync_with_stdio(0);
//	freopen("input.txt", "r", stdin);      
	freopen("millionaire.in", "r", stdin);
	freopen("millionaire.out", "w", stdout);

	cin >> i;

	while (i--)
	{
		Read();
		if (solve())
			cout << "Possible\n";
		else
			cout << "Not possible\n";
	}

	return 0;
}
