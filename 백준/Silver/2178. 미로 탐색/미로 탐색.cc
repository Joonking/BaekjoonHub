#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

static int N, M;  //N : 가로, M : 세로

static int map[100][100] = { 0 };
static bool visited[100][100] = { false };
static int dx[4] = { -1, 1, 0, 0 };    //x가 세로 y가 가로, 상하좌우
static int dy[4] = { 0, 0, -1, 1 };

void BFS(int x, int y)
{
	queue<pair<int,int>> Queue;
	Queue.push(make_pair(x, y));

	while(!Queue.empty())
	{
		pair<int, int> now = Queue.front();
		Queue.pop();
		int nowX = now.first;
		int nowY = now.second;
		visited[nowX][nowY] = true;

		for(int i = 0;i<4;i++)
		{
			int tempX = nowX + dx[i];
			int tempY = nowY + dy[i];

			if (tempX < 0 || tempX >= N || tempY < 0 || tempY >= M)
				continue;

			if(visited[tempX][tempY]==false && map[tempX][tempY] !=0)
			{
				visited[tempX][tempY] = true;
				map[tempX][tempY] = map[nowX][nowY] + 1;
				Queue.push(make_pair(tempX, tempY));
			}
		}
	}

}

int main()
{
	//cin, cout 시간단축
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string tempStr;
		cin >> tempStr;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = tempStr[j] - '0';
		}
	}

	BFS(0, 0);
	cout << map[N - 1][M - 1] << endl;
}
