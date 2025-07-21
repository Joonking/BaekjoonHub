#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	int N;
	cin >> N;

	map<string, int> UMap;

	while (N--)
	{
		string BookName;
		cin >> BookName;
		UMap[BookName]++;
	}

	int MaxCount = -1;
	set<string> Set;

	for (auto a : UMap)
	{
		if (a.second > MaxCount)
		{
			MaxCount = a.second;
			Set.clear();
			Set.insert(a.first);
		}
		else if (a.second == MaxCount)
			Set.insert(a.first);
	}

	cout << *Set.begin();

	return 0;
}