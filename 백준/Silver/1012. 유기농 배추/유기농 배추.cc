#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 밭
int Bat[51][51] = { 0 };
bool Visited[51][51] = { false };

// 상하좌우
int Dy[4] = { -1, 1, 0, 0 };
int Dx[4] = { 0, 0, -1, 1 };

void BFS(int y, int x, int YSize, int XSize)
{
    queue<pair<int, int>> Queue;
    Queue.push({ y, x });
    Visited[y][x] = true;

    while (Queue.empty() == false)  // while 조건 수정
    {
        pair<int, int> Front = Queue.front();
        Queue.pop();

        for (int i = 0; i < 4; i++)
        {
            int NewY = Front.first + Dy[i];
            int NewX = Front.second + Dx[i];

            if (NewY < 0 || NewX < 0 || NewY >= YSize || NewX >= XSize)
                continue;

            if (Visited[NewY][NewX] == false && Bat[NewY][NewX] == 1)  
            {
                Visited[NewY][NewX] = true;
                Queue.push({ NewY, NewX });
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

        // 배열 초기화
        fill(&Bat[0][0], &Bat[50][51], 0);  
        fill(&Visited[0][0], &Visited[50][51], false); 

        for (int j = 0; j < K; j++)
        {
            int X, Y;
            cin >> X >> Y;
            Bat[Y][X] = 1;
        }

        // 지렁이 수
        int Count = 0;

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                if (Bat[y][x] == 1 && Visited[y][x] == false)
                {
                    BFS(y, x, N, M);
                    Count++;
                }
            }
        }

        cout << Count << "\n";
    }

    return 0;
}
