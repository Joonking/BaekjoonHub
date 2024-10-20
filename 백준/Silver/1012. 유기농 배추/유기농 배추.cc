#include <iostream>
using namespace std;


int t, m, n, k, cnt = 0;
int arr[51][51] = { 0, };
// 상하좌우 세팅
int dirX[] = { -1,1,0,0 };
int dirY[] = { 0,0,-1,1 };

void dfs(int y, int x)
{
   // 0으로 바꾸기(방문처리)
	arr[y][x] = 0;
     
    // 상하좌우 탐색
	for (int i = 0; i < 4; i++)
	{
		int _y = dirY[i] + y;
		int _x = dirX[i] + x;
        
        // 갈 수 있는 좌표라면
		if (_y >= 0 && _y < n && _x >= 0 && _x < m)
		{
            // 계산한 좌표가 배추 밭이라면
			if (arr[_y][_x] == 1)
				dfs(_y, _x);
		}
	}
	
}

int main()
{
   // 테스트 케이스 개수 입력
	cin >> t;


	int x, y;

	for (int o = 0; o < t; o++)
	{
		cnt = 0;
        // 가로, 세로, 배수를 심은 밭 개수 
		cin >> m >> n >> k;

        // 배열 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = 0;
			}
		}
        

		for (int i = 0; i < k; i++)
		{
            // 좌표 입력
			cin >> x >> y;
            // 해당 좌표 배추 밭 처리
			arr[y][x] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{  
                // 해당 좌표가 배추 밭이라면
				if (arr[i][j] == 1)
				{
                    // DFS를 통해 연결되어 있는 배추 밭을 0으로 바꿈
					dfs(i, j);
                    // 개수를 셈
					cnt++;
				}
			}
		}
        // 개수 출력
		cout << cnt << '\n';
	}
}