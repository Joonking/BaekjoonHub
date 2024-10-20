#include <iostream>
#include <string>
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
	vector<string> StrVector(N);

	for (int i = 0; i < N; i++)
	{
		cin >> StrVector[i];
	}

	sort(StrVector.begin(), StrVector.end(), [](const string& a, const string& b) {
		if (a.size() == b.size())
			return a < b;
		return a.size() < b.size();
		});

	string StrBackup = "";
	for (string StrTemp : StrVector)
	{
		if (StrBackup == StrTemp)
			continue;
		else
		{
			StrBackup = StrTemp;
			cout << StrTemp << "\n";
		}
	}

	return 0;
}