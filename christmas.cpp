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
#include <stdlib.h>
#include <vector>
#include <list>
#include <limits.h>

using namespace std;

class ufs
{
	private:
		struct set
		{
			int name;
			int rank;
			set *parent;
		};
		int ssize;
		vector<set> S;

		set *fs(int name)
		{
			if(S[name].parent->name==name)
				return &S[name];

			S[name].parent=fs(S[name].parent->name);
			return S[name].parent;
		}


	public:
		ufs(int n)
		{
			int i;
			ssize=n;
			S.resize(ssize);

			for(i=0; i<S.size(); i++)
			{
				S[i].name=i;
				S[i].parent=&S[i];
				S[i].rank=0;
			}
		}

		int find_set(int name)
		{
			return fs(name)->name;
		}

		bool is_same_set(int a, int b)
		{
			return fs(a)->name==fs(b)->name;
		}

		void union_sets(int a, int b)
		{
			set *f, *s;

			f=fs(a);
			s=fs(b);

			if(f->name==s->name)
				return;

			ssize--;
			if(f->rank==s->rank)
			{
				f->rank++;
				s->parent=f;
			}
	
			else if(f->rank > s->rank)
				s->parent=f;
	
			else
				f->parent=s;
		}

		int size()
		{
			return ssize;
		}
};

list<pair<long long, pair<int, int> > >G;
vector< vector<pair<int, long long> > > MST;
int N, E;
long long mst_w;
vector< vector<long long> > max_edge;

void kruskal()
{
	int v=0;
	list<pair<long long, pair<int, int> > >::iterator ii;
	ufs g(N+1);

	G.sort();
	ii=G.begin();

	while(v<N-1)
	{
		if(!g.is_same_set(ii->second.first, ii->second.second))
		{
			MST[ii->second.first].push_back(make_pair(ii->second.second, ii->first));
			MST[ii->second.second].push_back(make_pair(ii->second.first, ii->first));
			mst_w+=ii->first;
			v++;
			g.union_sets(ii->second.first, ii->second.second);
			ii=G.erase(ii);
		}
		else
			ii++;
	}
}

void calc_max(int u, int x)
{
	int i, v;

	for(i=0; i<MST[x].size(); i++)
	{
		v=MST[x][i].first;

		if(max_edge[u][v]==0)
		{
			if(x==u)
			{
				max_edge[u][v]=MST[x][i].second;
				//max_edge[v][u]=MST[x][i].second;
			}

			else
			{
				max_edge[u][v]=max(max_edge[u][x], MST[x][i].second);
				//max_edge[v][u]=max_edge[u][v];
			}

			calc_max(u, v);
		}
	
	}
}

void init()
{
	int i;
	int f, s;
	long long w;

	scanf("%d %d", &N, &E);

	MST.resize(N+1);
	max_edge.resize(N+1);

	for(i=0; i<N+1; i++)
		max_edge[i].resize(N+1);

	for(i=0; i<E; i++)
	{
		scanf("%d %d %lld", &f, &s, &w);
		G.push_back(make_pair(w, make_pair(f, s)));
	}
}

long long find_min()
{
	list<pair<long long, pair<int, int> > >::iterator ii;
	long long mmin=LLONG_MAX;

	for(ii=G.begin(); ii!=G.end(); ii++)
		mmin=min(mmin, ii->first - max_edge[ii->second.first][ii->second.second]);

	return mmin;
}

int main()
{
	int i;

	freopen("christmas.in","r",stdin);
	freopen("christmas.out","w",stdout);

	init();
	kruskal();
	
	for(i=1; i<=N; i++)
		calc_max(i, i);

	printf("%lld %lld\n", mst_w, mst_w + find_min());

	return 0;
}
