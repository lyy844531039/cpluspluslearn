#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int vis[20];
int A[20];

bool is_prime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i*i <= n; i++)
		if (n%i == 0) return false;
	return true;
}

void search(int n, int *A, int cur)
{
	if (cur == n)
	{
		if (is_prime(A[0] + A[n - 1]))
		{
			for (int i = 0; i < n; i++)
				cout << A[i] << " ";
			cout << endl;
		}
	}
	else
	{
		for (int i = 2; i <= n; i++)
			if (!vis[i] && is_prime(A[cur - 1] + i))
			{
				vis[i] = 1;
				A[cur] = i;
				search(n, A, cur + 1);
				vis[i] = 0;
			}
	}


}


int main()
{
	int n;
	while (cin >> n) {
		memset(vis, 0, sizeof(vis));
		A[0] = 1;
		search(n, A, 1);
	}
}
