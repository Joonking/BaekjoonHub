#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	map<string, string, greater<string>> StrMap;

	for (int i = 0; i < N; i++)
	{
		string Temp1, Temp2;
		cin >> Temp1 >> Temp2;
		StrMap[Temp1] = Temp2;
	}

	for (auto a : StrMap)
	{
		if (a.second == "enter")
			cout << a.first << "\n";
	}

	return 0;
}