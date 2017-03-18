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

#include <deque>
#include <climits>
#include <iostream>
#include <stdio.h>

using namespace std;

int N, M;

typedef struct
{
	bool left;
	bool right;
	bool up;
	bool down;
}r;

r rooms[60][60];
int sinistwsa[60][60];
int count_sinistwses;
deque< pair<int,int> > Next;
int mmax=-1, mmaxroom;
int sinistwses_pop[2501];
int posx, posy;
char C;

void init()
{
	int i, j;
	int temp;

	cin>>N>>M;
	

	for(i=1; i<=N; i++)
		for(j=1; j<=M; j++)
		{
			cin>>temp;
			rooms[i][j].down=temp/8;
			temp%=8;
			rooms[i][j].right=temp/4;
			temp%=4;
			rooms[i][j].up=temp/2;
			temp%=2;
			rooms[i][j].left=temp/1;
		}
}

void neighboors(int x, int y)
{
	if(rooms[x][y].left==0)
		Next.push_back(make_pair(x, y-1));
	if(rooms[x][y].up==0)
		Next.push_back(make_pair(x-1, y));
	if(rooms[x][y].right==0)
		Next.push_back(make_pair(x, y+1));
	if(rooms[x][y].down==0)
		Next.push_back(make_pair(x+1, y));
}

void flood_fill(int nea_sinistwsa)
{
	int num_visitors;
	int i, j;
	pair<int, int> temp;
	do
	{
		num_visitors=0;
		for(i=1; i<=N; i++)
			for(j=1; j<=M; j++)
			{
				if(sinistwsa[i][j]==-2)
				{
					num_visitors++;
					sinistwses_pop[nea_sinistwsa]++;
					sinistwsa[i][j]=nea_sinistwsa;
					neighboors(i, j);
					while(Next.empty()==0)
					{
						temp=Next.front();
						Next.pop_front();
						if(sinistwsa[temp.first][temp.second]==0)
							sinistwsa[temp.first][temp.second]=-2;
					}
				}
			}
	}while(num_visitors!=0);
}

void find_sinistwses()
{
	int i, j;
	count_sinistwses=0;

	for(i=1; i<=N; i++)
		for(j=1; j<=M; j++)
		{
			if(sinistwsa[i][j]==0)
			{
				count_sinistwses++;
				sinistwsa[i][j]=-2;
				flood_fill(count_sinistwses);
			}
		}
}

void find_wall()
{
	int i, j;

	for(j=1; j<=M-1; j++)
	{
		for(i=N; i>=2; i--)
		{
			if(sinistwsa[i][j]!=sinistwsa[i-1][j] && mmaxroom<sinistwses_pop[sinistwsa[i][j]]+sinistwses_pop[sinistwsa[i-1][j]])
			{
				mmaxroom=sinistwses_pop[sinistwsa[i][j]]+sinistwses_pop[sinistwsa[i-1][j]];
				posx=i;
				posy=j;
				C='N';
			}

			if(sinistwsa[i][j]!=sinistwsa[i][j+1] && mmaxroom<sinistwses_pop[sinistwsa[i][j]]+sinistwses_pop[sinistwsa[i][j+1]])
			{
				mmaxroom=sinistwses_pop[sinistwsa[i][j]]+sinistwses_pop[sinistwsa[i][j+1]];
				posx=i;
				posy=j;
				C='E';
			}
		}

		if(sinistwsa[1][j]!=sinistwsa[1][j] && mmaxroom<sinistwses_pop[sinistwsa[1][j]]+sinistwses_pop[sinistwsa[1][j+1]])
			{
				mmaxroom=sinistwses_pop[sinistwsa[1][j]]+sinistwses_pop[sinistwsa[1][j+1]];
				posx=1;
				posy=j;
				C='E';
			}
	}

	for(i=N; i>=2; i--)
	{
		if(sinistwsa[i][M]!=sinistwsa[i-1][M] && mmaxroom<sinistwses_pop[sinistwsa[i][M]]+sinistwses_pop[sinistwsa[i-1][M]])
			{
				mmaxroom=sinistwses_pop[sinistwsa[i][M]]+sinistwses_pop[sinistwsa[i-1][M]];
				posx=i;
				posy=M;
				C='N';
			}
	}

			
}
int main()
{
	int i;
	freopen("castle.in","r",stdin);
	freopen("castle.out","w",stdout);
	init();
	find_sinistwses();
	for(i=1; i<=count_sinistwses; i++)
		if(mmax<sinistwses_pop[i])
			mmax=sinistwses_pop[i];
	find_wall();
	cout<<count_sinistwses<<endl;
	cout<<mmax<<endl;
	cout<<mmaxroom<<endl;
	cout<<posx<<" "<<posy<<" "<<C<<" "<<endl;
	//printf("%d\n%d\n%d\n%d %d %c\n", count_sinistwses, mmax, mmaxroom, posx, posy, C);
	return 0;
}
