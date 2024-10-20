#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool IsPrime(int Num)
{
	if (Num == 2) return true;
	if (Num % 2 == 0 || Num < 2) return false;
	
	for (int i = 3; i <= sqrt(Num); i += 2)
	{
		if (Num % i == 0) return false;
	}
	return true;
}

void DFS(int Num, int MaxJarisu, int Jarisu)
{
	if (MaxJarisu == Jarisu)
	{
		cout << Num << "\n";
		return;
	}

	for (int i = 1; i <= 9; i += 2)
	{
		int NewNum = Num * 10 + i;
		if (IsPrime(NewNum))
		{
			DFS(NewNum, MaxJarisu, Jarisu+1);
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	DFS(2, N, 1);
	DFS(3, N, 1);
	DFS(5, N, 1);
	DFS(7, N, 1);

	return 0;
}