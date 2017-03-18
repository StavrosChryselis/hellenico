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
#include <list>
#include <iostream>

#define mmax 1000000

using namespace std;

vector<long long int> Dim(3);
vector<long long> Powers;
list< vector<long long int> > Next;
long long int counter;

void get_powers()
{
	long long int num=2;
	Powers.push_back(1);
	Powers.push_back(num);
	while(num<=mmax)
	{
		num*=2;
		Powers.push_back(num);
	}
	Powers.pop_back();
}

inline long long int findpow(long long int num)
{
	int i;
	for(i=Powers.size()-1; i>=0; i--)
		if(Powers[i]<=num)
			return Powers[i];
}

void solve()
{
	vector<long long int> Curr(3);
	long long int cube;
	long long int pmikos, pplatos, pipsos;
	long long int leftmikos, leftplatos, leftipsos;
	vector<long long int> Temp(3);

	while(!Next.empty())
	{
		Curr=Next.front();
		sort(Curr.begin(), Curr.end());
		Next.pop_front();
		cube=findpow(Curr[0]);
		pmikos=Curr[0]/cube;
		leftmikos=Curr[0]%cube;
		pplatos=Curr[1]/cube;
		leftplatos=Curr[1]%cube;
		pipsos=Curr[2]/cube;
		leftipsos=Curr[2]%cube;

		counter+=pmikos*pplatos*pipsos;

		if(leftipsos!=0)
		{
			Temp[0]=Curr[0];
			Temp[1]=Curr[1];
			Temp[2]=leftipsos;

			Next.push_back(Temp);
		}

		if(leftmikos!=0 && leftplatos!=0)
		{
			Temp[0]=leftmikos;
			Temp[1]=Curr[1];
			Temp[2]=Curr[2]-leftipsos;

			Next.push_back(Temp);

			Temp[0]=pmikos*cube;
			Temp[1]=leftplatos;
			Temp[2]=Curr[2]-leftipsos;

			Next.push_back(Temp);
		}

		else if(leftmikos!=0)
		{
			Temp[0]=leftmikos;
			Temp[1]=Curr[1];
			Temp[2]=Curr[2]-leftipsos;

			Next.push_back(Temp);
		}

		else if(leftplatos!=0)
		{
			Temp[0]=Curr[0];
			Temp[1]=leftplatos;
			Temp[2]=Curr[2]-leftipsos;

			Next.push_back(Temp);
		}

	}
}

		
		

int main()
{
	freopen("fillbox.in","r",stdin);
	freopen("fillbox.out","w",stdout);

	cin>>Dim[0]>>Dim[1]>>Dim[2];
	if(Dim[0]==0 || Dim[1]==0 || Dim[2]==0)
		cout<<"0"<<endl;
	else
	{
	sort(Dim.begin(), Dim.end());
	Next.push_back(Dim);
	get_powers();
	solve();
	cout<<counter<<endl;
	}

	return 0;
}
