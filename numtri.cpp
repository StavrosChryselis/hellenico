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
#include <algorithm>

using namespace std;

int N;
vector< vector<int> > Pyramid;

void init()
{
	int i, j;

	scanf("%d", &N);
	Pyramid.resize(N);

	for(i=0; i<N; i++)
	{
		Pyramid[i].resize(i+1);

		for(j=0; j<=i; j++)
			scanf("%d", &Pyramid[i][j]);
	}
}

void compute()
{
	int i, j;

	for(i=N-2; i>=0; i--)
	{
		for(j=0; j<Pyramid[i].size(); j++)
			Pyramid[i][j]=max(Pyramid[i][j]+Pyramid[i+1][j], Pyramid[i][j]+Pyramid[i+1][j+1]);
	}
}

int main()
{
	freopen("numtri.in","r",stdin);
	freopen("numtri.out","w",stdout);

	init();
	compute();
	printf("%d\n", Pyramid[0][0]);
	return 0;
}
