#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(const vector<vector<int>>& List, vector<int>& ColorList, int Num, bool* Find)
{
	queue<int> Queue;
	Queue.push(Num);
	ColorList[Num] = 1;

	while (Queue.empty() == false)
	{
		int front = Queue.front();
		Queue.pop();

		for (int i : List[front])
		{
			if (ColorList[i] == 0)
			{
				if (ColorList[front] == 1)
					ColorList[i] = 2;
				else if (ColorList[front] == 2)
					ColorList[i] = 1;

				Queue.push(i);
			}
			else 
			{
				if (ColorList[front] == ColorList[i])
				{
					*Find = true;
					return;
				}
			}

		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int V, E;
		cin >> V >> E;

		vector<vector<int>> NodesList(V + 1);
		vector<int> Color(V + 1, 0);
		for (int i = 0; i < E; i++)
		{
			int TempA, TempB;
			cin >> TempA >> TempB;
			NodesList[TempA].push_back(TempB);
			NodesList[TempB].push_back(TempA);
		}
		bool Find = false;
		for (int i = 1; i <= V; i++)
		{
			if (Find)
				break;
			if (Color[i] == 0)
			{
				BFS(NodesList, Color, i, &Find);
			}
		}
		if (Find)
			cout << "NO" << "\n";
		else
			cout << "YES" << "\n";
	}


	return 0;
}
