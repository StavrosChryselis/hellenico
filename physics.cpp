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
#include <iostream>

using namespace std;

typedef struct
{
	int a;
	int b;
	int c;
}my;

vector<long int> pos;
vector<my> Arr;
long int N;
vector<long int> prob;
vector<long int> countB, countC, countA;
long int counter;
vector<bool> Visited;

void init()
{
	int i;

	cin>>N;
	pos.resize(N+1);
	Arr.resize(N+1);
	countB.resize(N+1);
	countC.resize(N+1);
	countA.resize(N+1);
	Visited.resize(N+1);

	for(i=1; i<=N; i++)
	{
		cin>>Arr[i].a;
		pos[Arr[i].a]=i;
		countA[i]++;
	}

	for(i=1; i<=N; i++)
	{
		cin>>Arr[i].b;
		countB[Arr[i].b]++;
	}

	for(i=1; i<=N; i++)
	{
		cin>>Arr[i].c;
		countC[Arr[i].c]++;
	}

	for(i=1; i<=N; i++)
		if(countB[i]==0 || countC[i]==0)
			if(!Visited[i])
			{
				prob.push_back(i);
				Visited[i]=1;
			}
}

void solve()
{
	int num, b, c;

	while(!prob.empty())
	{
		num=prob.back();
		prob.pop_back();
		Visited[num]=1;
		counter++;
		
		countA[num]--;
		b=Arr[pos[num]].b;
		c=Arr[pos[num]].c;
		countB[b]--;
		countC[c]--;
		if(countB[b]<countA[b] && Visited[b]!=1)
		{
			Visited[b]=1;
			prob.push_back(b);
		}
		if(countC[c]<countA[c] && Visited[c]!=1)
		{
			Visited[c]=1;
			prob.push_back(c);
		}
	}
}

int main()
{
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	init();
	solve();
	cout<<counter<<endl;

	return 0;
}
