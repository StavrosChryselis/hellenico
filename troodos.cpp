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

#include <stdio.h>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <deque>

using namespace std;

vector< vector< pair< int, int > > > G, RG; //v, w
int MIN[10007], MAX[10007];
bool MARKED[10007];
int N, E, sum, rest;

inline void init()
{
	int i, f, s, w;

	scanf("%d %d", &N, &E);

	G.resize(N);
	RG.resize(N);

	for (i = 0; i < E; i++)
	{
		scanf("%d %d %d", &f, &s, &w);
		G[f].push_back(make_pair(s, w));
		RG[s].push_back(make_pair(f, w));
	}

	for (i = 0; i < N; i++)
		MIN[i] = INT_MAX;

	rest = N;
	
}

inline void solve()
{
	int i, j, curr;
	deque<int> Q;

	MIN[0] = 0;

	for (i = 0; i < N - 1; i++)
	{
		sum += MAX[i] - MIN[i];
		for (j = 0; j < G[i].size(); j++)
		{
			MAX[G[i][j].first] = max(MAX[G[i][j].first], MAX[i] + G[i][j].second);
			MIN[G[i][j].first] = min(MIN[G[i][j].first], MAX[i] + G[i][j].second);
		}
	}

	sum += MAX[N - 1] - MIN[N - 1];
	
	Q.push_back(N - 1);
	MARKED[N - 1] = 1;

	while (!Q.empty())
	{
		curr = Q.front();
		Q.pop_front();
		rest--;

		for (i = 0; i < RG[curr].size(); i++)
			if (MAX[curr] - RG[curr][i].second == MAX[RG[curr][i].first] && !MARKED[RG[curr][i].first])
			{
				MARKED[RG[curr][i].first] = 1;
				Q.push_back(RG[curr][i].first);
			}
	}	
}

int main()
{
	freopen("troodos.in", "r", stdin);
	freopen("troodos.out", "w", stdout);


	init();
	solve();
	printf("%d %d %d\n", MAX[N - 1], sum, rest);

	return 0;
}
