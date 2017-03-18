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

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#define MAXN 2000007
using namespace std;

int tree[4 * MAXN];
bool is_lucky[MAXN];
vector<int> lucky_nums;
int N;

void init_tree(int node, int a, int b)
{
	if (a == b)
	{
		if (a % 2)
			tree[node] = 1;
		else
			tree[node] = 0;

		return;
	}

	int mid = (a + b) / 2;

	init_tree(node * 2, a, mid);
	init_tree(node * 2 + 1, mid + 1, b);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void erase_element(int node, int a, int b, int pos)
{
	if (pos > tree[node])
		return;

	if (a == b)
	{
		tree[node] = 0;
		return;
	}

	int mid = (a + b) / 2;

	if (pos <= tree[node * 2])
		erase_element(node * 2, a, mid, pos);
	else
		erase_element(node * 2 + 1, mid + 1, b, pos - tree[node * 2]);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int get_element(int node, int a, int b, int pos)
{
	if (pos > tree[node])
		return - 1;

	if (a == b)
		return a;

	int mid = (a + b) / 2;

	if (pos <= tree[node * 2])
		get_element(node * 2, a, mid, pos);
	else
		get_element(node * 2 + 1, mid + 1, b, pos - tree[node * 2]);
}

void extract_all(int node, int a, int b)
{
	if (!tree[node])
		return;

	if (a == b)
	{
		lucky_nums.push_back(a);
		return;
	}

	int mid = (a + b) / 2;

	extract_all(node * 2, a, mid);
	extract_all(node * 2 + 1, mid + 1, b);
}

inline bool erase_helper(int pos)
{
	int temp = get_element(1, 1, N, pos);
	int step = temp;

	if (temp == -1)
		return 0;

	while (tree[1] >= temp)
	{
		erase_element(1, 1, N, temp);
		temp += step - 1;
	}

	return 1;
}

inline void init()
{
	int pos = 2;

	cin >> N;

	init_tree(1, 1, N);

	while (erase_helper(pos))
		pos++;

	extract_all(1, 1, N);

	for (int i = 0; i < lucky_nums.size(); i++)
		is_lucky[lucky_nums[i]] = 1;
}

inline void solve()
{
	int i;
	vector<int>::iterator ii;

	for (ii = lower_bound(lucky_nums.begin(), lucky_nums.end(), N / 2); ii != lucky_nums.end(); ii++)
		if (is_lucky[N - *ii])
		{
			cout << N - *ii << " " << *ii << "\n";
			return;
		}
}

int main()
{
//	freopen("input.txt", "r", stdin);
	freopen("luckynum.in", "r", stdin);
	freopen("luckynum.out", "w", stdout);

	ios::sync_with_stdio(0);

	init();
	solve();

	return 0;
}
