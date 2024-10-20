#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	//set은 기본적으로 오름차순 정렬 
	set<string> NoHear;
	set<string> NoHearNoSee;

	//내림차순으로 하고싶다면
	//set<string, greater<string>> NoHear;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		NoHear.insert(temp);
	}

	for (int i = 0; i < M; i++)
	{
		string temp;
		cin >> temp;
		if (NoHear.find(temp) != NoHear.end())
			NoHearNoSee.insert(temp);
	}

	cout << NoHearNoSee.size() << "\n";
	for (string a : NoHearNoSee)
	{
		cout << a << "\n";
	}

	return 0;
}