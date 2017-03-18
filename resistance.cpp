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
#include <ctype.h>
#define gc() getchar_unlocked()

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

inline int FAST_IO()
{
    char ch;
    int val=0;
    ch=gc();
    while(isspace(ch) && ch!=EOF)
            ch=gc();
    val=0;
    while(isdigit(ch))
    {
        val=(val*10)+(ch-'0');
        ch=gc();
    }
    return val;
}

struct p
{
	int first;
	int second;
};

bool operator<(const p &a,const p &b)
{
	return 0;
}

list<pair<int, p > >G; 
int N, E;
int DYN;

void kruskal()
{
	int v=0;
	list<pair<int, p > >::iterator ii;
	ufs g(N+1);

	G.sort();
	ii=G.end();
	ii--;

	while(v<N-1)
	{
		if(!g.is_same_set(ii->second.first, ii->second.second))
		{
			v++;
			g.union_sets(ii->second.first, ii->second.second);
			ii=G.erase(ii);
			ii--;
		}
		else
			ii--;
	}
}

void init()
{
	int i;
	p temp;
	int w;

	N = FAST_IO();
	E = FAST_IO();
	DYN = FAST_IO();
	//scanf("%d %d %d", &N, &E, &DYN);

	for(i=0; i<E; i++)
	{
		temp.first = FAST_IO();
		temp.second = FAST_IO();
		w = FAST_IO();
		//scanf("%d %d %d", &temp.first, &temp.second, &w);
		G.push_back(make_pair(w, temp));
	}
}

int count()
{
	int counter=0;
	list< pair<int, p > >::iterator ii;

	for(ii=G.begin(); ii!=G.end(); ii++) 
	{
		if(DYN- ii->first >=0)
		{
			counter++;
			DYN-=ii->first;
		}
		else
			return counter;
	}

	return counter;
}

int main()
{
	freopen("resistance.in","r",stdin);
	freopen("resistance.out","w",stdout);

	init();
	kruskal();
	printf("%d\n", count());

	return 0;
}
