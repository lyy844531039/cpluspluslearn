#include<iostream>
#include<algorithm>
using namespace std;
int tot = 0;//total number of answers
int n;//on No.cur row can select n positions to place the queen
int C[20];//the queen place on No.x row, No.C[x] column.
//search on No.cur row 
void search(int cur) {
	if (cur == n) tot++;
	else
	{
		for (int i = 0; i < n; i++)//try to place on the ith column
		{
			bool ok = false;
			C[cur] = i;
			for (int j = 0; j < cur; j++)
				if (C[j] == C[cur] || cur + C[cur] == j + C[j] || cur - C[j] == j - C[cur])
				{
					ok = false;
					break;
				}
			if (ok) search(cur + 1);
		}
	}
}

int vis[2][40];

void search2(int cur)
{
	if (cur == n) tot++;
	else
	{
		for (int i = 0; i < n; i++)//try to place on the ith column
		{
			if (!vis[0][i] && !vis[1][i + cur] && !vis[2][i - cur + n])
			{
				C[cur] = i;
				vis[0][i] = vis[1][i + cur] = vis[2][i - cur + n] = 1;
				search(cur + 1);
				vis[0][i] = vis[1][i + cur] = vis[2][i - cur + n] = 0;//reduction in backtracking
			}
		}
	}
}
