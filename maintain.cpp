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

#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define edge pair< int, int >
#define MAX 1001

// ( w (u, v) ) format
vector< pair< int, edge > > GRAPH, MST, BAN;
int parent[MAX], total, N, E;
pair<int, edge> banned;

int findset(int x, int *parent)
{
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}

vector< pair< int, edge > > kruskal(vector< pair< int, edge > > GRAPH, int E)
{
    int i, pu, pv;
	vector< pair< int, edge > > MST;
    sort(GRAPH.begin(), GRAPH.end()); // increasing weight
    for(i=total=0; i<E; i++)
    {
        pu = findset(GRAPH[i].second.first, parent);
        pv = findset(GRAPH[i].second.second, parent);
        if(pu != pv)
        {
            MST.push_back(GRAPH[i]); // add to tree
            total += GRAPH[i].first; // add edge cost
            parent[pu] = parent[pv]; // link
        }
    }

	return MST;
}

void reset()
{
    // reset appropriate variables here
    // like MST.clear(), GRAPH.clear(); etc etc.
	total=0;
    for(int i=1; i<=N; i++) parent[i] = i;
}

int main()
{
    int i, u, v, w;

	freopen("maintain.in","r",stdin);
	freopen("maintain.out","w",stdout);

    scanf("%d %d", &N, &E);

	scanf("%d %d %d", &u, &v, &w);
    GRAPH.push_back(pair< int, edge >(w, edge(u, v)));
	reset();
	MST=kruskal(GRAPH, 1);

	if(MST.size()<N-1)
		printf("-1\n");
	else
		printf("%d\n", total);

    for(i=1; i<E; i++)
    {
		reset();
        scanf("%d %d %d", &u, &v, &w);
        MST.push_back(pair< int, edge >(w, edge(u, v)));
		MST=kruskal(MST, MST.size());

		if(MST.size()<N-1)
			printf("-1\n");
		else
			printf("%d\n", total);

    }


    return 0;
}
