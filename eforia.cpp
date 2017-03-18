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
#include <set>
#include <limits.h>
#include <algorithm>
#include <iostream>

using namespace std;

vector< vector<pair<int, long long> > > G;
vector<long long> D;
int N, E;
vector<int> odds;
long long all;

void dijkstra(int root)
{
	set<pair<long long, int> > S;
	int i;
	long long alt;
	pair<long long, int> u;

	for(i=1; i<=N; i++)
		D[i]=LLONG_MAX;

	D[root]=0;

	S.insert(make_pair(0, root));
	S.insert(make_pair(LLONG_MAX, N+1));

	while(S.begin()->first!=LLONG_MAX)
	{
		u=*S.begin();
		S.erase(S.begin());
	
		for(i=0; i<G[u.second].size(); i++)
		{
			alt=u.first + G[u.second][i].second;
			if(alt<D[G[u.second][i].first])
			{
				D[G[u.second][i].first]=alt;
				S.insert(make_pair(D[G[u.second][i].first], G[u.second][i].first));
			}
		}
	}
}





void init()
{
	int i;
	int f, s;
	long long w;
	vector<int> appear;

	scanf("%d %d", &N, &E);

	G.resize(N+1);
	appear.resize(N+1);

	for(i=0; i<N+1; i++)
	{
		appear[i]=0;
		G[i].resize(N+1);
	}

	D.resize(N+1);

	for(i=0; i<E; i++)
	{
		scanf("%d %d %lld", &f, &s, &w);
		appear[f]++;
		appear[s]++;
		all+=w;
		G[f].push_back(make_pair(s, w));
		G[s].push_back(make_pair(f, w));
	}
	
	for(i=1; odds.size()!=2; i++)
		if(appear[i]%2)
			odds.push_back(i);
}

int main()
{
	freopen("eforia.in","r",stdin);
	freopen("eforia.out","w",stdout);

	init();

	dijkstra(odds[0]);
	
	all+=D[odds[1]];
	//cout<<all<<endl;
	printf("%lld\n", all);


	return 0;
}
