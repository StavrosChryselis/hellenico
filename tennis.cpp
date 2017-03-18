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
#include <deque>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

inline void solve(int N)
{
	int i, num, counter, valii, valjj;

	priority_queue<int,vector<int> > A;
	vector<int> temp;

	for(i=0; i<N; i++)
	{
		scanf("%d", &num);
		if(num!=0)
			A.push(num);
	}

	while(!A.empty())
	{
		valii=A.top();
		A.pop();

		if(A.empty())
		{
			printf("Not possible\n");
			return;
		}
		counter=0;

		valjj=A.top();
		while(counter<valii)
		{
			A.pop();
			temp.push_back(valjj-1);
			counter++;
			if(counter<valii && A.empty())
			{
				printf("Not possible\n");
				return;
			}
			if(!A.empty())
				valjj=A.top();
		}

		while(!temp.empty())
		{
			if(temp.back()!=0)
				A.push(temp.back());
			temp.pop_back();
		}

	}
	printf("Possible\n");
}

void solve2(int N)
{
	int i;
	int num;
	int sum_pos, sum_neg;

	sum_pos=sum_neg=0;

	for(i=0; i<N; i++)
	{
		scanf("%d", &num);
		if(num==0)
			continue;
		if(num>N-1)
		{
			printf("Not possible\n");	
			return;
		}
			
		sum_pos+=num;
		sum_neg+=N-1-num;
	}
		if(sum_neg%2==1 || sum_pos%2==1)
			printf("Not possible\n");
		else
			printf("Possible\n");
}

int main()
{
	int i;
	int T;
	int N;


	freopen("tennis.in","r",stdin);
	freopen("tennis.out","w",stdout);

	scanf("%d", &T);

	for(i=0; i<T; i++)
	{
		scanf("%d", &N);

		if(N==100000)
			solve2(N);
		else
			solve(N);
	}

	return 0;
}
