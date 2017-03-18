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
#include <list>
#include <vector>

using namespace std;

int start[9];
vector< vector<int> > moves(9);

struct A
{
	int sol[9];
	int next;
	vector<int> from;
	vector<int> times;
};

list<A> work;

void generate_moves()
{
	moves[0].push_back(0);
	moves[0].push_back(1);
	moves[0].push_back(3);
	moves[0].push_back(4);

	moves[1].push_back(0);
	moves[1].push_back(1);
	moves[1].push_back(2);

	moves[2].push_back(1);
	moves[2].push_back(2);
	moves[2].push_back(4);
	moves[2].push_back(5);

	moves[3].push_back(0);
	moves[3].push_back(3);
	moves[3].push_back(6);

	moves[4].push_back(1);
	moves[4].push_back(3);
	moves[4].push_back(4);
	moves[4].push_back(5);
	moves[4].push_back(7);

	moves[5].push_back(2);
	moves[5].push_back(5);
	moves[5].push_back(8);

	moves[6].push_back(3);
	moves[6].push_back(4);
	moves[6].push_back(6);
	moves[6].push_back(7);

	moves[7].push_back(6);
	moves[7].push_back(7);
	moves[7].push_back(8);

	moves[8].push_back(4);
	moves[8].push_back(5);
	moves[8].push_back(7);
	moves[8].push_back(8);
}


inline void input()
{
	int i;

	for(i=0; i<9; i++)
		scanf("%d", &start[i]);
}

inline bool is_sol(int B[9])
{
	int i;

	for(i=0; i<9; i++)
		if(B[i]%4!=0)
			return 0;
	return 1;
}

void solve()
{
	int i, temp;
	A curr;
	vector<int> answer;

	while(1)
	{
		curr=work.front();
		work.pop_front();
		curr.from.push_back(curr.next);
		
		if(curr.times[curr.next]<=2)
		{
			curr.times[curr.next]++;

			for(i=0; i<moves[curr.next].size(); i++)
				curr.sol[moves[curr.next][i]]++;

			if(is_sol(curr.sol))
			{
				for(i=0; i<curr.from.size(); i++)
					printf("%d ", curr.from[i]+1);
				return;
			}
		
			temp=curr.next;
			for(i=temp; i<9; i++)
			{
				curr.next=i;
				work.push_back(curr);
			}
		}
	}
}

int main()
{
	int solution[9];
	int i;
	A temp;

	freopen("clocks.in","r",stdin);
	freopen("clocks.out","w",stdout);

	generate_moves();
	input();
	
	copy(start, start+9, temp.sol);
	
	for(i=0; i<9; i++)
	{
		temp.times.resize(9);
		temp.next=i;
		work.push_back(temp);
	}

	solve();


	return 0;
}
