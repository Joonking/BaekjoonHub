#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	
	vector<vector<int>> NeedList(N + 1);
	vector<int> Degree(N + 1);
	vector<int> BuildTime(N + 1);
	vector<int> Ans(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> BuildTime[i];
		Ans[i] = BuildTime[i];
		while (true)
		{
			int Temp;
			cin >> Temp;
			if (Temp == -1) break;
			NeedList[Temp].push_back(i);
			Degree[i]++;
		}
	}

	queue<int> Queue;

	for (int i=1;i<=N;i++)
	{
		if (Degree[i] == 0)
			Queue.push(i);
	}

	while (Queue.empty() == false)
	{
		int Front = Queue.front();
		Queue.pop();

		for (int i : NeedList[Front])
		{
			if (Ans[i] < Ans[Front] + BuildTime[i])
			{
				Ans[i] = Ans[Front] + BuildTime[i];
			}

			Degree[i]--;
			if (Degree[i] == 0)
				Queue.push(i);
		}
	}

	for (int i= 1;i<=N;i++)
		cout << Ans[i] << "\n";


	return 0;
}