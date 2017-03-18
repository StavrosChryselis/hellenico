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
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

short int V[6][6][6][6][6][6][6][6];
vector<string> board(6);
int di[]={-1, 0, 0, 1};
int dj[]={0, -1, 1, 0};
int perm[]={0,1,2,3};

vector< pair<int, int> > ploc(4);

void Visit(vector< pair<int, int> > ploc, int val, int perm[])
{
	do
	{
		V[ploc[perm[0]].first][ploc[perm[0]].second][ploc[perm[1]].first][ploc[perm[1]].second][ploc[perm[2]].first][ploc[perm[2]].second][ploc[perm[3]].first][ploc[perm[3]].second]=val;
	}while(next_permutation(perm, perm+4));
}

queue< vector< pair<int, int> > > Q;

void init()
{
	int i;

	for(i=0; i<6; i++)
		cin>>board[i];

	ploc[0].first=4;
	ploc[0].second=4;

	ploc[1].first=5;
	ploc[1].second=4;

	ploc[2].first=4;
	ploc[2].second=5;

	ploc[3].first=5;
	ploc[3].second=5;

	Visit(ploc, 0, perm);
	Q.push(ploc);
}

bool dim_ok(pair<int, int> ploc)
{
	if(ploc.first<0 || ploc.second<0 || ploc.first>=6 || ploc.second>=6)
			return 0;
	return 1;
}

int board_ok(pair<int, int> ploc, vector< pair<int, int> > pionia)
{
	int i;
	int flag;

	for(i=0; i<pionia.size(); i++)
		board[pionia[i].first][pionia[i].second]='p';

	if(board[ploc.first][ploc.second]=='r')
		flag=-1;
	else if(board[ploc.first][ploc.second]!='.')
		flag=0;
	else
		flag=1;
	
	for(i=0; i<pionia.size(); i++)
		board[pionia[i].first][pionia[i].second]='.';
	return flag;

}

int check_v(int pos, pair<int, int> test, vector< pair<int, int> > ploc)
{
	switch(pos)
	{
		case 0:
			if(V[test.first][test.second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second]==0 || V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second]+1<V[test.first][test.second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second])
			{
				V[test.first][test.second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second]=V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second]+1;
				return V[test.first][test.second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second];
			}
			else return 0;

		case 1:
			if(V[ploc[0].first][ploc[0].second][test.first][test.second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second]==0 || V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second]+1<V[ploc[0].first][ploc[0].second][test.first][test.second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second])
			{
				V[ploc[0].first][ploc[0].second][test.first][test.second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second]=V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second]+1;
				return V[ploc[0].first][ploc[0].second][test.first][test.second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second];
			}
			else return 0;

		case 2:
			if(V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][test.first][test.second][ploc[3].first][ploc[3].second]==0 || V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second]+1<V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][test.first][test.second][ploc[3].first][ploc[3].second])
			{
				V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][test.first][test.second][ploc[3].first][ploc[3].second]=V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second]+1;
				return V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][test.first][test.second][ploc[3].first][ploc[3].second];
			}
			else return 0;

		case 3:
			if(V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][test.first][test.second]==0 || V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second]+1<V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][test.first][test.second])
			{
				V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][test.first][test.second]=V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][ploc[3].first][ploc[3].second]+1;
				return V[ploc[0].first][ploc[0].second][ploc[1].first][ploc[1].second][ploc[2].first][ploc[2].second][test.first][test.second];
			}
			else return 0;
	}
}

void work(vector< pair<int, int> > curr)
{
	int i, j;
	pair<int, int> temp;
	vector< pair<int, int> > T;
	int val;

	for(i=0; i<4; i++)
	{
		for(j=0; j<5; j++)
		{
			temp.first=curr[i].first+di[j];
			temp.second=curr[i].second+dj[j];
			if(dim_ok(temp))
			{
				val=board_ok(temp, curr);
				if(val==1)
				{
					val=check_v(i,temp,curr);
					if(val!=0)
					{
						T=curr;
						T[i]=temp;
						Q.push(T);
						Visit(T, val, perm);
					}
				}
				else if(val!=-1)
				{
					temp.first+=di[j];
					temp.second+=dj[j];
					if(dim_ok(temp) && board_ok(temp, curr)==1)
					{
						val=check_v(i,temp,curr);
						if(val!=0)
						{
							T=curr;
							T[i]=temp;
							Q.push(T);
							Visit(T, val, perm);
						}
					}
				}
			}
		}
	}
}

void bfs()
{
	while(!Q.empty())
	{
		ploc=Q.front();
		Q.pop();
		work(ploc);
	}
}

int main()
{
	freopen("corners.in","r",stdin);
	freopen("corners.out","w",stdout);

	init();
	bfs();

	if(V[0][0][1][0][0][1][1][1]==0)
		printf("-1\n");
	else
		printf("%d\n", V[0][0][1][0][0][1][1][1]);
	return 0;
}
