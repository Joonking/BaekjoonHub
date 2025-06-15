#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<int> Degree(N + 1, 0);
	vector<vector<int>> People(N + 1);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		People[a].push_back(b);
		Degree[b]++;
	}

	queue<int> MyQueue;
	for (int i = 1; i <= N; i++)
	{
		if (Degree[i] == 0)
			MyQueue.push(i);
	}

	while (MyQueue.empty() == false)
	{
		int Front = MyQueue.front();
		MyQueue.pop();

		cout << Front << " ";

		for (int i : People[Front])
		{
			Degree[i]--;
			if (Degree[i] == 0)
				MyQueue.push(i);
		}
	}

	return 0;
}


