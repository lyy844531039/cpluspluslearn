#include<iostream>
#include<algorithm>
using namespace std;

//generate 1-n whole permutation
void print_permutation(int n, int *A, int cur)
{
	if (cur == n) {
		for (int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			bool ok = true;
			for (int j = 0; j < cur; j++)
			{
				if (A[j] == i)
					ok = false;
			}
			if (ok)
			{
				A[cur] = i;
				print_permutation(n, A, cur + 1);
			}
		}
	}
}

//generate repeatable permutation
//precondition: P must be sorted
void print_Rpermutation(int n, int *P, int *A, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
			cout << A[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < n && (!i || P[i - 1] != P[i]); i++)
			//!i || P[i - 1] != P[i] ensures repeated permutations are eliminated
		{
			int c1 = 0, c2 = 0;
			for (int j = 0; j < cur; j++)
				if (P[i] == A[j]) c1++;
			for (int j = 0; j < n; j++)
				if (P[i] == P[j]) c2++;
			if (c1 < c2)
			{
				A[cur] = P[i];
				print_Rpermutation(n, P, A, cur + 1);
			}

		}
	}
}

//using STL(in algorithm.h) next_permutation
//It also can be used in repeatable permutation
void print_permutation(int *P, int n)
{
	sort(P, P + n);
	do {
		for (int i = 0; i < n; i++)
			cout << P[i] << " ";
		cout << endl;
	} while (next_permutation(P, P + n));
}

//enumerate {0,1,2,...,n-1} subset
//select an element every recursion
void print_subset(int n, int *A, int cur)
{
	for (int i = 0; i < cur; i++)
	{
		cout << A[i] << ' ';
	}
	cout << endl;

	int minElement = cur ? A[cur - 1] + 1 : 0;
	for (int i = minElement; i < n; i++)
	{
		A[cur] = i;
		print_subset(n, A, cur + 1);
	}
}

//use a bit vector
void print_subset2(int n, int *B, int cur)
{
	if (cur == n)
	{
		for (int i = 0; i < n; i++)
			if (B[i]) cout << i << " ";
		cout << endl;
	}
	else
	{
		B[cur] = 0;
		print_subset2(n, B, cur + 1);
		B[cur] = 1;
		print_subset(n, B, cur + 1);
	}
}

//binary constraction
void print_subset3(int n)
{
	for (int i = 0; i < (1 << n); i++)
	{
		for (int j = 0; j < n; j++)
			if (i&(1 << j)) cout << i << " ";
		cout << endl;
	}

}
