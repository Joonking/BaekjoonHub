#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void DFS(const vector<vector<int>>& List, vector<bool>& VisitedList, int Num)
{
	if (VisitedList[Num])
		return;
	VisitedList[Num] = true;
	cout << Num << " ";
	for (int i : List[Num])
	{
		DFS(List, VisitedList, i);
	}
}

void BFS(const vector<vector<int>>& List, vector<bool>& VisitedList, int StartNum)
{
	queue<int> Queue;
	Queue.push(StartNum);
	VisitedList[StartNum] = true;

	while (Queue.empty() == false)
	{
		int front = Queue.front();
		Queue.pop();
		cout << front << " ";

		for (int i : List[front])
		{
			if (VisitedList[i] == false)
			{
				VisitedList[i] = true;
				Queue.push(i);
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, V;
	cin >> N >> M >> V;

	vector<vector<int>> NodesList(N + 1);
	vector<bool> Visited(N + 1,false);

	for (int i = 0; i < M; i++)
	{
		int TempA, TempB;
		cin >> TempA >> TempB;
		NodesList[TempA].push_back(TempB);
		NodesList[TempB].push_back(TempA);
	}

	//sort(NodesList.begin(), NodesList.end());
	for (int i=1;i<=N;i++)
	{
		sort(NodesList[i].begin(), NodesList[i].end());
	}

	DFS(NodesList, Visited, V);
	fill(Visited.begin(), Visited.end(), false);
	cout << "\n";
	BFS(NodesList, Visited, V);


	return 0;
}