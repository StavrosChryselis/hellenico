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

using namespace std;

int N, M, C;

typedef struct
{
	vector<int> guess;
	vector<int> is;
	int n1;
	int n2;
}A;

vector<A> cases;
double ABC=0;

bool check(vector<int> Curr, vector<A> casess)
{
	int i, j;
	int tempn1, tempn2;

	for(i=0; i<N; i++)
	{
		tempn1=tempn2=0;

		for(j=0; j<Curr.size(); j++)
			if(Curr[j]==casess[i].guess[j])
			{
				tempn1++;
				casess[i].is[Curr[j]]--;
			}
		if(tempn1!=casess[i].n1)
			return 0;

		for(j=0; j<Curr.size(); j++)
			if(Curr[j]!=casess[i].guess[j] && casess[i].is[Curr[j]]>0)
			{
				tempn2++;
				casess[i].is[Curr[j]]--;
			}
		
		if(tempn2!=casess[i].n2)
			return 0;
	}

	return 1;
}
				
void is3()
{
	int i, j, k;
	vector<int> Try(3);

	for(i=1; i<=M; i++)
	{
		Try[0]=i;
		for(j=1; j<=M; j++)
		{
			Try[1]=j;
			for(k=1; k<=M; k++)
			{
				Try[2]=k;
				if(check(Try, cases))
					ABC++;
			}
		}
	}

}

void is4()
{
	int i, j, k, l;
	vector<int> Try(4);

	for(i=1; i<=M; i++)
	{
		Try[0]=i;
		for(j=1; j<=M; j++)
		{
			Try[1]=j;
			for(k=1; k<=M; k++)
			{
				Try[2]=k;
				for(l=1; l<=M; l++)
				{
					Try[3]=l;
					if(check(Try, cases))
						ABC++;
				}
			}
		}
	}

}

void is5()
{
	int i, j, k, l, s;
	vector<int> Try(5);

	for(i=1; i<=M; i++)
	{
		Try[0]=i;
		for(j=1; j<=M; j++)
		{
			Try[1]=j;
			for(k=1; k<=M; k++)
			{
				Try[2]=k;
				for(l=1; l<=M; l++)
				{
					Try[3]=l;
					for(s=1; s<=M; s++)
					{
						Try[4]=s;
						if(check(Try, cases))
							ABC++;
					}
				}
			}
		}
	}

}

int main()
{
	int i, j;
	A temp;

	freopen("mastermind.in","r",stdin);
	freopen("mastermind.out","w",stdout);

	scanf("%d %d %d", &N, &M, &C);
	temp.guess.resize(C);
	temp.is.resize(M+1);

	for(i=0; i<N; i++)
	{
		for(j=0; j<C; j++)
		{
			scanf("%d", &temp.guess[j]);
			temp.is[temp.guess[j]]++;
		}
		scanf("%d %d", &temp.n1, &temp.n2);
		cases.push_back(temp);
		for(j=0; j<C; j++)
			temp.is[temp.guess[j]]=0;
	}

	if(C==3)
		is3();
	else if(C==4)
		is4();
	else if(C==5)
		is5();

	printf("%.0lf\n", ABC);
		
	return 0;
}
