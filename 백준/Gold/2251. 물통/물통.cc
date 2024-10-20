#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int Volume[3] = { 0 };

bool Ans[201] = { false };
bool Visited[201][201] = { false };

int Sender[] = { 0, 0, 1, 1, 2, 2 };   //보내는 쪽
int Receiver[] = { 1, 2, 0, 2, 0, 1 }; //받는 쪽

void BFS()
{
	queue<pair<int, int>> Queue;
	Queue.push({ 0, 0 });
	Visited[0][0] = true;
	Ans[Volume[2]] = true;

	while (Queue.empty() == false)
	{
		pair<int, int> Front = Queue.front();
		Queue.pop();

		int NowA = Front.first;
		int NowB = Front.second;
		int NowC = Volume[2] - NowA - NowB;

		for (int i = 0; i < 6; i++)
		{
			int Next[] = { NowA, NowB, NowC };
			Next[Receiver[i]] += Next[Sender[i]];
			Next[Sender[i]] = 0;

			if (Next[Receiver[i]] > Volume[Receiver[i]])
			{
				Next[Sender[i]] = Next[Receiver[i]] - Volume[Receiver[i]];
				Next[Receiver[i]] = Volume[Receiver[i]];
			}

			if (Visited[Next[0]][Next[1]] == false)
			{
				Visited[Next[0]][Next[1]] = true;
				Queue.push({ Next[0], Next[1] });
				if (Next[0] == 0)
				{
					Ans[Next[2]] = true;
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

	cin >> Volume[0] >> Volume[1] >> Volume[2];
	BFS();

	for (int i = 0; i < 201; i++)
	{
		if (Ans[i])
			cout << i << " ";
	}

	return 0;
}