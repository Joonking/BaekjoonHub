#include <bits/stdc++.h>
using namespace std;

int n;
string graph[101];
bool visited[101][101];

bool dfs(int x, int y, char color)
{
    // 주어진 범위를 벗어나는 경우에는 즉시 종료
    if (x <= -1 || x >= n || y <= -1 || y >= n)
    {
        return false;
    }
    // 현재 노드를 아직 방문하지 않았다면
    if (visited[x][y] == false && graph[x][y] == color)
    {
        visited[x][y] = true; // 우선, 방문처리
        // 상, 하, 좌, 우 위치들도 재귀적으로 호출
        dfs(x - 1, y, color);
        dfs(x + 1, y, color);
        dfs(x, y - 1, color);
        dfs(x, y + 1, color);
        return true;
    }
    return false;
}

int main()
{
    // 입력받기
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }

    // 적록색약이 아닌 경우
    int result1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dfs(i, j, graph[i][j]))
            {
                result1 += 1;
            }
        }
    }

    // 적록생약인 경우
    // visited 초기화
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    // G를 R로 바꿔준다.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == 'G')
            {
                graph[i][j] = 'R';
            }
        }
    }

    int result2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dfs(i, j, graph[i][j]))
            {
                result2++;
            }
        }
    }
    cout << result1 << ' ' << result2 << endl;

    return 0;
}