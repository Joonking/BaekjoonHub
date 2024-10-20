#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	vector<int> IntVector(N);
	for (int i = 0; i < N; i++)
	{
		cin >> IntVector[i];
	}
	int Count = 0;
	for (int i = IntVector.size() - 1; i >= 0; i--)
	{
		if (IntVector[i] <= K)
		{
			Count += K / IntVector[i];
			K = K % IntVector[i];
		}
	}
	cout << Count;

	return 0;
}