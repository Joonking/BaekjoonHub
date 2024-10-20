#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> nums;
vector<vector<int>> answer;

void BFS(int start)
{
    vector<bool> visited(N, false);  // 방문한 노드 체크용 배열
    queue<int> Queue;
    Queue.push(start);
    while (!Queue.empty())
    {
        int now = Queue.front();
        Queue.pop();
        for (int i : nums[now])
        {
            if (!visited[i])
            {
                answer[start][i] = 1;
                visited[i] = true;
                Queue.push(i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    nums.resize(N);
    answer.resize(N, vector<int>(N, 0));  // 0으로 초기화된 NxN 크기의 2차원 벡터 선언

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                nums[i].push_back(k);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        BFS(i);
    }

    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
        {
            cout << answer[i][k] << " ";
        }
        cout << "\n";
    }

    return 0;
}
