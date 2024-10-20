#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> IntVector(N);

	for (int i = 0; i < N; i++)
	{
		cin >> IntVector[i];
	}
	sort(IntVector.begin(), IntVector.end());

	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int Target;
		cin >> Target;
		bool Find = false;

		int StartIndex = 0, EndIndex = IntVector.size() - 1;
		while (StartIndex <= EndIndex)
		{
			int MidIndex = (StartIndex + EndIndex) / 2;
			if (Target < IntVector[MidIndex])
			{
				EndIndex = MidIndex - 1;
			}
			else if (Target > IntVector[MidIndex])
			{
				StartIndex = MidIndex + 1;
			}
			else
			{
				Find = true;
				break;
			}
		}

		if (Find)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";

	}

	return 0;
}