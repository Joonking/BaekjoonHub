#include <iostream>
#include <queue>

using namespace std;

int Bat[50][50] = { 0 };
bool Visited[50][50] = { false };
int Dy[] = {-1, 1, 0, 0};
int Dx[] = {0, 0, -1, 1};

void BFS(int Y, int X, int YSize, int XSize)
{
	queue<pair<int,int>> Queue;
	Queue.push({ Y, X });
	Visited[Y][X] = true;

	while (Queue.empty() == false)
	{
		pair<int, int> Front = Queue.front();
		Queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int TempY = Front.first + Dy[i];
			int TempX = Front.second + Dx[i];

			if (TempY < 0 || TempX <0 || TempY >= YSize || TempX >= XSize)
				continue;
			
			if (Bat[TempY][TempX] == 1 && Visited[TempY][TempX] == false)
			{
				Visited[TempY][TempX] = true;
				Queue.push({ TempY, TempX });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int M, N, K;
		cin >> M >> N >> K;

		fill(&Bat[0][0], &Bat[49][50], 0);
		fill(&Visited[0][0], &Visited[49][50], false);

		for (int p = 0; p < K; p++)
		{
			int TempX, TempY;
			cin >> TempX >> TempY;
			Bat[TempY][TempX] = 1;
		}
		int Count = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (Bat[y][x] == 1 && Visited[y][x] == false)
				{
					Count++;
					BFS(y,x, N, M);
				}
			}
		}

		cout << Count << "\n";
	}

	return 0;
}